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
    <title>Camagru - Profile</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="style/profile_style.css" />
    <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.1/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
    <link rel="icon" href="assets/photography-icon-png-2382.png" type="image/x-icon">
    <script async src="front/profile.js"></script>
</head>
<body>
<div id="grid-container" class="grid-container">
    <header class="header">
        <i class="fas fa-bars" onclick="Sidebar()"></i>
        <form action="#" method="POST">
            <input class="searchbar" type="text" placeholder="Search...">
        </form>
    </header>
    <aside id="sidenavbar" class="sidenavbar">
        <div class="sidenavbar_content">
            <h1><a style="text-decoration: none; color: white" href="index.php">SHARE</a></h1>
            <ul class="sidenavbar_box">
                <li class="sidenavbar_box-content"><a class="sidenavbar_links" href="#">Post a Picture</a></li>
                <button id="sidenavbar_button" class="sidenavbar_button" onclick="toggleDropdown()">Edit my Profile
                    <i class="fa fa-caret-down"></i>
                </button>
                <div id="sidenavbar_dropdown" class="sidenavbar_dropdown hidden">
                    <li class="sidenavbar_account-box-content none">
                        <label for="file_profile" class="label-file">Change my Profile Picture</label>
                        <input id="file_profile" style="display: none;" type="file" name="picture" accept="image/*" onchange="upload_profile_pic(event)">
                    </li>
                    <li class="sidenavbar_account-box-content none">
                        <label for="file_banner" class="label-file">Change my Banner Picture</label>
                        <input id="file_banner" style="display: none;" type="file" accept="image/*" onchange="upload_banner_pic(event)">
                    </li>
                    <li class="sidenavbar_account-box-content none"><a class="sidenavbar_links" href="settings.php">Settings</a></li>
                </div>
                <li class="sidenavbar_box-content"><a class="sidenavbar_links" href="back/logout.php">Sign out</a></li>
            </ul>
        </div>
    </aside>
    <main class="content">
        <div id="banner" style="background: url('users/<?= $_SESSION['username']?>/banner.jpg') no-repeat center; background-size: cover;" class="content_banner">
            <div class="content_banner-user">
                <p style="margin: 0; padding: 2px" class="banner_total_desc">Hello <?= $_SESSION['logued_user']?></p>
                <img id="profile_picture" class="profile_pic_banner" src="users/<?= $_SESSION['username']?>/profile_pic.jpg">
            </div>
            <div class="content_banner-overview">
                <div class="banner-overview_content">
                    <div class="total_content">4</div>
                    <div class="banner_total_desc">Photo Uploaded</div>
                </div>
                <div class="banner-overview_content">
                    <div class="total_content">40</div>
                    <div class="banner_total_desc">Comments Written</div>
                </div>
                <div class="banner-overview_content">
                    <div class="total_content">10</div>
                    <div class="banner_total_desc">Liked Received</div>
                </div>
            </div>
        </div>
        <div class="content_card">
            <div class="card">
                <div class="card_picture-info">
                    <div class="picture_poster">
                        <img id="profile_picture_card" class="profile_pic_card" src="users/<?= $_SESSION['username']?>/profile_pic.jpg">
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
                    <p class="comment_author">Yannis :</p>
                    <p class="description">Un site de photo rigolo</p>
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
                    <img class="card_picture" src="users/yadouble/banner.jpg">
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