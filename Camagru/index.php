<?php
session_start();
if (!file_exists("users")) {
    mkdir("users", 0700);
}
if (file_exists("assets/stickers")) {
    $files = array_diff(scandir('assets/stickers'), array('.', '..'));
}
$i = 0;
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8" />
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<title>Camagru</title>
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" type="text/css" media="screen" href="style/mainpage_style.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="style/post_style.css" />
    <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.1/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
    <link rel="icon" href="assets/photography-icon-png-2382.png" type="image/x-icon">
    <script async src="front/mainpage.js"></script>
    <script async src="front/post.js"></script>
</head>
<body>
<div id="post_picture" class="post_picture hidden">
    <div class="post_container">
        <div class="post_card">
            <div id="post_card_content">
                <div class="post_card_header">
                    <i class="fas fa-arrow-left" onclick="togglePost()"></i>
                    <p class="post_card_header_title">Post a picture</p>
                </div>
                <div class="post_card_picture">
                    <div id="webcam" class="webcam_option" onclick="toggleWebcam()">
                        <img id="selected" style=" position: absolute; top: 0px; left: 0px" src="">
                        <i id="move_left" class="fas fa-arrow-left move_sticker none" onmousedown="mousedownfunc(event)" onmouseup="mouseupfunc(event)" onmouseleave="mouseupfunc(event)"></i>
                        <i id="move_up" class="fas fa-arrow-up move_sticker none" onmousedown="mousedownfunc(event)" onmouseup="mouseupfunc(event)" onmouseleave="mouseupfunc(event)"></i>
                        <i id="move_right" class="fas fa-arrow-right move_sticker none" onmousedown="mousedownfunc(event)" onmouseup="mouseupfunc(event)" onmouseleave="mouseupfunc(event)"></i>
                        <i id="move_down" class="fas fa-arrow-down move_sticker none" onmousedown="mousedownfunc(event)" onmouseup="mouseupfunc(event)" onmouseleave="mouseupfunc(event)"></i>
                        <video id="video" class="" autoplay></video>
                        <img id="picture" src="" class="none">
                        <canvas id="canvas" style="display: none;"></canvas>
                    </div>
                    <div id="img" class="upload_option" onclick="upload_img()">
                    </div>
                </div>
                <div id="utils" class="post_card_utils none">
                    <i id="prev" class="fas fa-arrow-left none" onclick="toggleUtils()"></i>
                    <button disabled id="take_photo" class="" onclick="photo()">Take a photo</button>
                    <input id="title" class="none" type="text" placeholder="Name your picture !" required>
                    <button id="post" class="none" onclick="submit()">Post</button>
                </div>
                <div id="stickers_bar" class="post_card_bar none">
                    <p class="post_card_bar_header" onclick="toggleStickers()">Stickers</p>
                    <div id="stickers">
                        <div id="stickers_container">
                            <?php foreach($files as $value) {
                                ?><img id="<?= $i?>" class="stickers_img" src="assets/stickers/<?= $value?>" onclick="toggleActive(event)">
                            <?php $i++; }?>
                        </div>
                    </div>
                </div>
                <div id="old_pic" class="post_card_bar none">
                    <p class="post_card_bar_header" onclick="toggleOld()">Previous picture</p>
                    <div id="old"></div>
                </div>
            </div>
        </div>
    </div>
