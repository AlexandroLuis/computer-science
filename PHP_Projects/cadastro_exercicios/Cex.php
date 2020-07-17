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
		<link rel="stylesheet" href="style.css">
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
		<div id="id1">
		<table border="0">
		<tr>	
			<td>
				ID: <input type="text" name="id" size="50"/><br><br>
				Nome:<input type="text" name="name" size="50"/><br><br>
			Classificação:  <select name="class">
								<option value="Iniciante">Iniciante</option>
								<option value="AD-HOC">AD-HOC</option>
								<option value="String">String</option>
								<option value="AEd">AEd</option>
								<option value="Matemática">Matemática</option>
								<option value="Paradigma">Paradigma</option>
								<option value="Grafo">Grafo</option>
								<option value="Geometria Comp.">Geometria Comp.</option>
							   </select><br><br>
			Descrição:<input type="text" name="description" size="50"/><br><br>
			Tipo:<select id="cars" name="type">
					<option value="E/S">E/S</option>
					<option value="Repetição">Repetição</option>
					<option value="Vetores e matrizes">Vetores e matrizes</option>
				 </select><br><br>
			Dificuldade E2PC: <input type="number" id="quantity" name="level2pc" min="1" max="10"><br><br>
			Dificuldade: <input type="number" id="quantity" name="level" min="1" max="10"><br><br>
			Código: <textarea type="text" name="source" rows="10" cols="52"> </textarea><br><br>
			<input type="submit" value="Enviar" />
			</td>
		</tr>
		</table>
		</div>
	</form>
</body>
</html>