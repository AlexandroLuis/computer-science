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
<body>
	<ul>
		<li style="float:right"><a href="Cex.php">Cadastrar Novo</a></li>
		<li style="float:right"><a href="index.php">Exercicios Uri</a></li>
	</ul>
	
	<h2>Cadastrar Exercicios Uri</h2>
	
	<form action="cadastro_exercicios.php" method="POST" />
		<p align="center"><br><br>
			<div id="id1">
				ID:<br><br>
				Nome:<br><br>
				Descrição:<br><br>
				Classificação:<br><br>
				Dificuldade:<br><br><br>	
				Código:<br><br>	
			</div>
			
			<div id="id1">
				<input type="text" name="id" size="50"/> <br><br>
				<input type="text" name="name" size="50"/> <br><br>
				<input type="text" name="description" size="50"/> <br><br>
				<input type="text" name="class" size="50"/> <br><br>
				<input type="text" name="level" size="50"/> <br><br>
				<textarea type="text" name="source" rows="10" cols="52"> </textarea>
			</div>
			
			<div id="id2">
				<input type="submit" value="Enviar" />
			</div>
		</p>		
	</form>
</body>
</html>