<!--  
	Desenvolvido por https://github.com/Alexandro-845
	Versão 1.0 - 2020
-->
<?php
	ini_set('display_errors', 0 );
	error_reporting(0);
	
	//include('verifica_login.php');
	
	$id=$_GET['id'];
	require('conexao.php');
		
	$result = mysqli_query($db, "SELECT * FROM exercicio where id=$id");
	$row = mysqli_fetch_assoc($result);
?>
<html>
	<head>
		<title>Editar Exercicio</title>
		<meta charset="utf-8">
		<link rel="stylesheet" href="Style/style.css">
		<link rel="shortcut icon" href="Images/favicon.ico" />	
		<script src="https://apis.google.com/js/platform.js" async defer></script> 
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
		<meta name="google-signin-client_id" content="384602407862-g2t95qbtuto07r923qlic2317dbrkboa.apps.googleusercontent.com">
	</head>
<body>
	<ul><!-- Menu Inicial -->
		<li style="float:left"><a href="perfil.php">Bem Vindo, <?php echo $_SESSION['userName'];?>!</a></li>
		<li style="float:right"><a href="logout.php">Sair</a></li>
		<li style="float:right"><a href="Admin.php">Voltar</a></li>	
	</ul><!-- Fim Menu Inicial -->

    <h2 align ="center">Editar Informações do Exercício <?php  $id=$_GET['id']; echo"$id"; ?>!</h2>
	<form class="form-style-8" action="editar_exercicio.php" method="GET" />
		<div style="float:center">
			<input name="class" type="hidden" value ="<?php echo $row['class']?>"<br>
			<input name="type" type="hidden" value ="<?php echo $row['type']?>"<br>
			<input name="status" type="hidden" value ="<?php echo $row['status']?>"<br>
			<h5 style="float:left">Id:</h5>
			<input type="text" class="w3-input" name="id" size="50" value="<?php echo $row['id']?>"/><br>	
			<h5 style="float:left">Nome:</h5>
			<input type="text" class="w3-input" name="name" size="50" value="<?php echo $row['name']?>"/><br>
			<h5 style="float:left">Descrição:</h5>
			<input type="text" class="w3-input" name="description" size="50" value="<?php echo $row['description']?>"/><br>
			<h5 style="float:left">Dificuldade E2PC:</h5>
			<input type="number" class="w3-input" id="quantity" name="level2pc" min="01" max="10" value="<?php echo $row['level2pc']?>"><br>
			<h5 style="float:left">Dificuldade:</h5>
			<input type="number" class="w3-input" id="quantity" name="level" min="01" max="10" value="<?php echo $row['level']?>"><br>
			<h5 style="float:left">Observação:</h5>
			<input type="text" class="w3-input" name="Observation" size="50" value="<?php echo $row['Observation']?>"/><br>
			<h5 style="float:left">Código:</h5>
			<br><textarea name="source" rows="1000" cols="70"><?php echo $row['source']?></textarea> 
			<input type="submit" style="float:center" value="Editar"/>
		</div>
	</form>
</body>
</html>