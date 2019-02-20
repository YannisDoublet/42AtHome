<?php
session_start();
if (empty($_SESSION['logued_user'])) {
    session_destroy();
    header("Location: index.php?error=access_denied");
}
?>
<html>
    <head>
        <meta charset="utf-8" />
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>Camagru</title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link rel="stylesheet" type="text/css" media="screen" href="style/profile_style.css" />
        <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.1/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
        <link rel="icon" href="assets/photography-icon-png-2382.png" type="image/x-icon">
        <script async src="front/mainpage.js"></script>
    </head>
    <body>
        <div id="grid-container" class="grid-container">
            <div class="navbar">
                <div class="navbar_container">
                    <div class="title">
                        <a class="a_title" href="/"><p class="title_text">SHARE</p></a>
                    </div>
                    <div class="searchbar">
                        <h1 style="margin: 0;">HEYO</h1>
                    </div>
                </div>
            </div>
            <div class="profile">
                <h1>ALLO</h1>
            </div>
            <div class="empty_right">
            </div>
            <div class="content">
                <h1>MERE</h1>
            </div>
            <div class="empty_left">
            </div>
        </div>
    </body>
</html>