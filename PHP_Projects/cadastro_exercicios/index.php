<html>
	<head>
		<title></title>
		<meta charset="utf-8">
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
	
	<div class="tab-container">
        <h2>Exercicios Uri Cadastrados</h2>
        <table border="0" style="text-align:center;">
            <tr>
                <th width="100"  style="text-align:center;">ID</th>
                <th width="150"  style="text-align:center;">Nome</th>
                <th width="400"  style="text-align:center;">Descrição</th>
                <th width="200"  style="text-align:center;">Classificação</th>
                <th width="150"  style="text-align:center;">Dificuldade</th>
				<th width="150"  style="text-align:center;">Código</th>
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