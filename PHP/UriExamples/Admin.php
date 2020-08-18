<!--  
	Desenvolvido por https://github.com/Alexandro-845
	Versão 1.0 - 2020
-->
<?php
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
		<li style="float:left"><a href="perfil.php">Bem Vindo, <?php echo $_SESSION['usuario'];?>!</a></li>
		<li style="float:right"><a href="logout.php">Sair</a></li>
		<li style="float:right"><a href="Cex.php">Inserir Novo</a></li>	
	</ul><!-- Fim Menu Inicial -->
	
	<div class="tab-container"><!-- Lista De Problemas -->
        <h2 align ="left">Seleção de Problemas do URI Online Judge!</h2><br>
        <table border="0" style="text-align:left;">
            <tr>
				<th width="10"></th>
                <th width="75">ID</th>
                <th width="230">Nome</th>
				<th width="150">
					<a onclick="classificacao()" class="dropbtn">Categoria</a>
						<div id="classificacao" class="dropdown-content">
							<a href="Admin.php?ordem=class&campo=data">Ordenar por Categoria</a>
						</div>
				</th>
				<th width="75">
					<a onclick="dificuldade()" class="dropbtn">Nivel</a>
						<div id="dificuldade" class="dropdown-content">
							<a href="Admin.php?ordem=dificuldade1&campo=data">Crescente</a>
							<a href="Admin.php?ordem=dificuldade2&campo=data">Decrescente</a>
						</div>
				</th>
                <th width="415">Descrição</th>
				<th width="160">
					<a onclick="tipo()" class="dropbtn">Classificação</a>
						<div id="tipo" class="dropdown-content">
							<a href="Admin.php?ordem=tipo1&campo=data">Ordenar Por tipo</a>
						</div>
				</th>			 					
				<th width="120" >
					<a onclick="dificuldadee2pc()" class="dropbtn">Dificuldade</a>
						<div id="dificuldadee2pc" class="dropdown-content">
							<a href="Admin.php?ordem=dificuldadee2pc1&campo=data">Crescente</a>
							<a href="Admin.php?ordem=dificuldadee2pc2&campo=data">Decrescente</a>
						</div>
				</th>	
				<th width="100">Código</th>
            </tr><!-- Fim Lista de Problemas -->
			
			<script><!-- Função para fazer o  dropdown -->
				function classificacao() {
				  document.getElementById("classificacao").classList.toggle("show");
				}	
				function tipo() { 
				  document.getElementById("tipo").classList.toggle("show");
				}				
				function dificuldadee2pc() {
				  document.getElementById("dificuldadee2pc").classList.toggle("show");
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
			</script><!-- Fim da Função dropdown -->

			<?php
				ini_set('display_errors', 0 );
				error_reporting(0);
			?>
			<?php
				require('conexao.php');
				
				// Formas para ordenar o banco de dados!	
				if($_GET['ordem'] == "class")//Classificação
					$result = mysqli_query($db, "SELECT * FROM exercicio ORDER BY class desc");					
				else if($_GET['ordem'] == "tipo1")//Tipo
					$result = mysqli_query($db, "SELECT * FROM exercicio ORDER BY type desc");					
				else if($_GET['ordem'] == "dificuldadee2pc1")//Dificuldade E2PC
					$result = mysqli_query($db, "SELECT * FROM exercicio ORDER BY level2pc asc");
				else if($_GET['ordem'] == "dificuldadee2pc2") 
					$result = mysqli_query($db, "SELECT * FROM exercicio ORDER BY level2pc desc");					
				else if($_GET['ordem'] == "dificuldade1")//Dificuldade 
					$result = mysqli_query($db, "SELECT * FROM exercicio ORDER BY level asc");
				else if($_GET['ordem'] == "dificuldade2")
					$result = mysqli_query($db, "SELECT * FROM exercicio ORDER BY level desc");								
				else//Padrão
					$result = mysqli_query($db, "SELECT * FROM exercicio");
				//Fim da ordenação
				
				if(!$result){
					echo "" ;
					exit;
				}
		
				$linha =1;
				while($row = mysqli_fetch_assoc($result)) {
					echo "<tr>
							<td></td>
							<td>" ."<a href=editarproblema.php?id=".$row['id'] .">".$row['id'] ."</a></td>
							<td>" ."<a href=https://www.urionlinejudge.com.br/judge/pt/problems/view/".$row['id'] .">".$row['name'] ."</a></td>
							<td>" .$row['class'] ."</td>
							<td>" .$row['level'] ."</td>
							<td>" .$row['description'] ."</td>
							<td>" .$row['type'] ."</td>
							<td>" .$row['level2pc'] ."</td>							
							<td>" ."<a href=Mostrarcodigo.php?id=".$row['id'] .">Mostrar Código</a></td>";
					$linha++;
				}
				mysqli_free_result($result);
			?>
        </table>
    </div>
</body>
</html>