</div>
<div id="grid-container" class="grid-container">
    <header class="header">
        <i class="fas fa-bars" onclick="Sidebar()"></i>
        <form action="#" method="POST">
            <input class="searchbar" type="text" placeholder="Search...">
        </form>
    </header>
    <aside id="sidenavbar" class="sidenavbar">
        <div class="sidenavbar_content">
            <h1>SHARE</h1>
            <ul class="sidenavbar_box">
                <li class="sidenavbar_box-content"><a class="sidenavbar_links" <?php if (!empty($_SESSION['logued_user'])) { echo 'onclick="togglePost();"'; } else { echo 'href="sign_up.php?error=You must be logged in!"'; }?>>Post a Picture</a></li>
                <button id="sidenavbar_button" class="sidenavbar_button">Account
                    <i class="fa fa-caret-down"></i>
                </button>
                <div class="sidenavbar_account_content">
                    <?php if (empty($_SESSION['logued_user'])){?>
                        <li class="sidenavbar_account-box-content none"><a class="sidenavbar_links" href="sign_up.php" >Sign Up</a></li>
                    <?php }else{?>
                        <li class="sidenavbar_account-box-content none"><a class="sidenavbar_links" href="profile.php">My Profile</a></li>
                        <li class="sidenavbar_account-box-content none"><a class="sidenavbar_links" href="back/logout.php">Sign Out</a></li>
                    <?php }?>
                </div>
            </ul>
        </div>
    </aside>
    <main class="content">
        <div style="background: url('<?php if (!empty($_SESSION['username'])) {
            ?>users/<?= $_SESSION['username']?>/banner.jpg<?php }
            else { echo "assets/mountains.png"; }?>') no-repeat center; background-size: cover;" class="content_banner">
            <?php if (!empty($_SESSION['logued_user'])) {?>
                <div class="content_banner-user"><p style="margin: 0; padding: 2px" class="banner_total_desc">Hello <?= $_SESSION['logued_user'];?>, how are you today ?</p></div>
            <?php } else {?>
                <div class="content_banner-user"><p style="margin: 0; padding: 2px" class="banner_total_desc">Welcome to Share ! The new social network based on photography !</p></div>
            <?php }?>
            <div class="content_banner-overview">
                <div class="banner-overview_content">
                    <div class="total_content">4</div>
                    <div class="banner_total_desc">Photos Uploaded on Share</div>
                </div>
                <div class="banner-overview_content">
                    <div class="total_content">40</div>
                    <div class="banner_total_desc">Comments Written on Share</div>
                </div>
                <div class="banner-overview_content">
                    <div class="total_content">10</div>
                    <div class="banner_total_desc">Users Registered on Share</div>
                </div>
            </div>
        </div>
        <div class="content_card">
            <div class="card">
                <div class="card_picture-info">
                    <div class="picture_poster">
                        <img class="profile_pic_card" src="assets/profile_pic.jpg">
                        <p>First picture by Yannis</p>
                    </div>
                    <div class="picture_date">
                        <i class="far fa-calendar-alt"></i>
                        <p class="date">26/06/2018</p>
                    </div>
                </div>
                <div class="card_picture">
                    <img src="https://sd-cdn.fr/wp-content/uploads/2018/02/instagram-770x515.jpg">
                </div>
                <div class="card_picture_description">
                    <div class="picture_description">
                        <p class="comment_author">Yannis :</p>
                        <p class="description">Un site de photo rigolo</p>
                    </div>
                </div>
                <div class="card_picture-rating">
                    <div class="picture_likes">
                        <p id="likes">21</p>
                        <i id="heart" class="far fa-heart" onclick="Likes()"></i>
                    </div>
                    <p class="comment_number">10 comments</p>
                </div>
                <div class="card_picture-comments">
                    <div class="comment">
                        <div class="comment_content">
                            <p class="comment_author">William</p>
                            <p id="comment_text" class="comment_text">Lol kopieur</p>
                        </div>
                        <div class="comments_management">
                            <i id="edit" class="far fa-edit" onclick="Edit()"></i>
                            <form action="#">
                                <button id="erase" class="fas fa-times"></button>
                            </form>
                        </div>
                    </div>
                    <div class="comment">
                        <div class="comment_content">
                            <p class="comment_author">Thibaut</p>
                            <p id="comment_text" class="comment_text">C toi lkkopieur bollos gro naz mdr</p>
                        </div>
                        <div class="comments_management">
                            <i id="edit" class="far fa-edit" onclick="Edit()"></i>
                            <form action="#">
                                <button id="erase" class="fas fa-times"></button>
                            </form>
                        </div>
                    </div>
                    <div class="comment">
                        <div class="comment_content">
                            <p class="comment_author">Florent</p>
                            <p id="comment_text" class="comment_text">Wow bravo</p>
                        </div>
                        <div class="comments_management">
                            <i id="edit" class="far fa-edit" onclick="Edit()"></i>
                            <form action="#">
                                <button id="erase" class="fas fa-times"></button>
                            </form>
                        </div>
                    </div>
                </div>
                <form class="card_picture-add_comments" action="#" method="POST">
                    <input id="comment_bar" class="comment_bar" type="text" placeholder="Comment...">
                </form>
            </div>
            <div class="card">
                <div class="card_picture-info">
                    <p>Posted by Yannis</p>
                    <p>26/06/2018</p>
                </div>
                <div>
                    <img class="card_picture" src="https://www.toriaezu-japan.com/wp-content/uploads/2018/10/dog-3724261-740x532.jpg">
                </div>
                <div class="card_picture-rating">
                    <p>22 likes</p>
                    <p>10 comments</p>
                </div>
                <div class="card_picture-comments">
                </div>
                <div class="card_picture-add_comments"></div>
            </div>
            <div class="card">
                <div class="card_picture-info">
                    <p>Posted by Yannis</p>
                    <p>26/06/2018</p>
                </div>
                <div>
                    <img class="card_picture" src="assets/mountains.png">
                </div>
                <div class="card_picture-rating">
                    <p>23 likes</p>
                    <p>10 comments</p>
                </div>
                <div class="card_picture-comments"></div>
                <div class="card_picture-add_comments"></div>
            </div>
            <div class="card">
                <div class="card_picture-info">
                    <p>Posted by Yannis</p>
                    <p>26/06/2018</p>
                </div>
                <div>
                    <img class="card_picture" src="assets/mountains.png">
                </div>
                <div class="card_picture-rating">
                    <p>24 likes</p>
                    <p>10 comments</p>
                </div>
                <div class="card_picture-comments"></div>
                <div class="card_picture-add_comments"></div>
            </div>
        </div>
    </main>
    <footer class="footer">
        <div class="copyright">&copy; 2019 Yannis Doublet</div>
        <div class="signature">Camagru, a 42 Project</div>
    </footer>
</div>
</body>
</html>