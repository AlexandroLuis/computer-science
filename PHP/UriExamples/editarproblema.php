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
		<title>Editar Exercicio</title>
		<meta charset="utf-8">
		<link rel="stylesheet" href="Style/style.css">
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
		<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
		<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
		<style type="text/css">
			.form-style-8{
				font-family: 'Open Sans Condensed', arial, sans;
				width: 500px;
				padding: 30px;
				background: #FFFFFF;
				margin: 50px auto;
				box-shadow: 0px 0px 15px rgba(0, 0, 0, 0.22);
				-moz-box-shadow: 0px 0px 15px rgba(0, 0, 0, 0.22);
				-webkit-box-shadow:  0px 0px 15px rgba(0, 0, 0, 0.22);
			}
			.form-style-8 h2{
				background: #4D4D4D;
				text-transform: uppercase;
				font-family: 'Open Sans Condensed', sans-serif;
				color: #797979;
				font-size: 18px;
				font-weight: 100;
				padding: 20px;
				margin: -30px -30px 30px -30px;
			}
			.form-style-8 input[type="text"],
			.form-style-8 input[type="date"],
			.form-style-8 input[type="datetime"],
			.form-style-8 input[type="email"],
			.form-style-8 input[type="number"],
			.form-style-8 input[type="search"],
			.form-style-8 input[type="time"],
			.form-style-8 input[type="url"],
			.form-style-8 input[type="password"],
			.form-style-8 textarea,
			.form-style-8 select{
				box-sizing: border-box;
				-webkit-box-sizing: border-box;
				-moz-box-sizing: border-box;
				outline: none;
				display: block;
				width: 100%;
				padding: 7px;
				border: none;
				border-bottom: 1px solid #ddd;
				background: transparent;
				margin-bottom: 10px;
				font: 16px Arial, Helvetica, sans-serif;
				height: 45px;
			}
			.form-style-8 textarea{
				resize:500;
				height: 150px;
			}
			.form-style-8 input[type="button"], 
			.form-style-8 input[type="submit"]{
				-moz-box-shadow: inset 0px 1px 0px 0px #45D6D6;
				-webkit-box-shadow: inset 0px 1px 0px 0px #45D6D6;
				box-shadow: inset 0px 1px 0px 0px #45D6D6;
				background-color: #2CBBBB;
				border: 1px solid #27A0A0;
				display: inline-block;
				cursor: pointer;
				color: #FFFFFF;
				font-family: 'Open Sans Condensed', sans-serif;
				font-size: 14px;
				padding: 8px 18px;
				text-decoration: none;
				text-transform: uppercase;
			}
			.form-style-8 input[type="button"]:hover, 
			.form-style-8 input[type="submit"]:hover {
				background:linear-gradient(to bottom, #34CACA 5%, #30C9C9 100%);
				background-color:#34CACA;
			}
		</style>
		<script type="text/javascript">
			//auto expand textarea
			function adjust_textarea(h) {
				h.style.height = "20px";
				h.style.height = (h.scrollHeight)+"px";
			}
		</script>
	</head>
<body>
	<ul><!-- Menu Inicial -->
		<li style="float:left"><a>Bem Vindo, <?php echo $_SESSION['usuario'];?>!</a></li>
		<li style="float:right"><a href="logout.php">Sair</a></li>
		<li style="float:right"><a href="Admin.php">Voltar</a></li>	
	</ul><!-- Fim Menu Inicial -->

    <h2 align ="center">Editar Informações do Exercício <?php  $id=$_GET['id']; echo"$id"; ?>!</h2>

	<!-- Recebe Um id Por Parametro e Mostra o resultado do código -->
	<?php
		$id=$_GET['id'];
		require('conexao.php');
		
		$result = mysqli_query($db, "SELECT * FROM exercicio where id=$id");
		$row = mysqli_fetch_assoc($result);
	?>
	
	<form class="form-style-8" action="editar_exercicio.php" method="POST" />
		<div style="float:center">
			<h5 style="float:left">Id:</h5>
			<input type="text" class="w3-input" name="id" size="50" value="<?php echo $row['id']?>"/><br><br>	
			<h5 style="float:left">Nome:</h5>
			<input type="text" class="w3-input" name="name" size="50" value="<?php echo $row['name']?>"/><br><br>
			<h5 style="float:left">Descrição:</h5>
			<input type="text" class="w3-input" name="description" size="50" value="<?php echo $row['description']?>"/><br><br>
			<h5 style="float:left">Dificuldade E2PC:</h5>
			<input type="number" class="w3-input" id="quantity" name="level2pc" min="01" max="10" value="<?php echo $row['level2pc']?>"><br>
			<h5 style="float:left">Dificuldade:</h5>
			<input type="number" class="w3-input" id="quantity" name="level" min="01" max="10" value="<?php echo $row['level']?>"><br><br>
			<h5 style="float:left">Observação:</h5>
			<input type="text" class="w3-input" name="Observation" size="50" value="<?php echo $row['Observation']?>"/> <br><br>
			<h5 style="float:left">Código:</h5>
			<br><textarea type="text" name="source" rows="10" cols="52" value="<?php echo $row['source']?>"></textarea> 
			<input type="submit" style="float:center" value="Editar"/>
		</div>
	</form>
</body>
</html>