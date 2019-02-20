<?php
	$DB_DSN = 'mysql:host=127.0.0.1:3306';
	$DB_USER = 'root';
	$DB_PASSWORD = 'root';
	$DB_NAME = 'Camagru';
	$DB_USER_INFO = 'user_info';
	$DB_USER_INFO_CONTENT = "CREATE TABLE IF NOT EXISTS $DB_USER_INFO (
			`id` INT NOT NULL AUTO_INCREMENT PRIMARY KEY ,
			`firstname` VARCHAR( 255 ) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
			`lastname` VARCHAR( 255 ) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
			`email` VARCHAR( 255 ) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
			`phonenumber` VARCHAR( 12 ) ,
			`username` VARCHAR( 255 ) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
			`password` VARCHAR( 255 ) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
			`photo_uploaded` INT ,
			`comment_uploaded` INT ,
			`followers` INT ,
			`acc_id` VARCHAR( 255 ) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
			`validate` INT ,
			`creation_time` DATETIME NOT NULL
			);";