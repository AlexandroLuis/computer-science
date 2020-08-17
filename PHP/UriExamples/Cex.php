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
	</head>
<body align="center">
	<ul>
		<li style="float:left"><a>Bem Vindo, <?php echo $_SESSION['usuario'];?>!</a></li>
		<li style="float:right"><a href="Cex.php">Recarregar</a></li>
		<li style="float:right"><a href="Admin.php">Página Inicial</a></li>
	</ul>
	
	<h2>Cadastrar Exercicios Uri</h2>
	
	<form action="cadastro_exercicios.php" method="POST" />
		<div style="float:center">
			<h5>ID:
				<input type="text" name="id" size="50" placeholder="0000"/><br><br></h5> 	
			<h5>Nome: 
				<input type="text" name="name" size="50" placeholder="Máximo 15 caracteres"/><br><br></h5> 
			<h5>Descrição: 
				<input type="text" name="description" size="50"/><br><br></h5> 
			<h5>Tipo: 
				<select id="cars" name="type" ><!--multiple -->
					<option value="Entrada & Saida.">Entrada & Saida.</option>
					<option value="Laço de Repetição.">Laço de Repetição.</option>
					<option value="Vetores e matrizes.">Vetores e matrizes.</option>
				</select>
			Classificação:
				<select name="class">
					<option value="Nível Iniciante.">Nível Iniciante.</option>
					<option value="D-HOC Program.">AD-HOC Program.</option>
					<option value="Trat de String.">Trat de String.</option>
					<option value="Alg & data struct.">Alg & data struct.</option>
					<option value="Matemática Comp.">Matemática Comp.</option>
					<option value="Paradigma Comp.">Paradigma Comp.</option>
					<option value="Grafo Comp.">Grafo Comp.</option>
					<option value="Geometria Comp.">Geometria Comp.</option>
			</select><br><br></h5>
			<h5>Dificuldade E2PC: 
				<input type="number" id="quantity" name="level2pc" min="01" max="10">
			Dificuldade:
				<input type="number" id="quantity" name="level" min="01" max="10"><br><br></h5>  
			<h5>Observação:
				<input type="text" name="Observation" size="50"/><br><br></h5> 
			<h5>Código:
				<br><textarea type="text" name="source" rows="10" cols="52" placeholder="Digite A resolução do Exercício."> </textarea><br><br></h5> 
			<input type="submit" value="Enviar" />
		</div>
	</form>
</body>
</html>