<?php
session_start();

// Execute the right function

if (empty($_SESSION['logued_user'])) {
    session_destroy();
    exit;
}
if (!empty($_POST['b64']) && !empty($_POST['stickers']) && !empty($_POST['title'])) {
    submit_photo($_POST['b64'], preg_replace(';http://localhost:8080;', '..', $_POST['stickers']),
        trim($_POST['title']), intval($_POST['top']), intval($_POST['left']));
} else {

}

// Save image to database with her credentials.

function    save_image_in_db($title, $username, $img_id) {
    include $_SERVER['DOCUMENT_ROOT'].'/config/database.php';
    date_default_timezone_set('France/Paris');
    try {
        $DB = new PDO($DB_DSN.";dbname=".$DB_NAME, $DB_USER, $DB_PASSWORD);
        $stmt = $DB->prepare("INSERT INTO img_info (img_id, title, `user`, `firstname`, `comments`, `likes`, creation_time)
                      VALUES (?, ?, ?, ?, ?, ?, ?);");
        $stmt->execute([$img_id, $title, $username, $_SESSION['logued_user'], 0, 0, date('Y-m-d H:i:s')]);
    } catch (PDOException $e) {
        echo $e;
    }
}

// Create image from a picture and a stickers.

function submit_photo($b64, $stickers, $title, $top, $left)
{
    $img_id = uniqid();
    $file = "../pictures/$img_id.jpg";
    $stickers_size = getimagesize($stickers);
    $data = str_replace('data:image/png;base64', '', $b64);
    $data = str_replace(' ', '+', $data);
    $data = base64_decode($data);
    $source_img = imagecreatefromstring($data);
    $stickers_img = imagecreatefrompng($stickers);
    imagecopy($source_img, $stickers_img,$left,$top,0,0, $stickers_size[0], $stickers_size[1]);
    imagejpeg($source_img, $file, 75);
    save_image_in_db($title, $_SESSION['username'], $img_id);
    echo "OK";
    http_response_code(200);
}