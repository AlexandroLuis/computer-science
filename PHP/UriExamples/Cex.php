<!--  
	Desenvolvido por https://github.com/Alexandro-845
	Versão 1.0 - 2020
-->
<?php
	ini_set('display_errors', 0 );
	error_reporting(0);
	
	//include('verifica_login.php');
?>
<html>
	<head>
		<title>Cadastrar Exercicios</title>
		<meta charset="utf-8">
		<link rel="shortcut icon" href="Images/favicon.ico" />
		<script src="https://apis.google.com/js/platform.js" async defer></script> 
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
		<meta name="google-signin-client_id" content="384602407862-g2t95qbtuto07r923qlic2317dbrkboa.apps.googleusercontent.com">
		<link rel="stylesheet" href="Style/style.css">
	</head>
<body align="center">
	<ul>
		<li style="float:left"><a href="perfil.php">Bem Vindo, <?php echo $_SESSION['userName'];?>!</a></li>
		<li style="float:right"><a href="Cex.php">Recarregar</a></li>
		<li style="float:right"><a href="Admin.php">Página Inicial</a></li>
	</ul>
	
	<h2>Cadastrar Exercicios Uri</h2>
	
	<form class="form-style-8" action="cadastro_exercicios.php" method="POST" />
		<div style="float:center">
			<input type="text" class="w3-input" name="id" size="50" placeholder="ID:"/><br>
			<input type="text" class="w3-input" name="name" size="50" placeholder="Nome:"/><br>
			<input type="text" class="w3-input" name="description" size="50" placeholder="Descrição:"/><br>
			<input type="text" class="w3-input" name="Observation" size="50" placeholder="Observação:"/> <br>
			<input type="text" class="w3-input" name="type" size="50" placeholder="Tipo(s):"/> <br><br>
			<div class="id1">
				<h5 style="float:left">Selecione a Classificação:</h5><br><br><br>
				<h5 style="float:left">Dificuldade E2PC:</h5><br><br><br>
				<h5 style="float:left">Dificuldade:</h5>			
			</div>
			<div class="id2">
				<select name="class">
					<option value="Nível Iniciante.">Nível Iniciante.</option>
					<option value="D-HOC Program.">AD-HOC Program.</option>
					<option value="Trat de String.">Trat de String.</option>
					<option value="Alg & data struct.">Alg & data struct.</option>
					<option value="Matemática Comp.">Matemática Comp.</option>
					<option value="Paradigma Comp.">Paradigma Comp.</option>
					<option value="Grafo Comp.">Grafo Comp.</option>
					<option value="Geometria Comp.">Geometria Comp.</option>
				</select>
				<input type="number" class="w3-input" id="quantity" name="level2pc" min="01" max="10" placeholder="01">
				<input type="number" class="w3-input" id="quantity" name="level" min="01" max="10" placeholder="01">				
			</div>
			<h5 style="float:left">Código:</h5>
			<br><textarea type="text" name="source" rows="10" cols="52" ></textarea> 
			<input type="submit" value="Enviar" />
		</div>
	</form>
</body>
</html>