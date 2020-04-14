<html>
	<head>
		<title></title>
		<meta charset="utf-8">
		<style>
			#id1{	
				text-align:left;
				width:200px;
				height:200px;
				float:left;	

			}
			#id2{		
				position: absolute;
				bottom: 0;
				text-align:right;
				width:680px;
				height:156px;
				float:left;	

			}
			ul {
				list-style-type: none;
				margin: 0;
				padding: 0;
				overflow: hidden;
				background-color: #1E1E1E;
			}
			li {
			  float: left;
			}
			li a {
			  display: block;
			  color: white;
			  text-align: center;
			  padding: 15px 17px;
			  text-decoration: none;
			}
			li a:hover:not(.active) {
			  background-color: #111;
			}
			.active {
			  background-color: #4CAF50;
			}
		</style>
	</head>
<body>
	<ul>
		<li style="float:right"><a href="Cex.php">Cadastrar Novo</a></li>
		<li style="float:right"><a href="index.php">Exercicios Uri</a></li>
	</ul>
	
	<h2>Cadastro De Clientes</h2>
	
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