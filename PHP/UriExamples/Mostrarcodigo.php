<!--  
	Desenvolvido por https://github.com/Alexandro-845
	Versão 1.0 - 2020
-->
<?php
	ini_set('display_errors', 0 );
	error_reporting(0);
	
	include('verifica_login.php');
?>
<html>
	<head>
		<title>Uriexamples</title>
		<meta charset="utf-8">
		<link rel="stylesheet" href="Style/style.css">
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
		<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
		<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
	</head>
<body>
	<ul><!-- Menu Inicial -->
		<li style="float:left"><a>Bem Vindo, <?php echo $_SESSION['usuario'];?>!</a></li>
		<li style="float:right"><a href="logout.php">Sair</a></li>
		<li style="float:right"><a href="Admin.php">Voltar</a></li>	
	</ul><!-- Fim Menu Inicial -->

    <h2 align ="left">Código do Exercicio <?php  $id=$_GET['id']; echo"$id"; ?>!</h2><br>

	<!-- Recebe Um id Por Parametro e Mostra o resultado do código -->
	<table border="0">
		<tr>
			<td width="100">
			</td>
			<td>
				<?php
					$id=$_GET['id'];
					require('conexao.php');
					
					$result = mysqli_query($db, "SELECT * FROM exercicio where id=$id");
					
					$row = mysqli_fetch_assoc($result);
					$texto = $row['source'];
					echo str_replace("<br \>","<br>\\r",nl2br($texto));

					mysqli_free_result($result);
				?>
			</td>
		</tr>
	</table>
	<br><br><br>
</body>
</html>
