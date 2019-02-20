<?php

if (!empty($_POST['user']) && !empty($_POST['psw'])) {
    $user = $_POST['user'];
    $psw = $_POST['psw'];
    sign_in($user, $psw);
} else if (!empty($_POST['firstname']) && !empty($_POST['lastname']) && !empty($_POST['email']) && !empty($_POST['phone'])
        && !empty($_POST['username']) && !empty($_POST['psw']) && !empty($_POST['check-psw'])) {
        sign_up();
} else if (!empty($_GET['confirm_code'])) {
    confirm($_GET['confirm_code']);
}

function    confirm($code) {
    include $_SERVER['DOCUMENT_ROOT'].'/config/database.php';
    try {
        $DB = new PDO($DB_DSN . ";dbname=" . $DB_NAME, $DB_USER, $DB_PASSWORD);
        $stmt = $DB->prepare("SELECT * FROM user_info WHERE acc_id=?");
        $stmt->execute([$code]);
        $user = $stmt->fetch();
        if (!empty($user)) {
            try {
                $stmt = $DB->prepare("UPDATE user_info SET validate=? WHERE acc_id=?");
                $stmt->execute([1, $code]);
                header("Location: ../sign_up.php?account=validation_success");
            }
            catch (PDOException $e) {
                header("Location: ../sign_up.php?error=database_error");
            }
        }
    }
    catch (PDOException $e) {
        header("Location: ../sign_up.php?error=database_error");
    }
}

function    resubmit_info($error, $dodge) {
    $resub = array();
    foreach ($_POST as $key => $value) {
        if ($key === $dodge || $key === "psw" || $key === "check-psw") {
            ;
        }
        else {
            $resub[$key] = $value;
        }
    }?>
    <html>
        <form style="display: none;" id="resub" action="../sign_up.php?error=<?= $error; ?>" method="POST">
            <?php foreach ($resub as $key => $value){?>
                <input type="hidden" name="<?= $key?>" value="<?= $value?>">
            <?php }?>
        </form>
        <script>
            document.getElementById('resub').submit();
        </script>
       </html><?php
}
function    sign_in($user, $psw) {
    include $_SERVER['DOCUMENT_ROOT'].'/config/database.php';
    try {
        $DB = new PDO($DB_DSN.";dbname=".$DB_NAME, $DB_USER, $DB_PASSWORD);
        $stmt = $DB->prepare("SELECT username, email, `password`, validate, firstname
                FROM user_info WHERE username=? OR email=?");
        $stmt->execute([$user, $user]);
        $log = $stmt->fetch();
        if (!empty($log)) {
            if (intval($log['validate']) === 1) {
                if (password_verify($psw, $log['password'])) {
                    session_start();
                    $_SESSION['logued_user'] = $log['firstname'];
                    header("Location: ../index.php?sign_in=success");
                }
                else {
                    resubmit_info("invalid_password", "psw");
                    exit;
                }
            }
            else {
                header("Location: ../sign_up.php?error=unvalidated_account");
            }
        }
        else {
            header("Location: ../sign_up.php?error=invalid_info");
        }
    }
    catch (PDOException $e) {
        header("Location: ../sign_up.php?error=database_error");
    }
}

function    sign_up() {
    include $_SERVER['DOCUMENT_ROOT'].'/config/database.php';
    date_default_timezone_set("Europe/Paris");
    if (!preg_match("/^[a-zA-Z]+$/", $_POST['firstname'])) {
        resubmit_info("invalid_firstname", "firstname");
        exit;
    }
    if (!preg_match("/^[a-zA-Z]+$/", $_POST['lastname'])) {
        resubmit_info("invalid_lastname", "lastname");
        exit;
    }
    if (!preg_match("/^[a-zA-Z0-9.!#$%&'*+\=?^_`{|}~-]+@[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?(?:\.[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?)+$/", $_POST['email'])) {
        resubmit_info("invalid_email", "email");
        exit;
    }
    if (!preg_match("/^(?:(?:\+|00)33|0)*[1-9](?:\d{2}){4}$/", $_POST['phone'])) {
        resubmit_info("invalid_phonenumber", "phone");
        exit;
    }
    if (!preg_match("/^[a-zA-Z0-9]{5,10}$/", $_POST['username'])) {
        resubmit_info("invalid_username", "username");
        exit;
    }
    if (!preg_match("/^.{8,40}$/", $_POST['psw']) || !preg_match("/^.{8,40}$/", $_POST['check-psw']) || $_POST['psw'] !== $_POST['check-psw']) {
        resubmit_info("invalid_password", "");
        exit;
    }
    try {
        $DB = new PDO($DB_DSN.";dbname=".$DB_NAME, $DB_USER, $DB_PASSWORD);
        $stmt = $DB->prepare("SELECT username, email, phonenumber FROM user_info WHERE username=? OR email=? OR phonenumber=?");
        $stmt->execute([$_POST['username'], $_POST['email'], $_POST['phone']]);
        $user = $stmt->fetch();
        if (empty($user)) {
            $psw = password_hash($_POST['psw'], PASSWORD_BCRYPT);
            $acc_id = uniqid();
            try {
                $stmt = $DB->prepare("INSERT INTO user_info (firstname, lastname, email, phonenumber,
                    username, `password`, photo_uploaded, comment_uploaded, followers, acc_id, validate, creation_time)
                    VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
                $stmt->execute([$_POST['firstname'], $_POST['lastname'], $_POST['email'], $_POST['phone'],
                    $_POST['username'], $psw, 0, 0, 0, $acc_id, 0, date('Y-m-d H:i:s')]);
                $from = "no-reply@camagru.com";
                mail($_POST['email'], "Confirm your account",
                    "Welcome to Camagru please confirm your account by clicking this link http://localhost:8080/sign_up.php?confirm_code=".$acc_id, "From: ".$from);
                header("Location: ../email_confirmation.php");
            }
            catch (PDOException $e) {
                header("Location: ../sign_up.php?error=database_error");
            }
        }
        else {
            if ($user['username'] === $_POST['username']) {
                resubmit_info("username_already_taken", "username");
                exit;
            }
            else if ($user['email'] === $_POST['email']) {
                resubmit_info("email_already_taken", "email");
                exit;
            }
            else if ($user['phonenumber'] === $_POST['phone']) {
                resubmit_info("phonenumber_already_taken", "phone");
                exit;
            }
        }
    }
    catch (PDOException $e) {
       header("Location: ../sign_up.php?error=database_error");
    }
}