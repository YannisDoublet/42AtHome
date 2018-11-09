<html>
	<head>
		<title>Connexion</title>
		<style>
			*{
				border: 2px solid red;
			}
			.login {
				width: 100vw;
				height: 100vh;
				display: flex;
				justify-content: center;
				align-items: center;
			}
			#connexion {
			}
			.mid {
				width: 130px;
				text-align: center;
			}
		</style>
	</head>
	<body>

		<form method="POST" class="login" action="../back/login.back.php" autocomplete="on">
			<div class="mid">
				<p>Connecte toi !</p>
				<input type="text" placeholder="Enter your Username !" required>
				<input type="password" placeholder="Enter your Password !" required>
				<button id="connexion" type="button">Connexion</button>
				<button type="button">Créer un compte</button>
			</div>
		</form>
	</body>
</html>