<html>
	<head>
		<title></title>
		<meta charset="utf-8">
		<style>
		/* Popup container - can be anything you want */
			.popup {
			  position: relative;
			  display: inline-block;
			  cursor: pointer;
			  -webkit-user-select: none;
			  -moz-user-select: none;
			  -ms-user-select: none;
			  user-select: none;
			}

			/* The actual popup */
			.popup .popuptext {
			  visibility: hidden;
			  width: 160px;
			  background-color: #555;
			  color: #fff;
			  text-align: center;
			  border-radius: 6px;
			  padding: 8px 0;
			  position: absolute;
			  z-index: 1;
			  bottom: 125%;
			  left: 50%;
			  margin-left: -80px;
			}

			/* Popup arrow */
			.popup .popuptext::after {
			  content: "";
			  position: absolute;
			  top: 100%;
			  left: 50%;
			  margin-left: -5px;
			  border-width: 5px;
			  border-style: solid;
			  border-color: #555 transparent transparent transparent;
			}

			/* Toggle this class - hide and show the popup */
			.popup .show {
			  visibility: visible;
			  -webkit-animation: fadeIn 1s;
			  animation: fadeIn 1s;
			}

			/* Add animation (fade in the popup) */
			@-webkit-keyframes fadeIn {
			  from {opacity: 0;} 
			  to {opacity: 1;}
			}

			@keyframes fadeIn {
			  from {opacity: 0;}
			  to {opacity:1 ;}
			}
			body {
				background-color:white; 
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
	
	<div class="tab-container">
        <h2>Exercicios Uri Cadastrados</h2>
        <table style="text-align:center;">
            <tr>
                <th width="75" align="center">ID</th>
                <th width="100">Nome</th>
                <th width="400">Descrição</th>
                <th width="100">Classificação</th>
                <th width="150">Dificuldade</th>
				<th>Código</th>
            </tr>
			<?php
				ini_set('display_errors', 0 );
				error_reporting(0);
			?>
			<?php
				require('conexao.php');
				$result = mysqli_query($db, "SELECT * FROM exercicio");
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
							<td>" .$row['class'] ."</td>
							<td>" .$row['level'] ."</td>
							<td>"?>
									<div class="popup" onclick="myFunction()">Mostrar Código!
									<span class="popuptext" id="myPopup">xxxsgsdfgjdfhkghkdfhkghkdafkghdfhagkjx</span>
								   </div>
								   <?PHP "</td>";
					$linha++;
				}
				mysqli_free_result($result);
			?>
        </table>
    </div>
	
	<script>
		function myFunction() {
			var popup = document.getElementById("myPopup");
			popup.classList.toggle("show");
		}
	</script>
</body>
</html>
