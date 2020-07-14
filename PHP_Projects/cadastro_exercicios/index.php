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
		<li style="float:right"><a href="Cex.php">Cadastrar Novo</a></li>
		<li style="float:right"><a href="index.php">Exercicios Uri</a></li>
	</ul>
	
	<div class="dropdown">
        <h2>Exercicios Uri Cadastrados</h2>
        <table border="0" style="text-align:center;">
            <tr>
                <th width="100"  style="text-align:center;">ID</th>
                <th width="150"  style="text-align:center;">Nome</th>
                <th width="400"  style="text-align:center;">Descrição</th>
			 	<th width="150"  style="text-align:center;">
					<a onclick="e2pc()" class="dropbtn">E2PC</a>
						<div id="e2pc" class="dropdown-content">
							<a href="index.php?ordem=p1&campo=data">F1</a>
							<a href="index.php?ordem=p2&campo=data">F2</a>
						</div>
				</th>
				<th width="150"  style="text-align:center;">
					<a onclick="classificacao()" class="dropbtn">Classificação</a>
						<div id="classificacao" class="dropdown-content">
							<a href="index.php?ordem=f1&campo=data">F1</a>
							<a href="index.php?ordem=f2&campo=data">F2</a>
						</div>
				</th>
				<th width="200"  style="text-align:center;">
					<a onclick="dificuldade()" class="dropbtn">Dificuldade</a>
						<div id="dificuldade" class="dropdown-content">
							<a href="index.php?ordem=crescente&campo=data">Crescente</a>
							<a href="index.php?ordem=decrescente&campo=data">Decrescente</a>
						</div>
				</th>
				<th width="150"  style="text-align:center;">Código</th>
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
				$result = mysqli_query($db, "SELECT * FROM exercicio");
				 
				 // Começa a ordenar
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
							<td>"?>
								<a href="" data-toggle="modal" data-target="#exampleModalLong">Mostrar Código</a>
									<div class="modal fade" id="exampleModalLong" tabindex="-1" role="dialog" aria-labelledby="exampleModalLongTitle" aria-hidden="true">
									  <div class="modal-dialog" role="document">
										<div class="modal-content">
										  <div class="modal-header">
											<h5 class="modal-title" id="exampleModalLongTitle">Código</h5>
											<button type="button" class="close" data-dismiss="modal" aria-label="Close">
												<span aria-hidden="true">&times;</span>
											</button>
										  </div>
										  <div class="modal-body">
											<?php
												echo "" .$row['source'] ."";
											?>
										  </div>
										  <div class="modal-footer">
											<button type="button" class="btn btn-primary" data-dismiss="modal">Close</button>
										  </div>
										</div>
									  </div>
									</div>
							<?php
							"</td>";
					$linha++;
				}
				mysqli_free_result($result);
			?>
        </table>
    </div>
</body>
</html>