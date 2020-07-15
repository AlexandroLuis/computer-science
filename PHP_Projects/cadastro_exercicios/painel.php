<?php
	include('verifica_login.php');
?>
<html>
	<head>
		<title></title>
		<meta charset="utf-8">
		<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
		<link rel="stylesheet" href="style.css">
		<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
		<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
		<style>
			.dropbtn:hover, .dropbtn:focus {
			  background-color: #2980B9;
			}

			.dropdown {
			  position: relative;
			  display: inline-block;
			}

			.dropdown-content {
			  display: none;
			  position: absolute;
			  background-color: #f1f1f1;
			  min-width: 160px;
			  overflow: auto;
			  box-shadow: 0px 8px 16px 0px rgba(0,0,0,0.2);
			  z-index: 1;
			}

			.dropdown-content a {
			  color: black;
			  padding: 12px 16px;
			  text-decoration: none;
			  display: block;
			}

			.dropdown a:hover {background-color: #ddd;}

			.show {display: block;}
		</style>
	</head>
<body>
	<ul>
		<li style="float:left"><a>Bem Vindo, <?php echo $_SESSION['usuario'];?>!</a></li>
		<li style="float:right"><a href="logout.php">Sair</a></li>
	</ul>
	
	<div class="dropdown">
        <h2 align ="left">Exercicios Uri.</h2>
        <table border="0" style="text-align:center;">
            <tr>
                <th width="100"  style="text-align:center;">ID</th>
                <th width="150"  style="text-align:center;">Nome</th>
                <th width="400"  style="text-align:center;">Descrição</th>
			 	<th width="150"  style="text-align:center;">
					<a onclick="e2pc()" class="dropbtn">E2PC</a>
						<div id="e2pc" class="dropdown-content">
							<a href="painel.php?ordem=p1&campo=data">F1</a>
							<a href="painel.php?ordem=p2&campo=data">F2</a>
						</div>
				</th>
				<th width="150"  style="text-align:center;">
					<a onclick="classificacao()" class="dropbtn">Classificação</a>
						<div id="classificacao" class="dropdown-content">
							<a href="painel.php?ordem=f1&campo=data">F1</a>
							<a href="painel.php?ordem=f2&campo=data">F2</a>
						</div>
				</th>
				<th width="200"  style="text-align:center;">
					<a onclick="dificuldade()" class="dropbtn">Dificuldade</a>
						<div id="dificuldade" class="dropdown-content">
							<a href="painel.php?ordem=crescente&campo=data">Crescente</a>
							<a href="painel.php?ordem=decrescente&campo=data">Decrescente</a>
						</div>
				</th>
				<th width="100"  style="text-align:center;">
					<a onclick="status()" class="dropbtn">Status</a>
						<div id="status" class="dropdown-content">
							<a href="painel.php?ordem=realizada&campo=data">Realizadas</a>
							<a href="painel.php?ordem=notrealizada&campo=data">Não Realizadas</a>
						</div>
				</th>
            </tr>
			<script> // Função para fazer o  dropdown
				function e2pc() { 
				  document.getElementById("e2pc").classList.toggle("show");
				}				
				function classificacao() {
				  document.getElementById("classificacao").classList.toggle("show");
				}								
				function dificuldade() {
				  document.getElementById("dificuldade").classList.toggle("show");
				}
				function status() {
				  document.getElementById("status").classList.toggle("show");
				}
				
				window.onclick = function(event) {
				  if (!event.target.matches('.dropbtn')) {
					var dropdowns = document.getElementsByClassName("dropdown-content");
					var i;
					for (i = 0; i < dropdowns.length; i++) {
					  var openDropdown = dropdowns[i];
					  if (openDropdown.classList.contains('show')) {
						openDropdown.classList.remove('show');
					  }
					}
				  }
				}
			</script>

			<?php
				ini_set('display_errors', 0 );
				error_reporting(0);
			?>
			<?php
				require('conexao.php');
				
				 // Formas para ordenar o banco de dados!
				if($_GET['ordem'] == "crescente") // Dificuldade
					$result = mysqli_query($db, "SELECT * FROM exercicio ORDER BY level desc");
				else if($_GET['ordem'] == "decrescente")
					$result = mysqli_query($db, "SELECT * FROM exercicio ORDER BY level asc");
				else if($_GET['ordem'] == "p1") // E2PC
					$result = mysqli_query($db, "SELECT * FROM exercicio ORDER BY e2pc desc");
				else if($_GET['ordem'] == "p2")
					$result = mysqli_query($db, "SELECT * FROM exercicio ORDER BY e2pc asc");
				else if($_GET['ordem'] == "f1") // Classificação
					$result = mysqli_query($db, "SELECT * FROM exercicio ORDER BY class desc");
				else if($_GET['ordem'] == "f2")
					$result = mysqli_query($db, "SELECT * FROM exercicio ORDER BY class asc");
				else if($_GET['ordem'] == "realizada")//Status
					$result = mysqli_query($db, "SELECT * FROM exercicio ORDER BY status desc");
				else if($_GET['ordem'] == "notrealizada")
					$result = mysqli_query($db, "SELECT * FROM exercicio ORDER BY status asc");
				else
					$result = mysqli_query($db, "SELECT * FROM exercicio"); //Padrão
				//termina a ordenação
				
				if(!$result){
					echo "" ;
					exit;
				}
		
				$linha =1;
				while($row = mysqli_fetch_assoc($result)) {
					echo "<tr>
							<td>" .$row['id'] ."</td>
							<td>" ."<a href=https://www.urionlinejudge.com.br/judge/pt/problems/view/".$row['id'] ."''>".$row['name'] ."</a></td>
							<td>" .$row['description'] ."</td>
							<td>" .$row['classe2pc'] ."</td>
							<td>" .$row['class'] ."</td>
							<td>" .$row['level'] ."</td>
							<td>" .$row['status'] ."</td>";
					$linha++;
				}
				mysqli_free_result($result);
			?>
        </table>
    </div>
</body>
</html>