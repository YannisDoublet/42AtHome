<?php
session_start();
function    sign_up() {
    echo $_POST['user'];
    echo $_POST['psw'];
}
//header("Location: ../email_confirmation.php");