<!--  
	Desenvolvido por https://github.com/Alexandro-845
	Versão 1.0 - 2020
-->
<?php
	include('verifica_login.php');
?>
<html>
	<head>
		<title></title>
		<meta charset="utf-8">
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
		<link rel="stylesheet" href="Style/style.css">
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
<body align="center">
	<ul>
		<li style="float:left"><a>Bem Vindo, <?php echo $_SESSION['usuario'];?>!</a></li>
		<li style="float:right"><a href="Cex.php">Recarregar</a></li>
		<li style="float:right"><a href="Admin.php">Página Inicial</a></li>
	</ul>
	
	<h2>Cadastrar Exercicios Uri</h2>
	
	<form class="form-style-8" action="cadastro_exercicios.php" method="POST" />
		<div style="float:center">
			<input type="text" class="w3-input" name="id" size="50" placeholder="ID:"/><br><br>	
			<input type="text" class="w3-input" name="name" size="50" placeholder="Nome:"/><br><br>
			<input type="text" class="w3-input" name="description" size="50" placeholder="Descrição:"/><br><br>
			<h5 style="float:left">Selecione o Tipo:</h5><br><br>
			<input type="checkbox" style="float:left" value="Entrada & Saida.">Entrada & Saida.</option><br>
			<input type="checkbox" style="float:left" value="Laço de Repetição.">Laço de Repetição.</option><br>
			<input type="checkbox" style="float:left" value="Vetores e matrizes.">Vetores e matrizes.</option><br><br>
			<select name="class">
				<option value="">Selecione a Classificação:</option>
				<option value="Nível Iniciante.">Nível Iniciante.</option>
				<option value="D-HOC Program.">AD-HOC Program.</option>
				<option value="Trat de String.">Trat de String.</option>
				<option value="Alg & data struct.">Alg & data struct.</option>
				<option value="Matemática Comp.">Matemática Comp.</option>
				<option value="Paradigma Comp.">Paradigma Comp.</option>
				<option value="Grafo Comp.">Grafo Comp.</option>
				<option value="Geometria Comp.">Geometria Comp.</option>
			</select><br><br>
			<h5 style="float:left">Dificuldade E2PC:</h5>
			<input type="number" class="w3-input" id="quantity" name="level2pc" min="01" max="10">
			<h5 style="float:left">Dificuldade:</h5>
			<input type="number" class="w3-input" id="quantity" name="level" min="01" max="10"><br><br>
			<input type="text" class="w3-input" name="Observation" size="50" placeholder="Observação:"/> <br><br>
			<h5 style="float:left">Código:</h5>
			<br><textarea type="text" name="source" rows="10" cols="52" "></textarea> 
			<input type="submit" value="Enviar" />
		</div>
	</form>
</body>
</html>