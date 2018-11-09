<?php
include 'database.php';
try {
	$NEW = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	echo "Connexion à MySQL réussi.";
	$req = "CREATE DATABASE IF NOT EXISTS $DB_NAME DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci";
	$NEW->prepare($req)->execute();
	echo "<br>Base de donnée ".$DB_NAME." créé !";
}
catch (PDOException $e) {
	echo "La base de donnée n'à pas pu être reliée.";
}
try {
	$DB = new PDO($DB_DSN.";dbname=".$DB_NAME, $DB_USER, $DB_PASSWORD);
	echo "<br>Connexion à la base de donnée ".$DB_NAME." réussi !";
	$req = "CREATE TABLE IF NOT EXISTS $DB_TABLE_LOG (
			`id` INT NOT NULL AUTO_INCREMENT PRIMARY KEY ,
			`Firstname` VARCHAR( 255 ) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
			`Lastname` VARCHAR( 255 ) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
			`Email` VARCHAR( 255 ) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
			`Username` VARCHAR( 255 ) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
			`Password` VARCHAR( 255 ) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL ,
			`Creation_time` DATETIME NOT NULL
			);";
	$DB->prepare($req)->execute();
	echo "<br>Table ".$DB_TABLE_LOG." créé !";
}
catch (PDOException $e) {
	echo "<br>La base de donnée n'à pas pu se connecter à Camagru.";
}
?>