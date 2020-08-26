<html>
<head>
	<meta charset="utf-8">
	<title>Editando...</title>
	<meta http-equiv="refresh" content="2; url=Admin.php">
	<script type="text/javascript"></script>
	<link rel="shortcut icon" href="Images/favicon.ico" />
</head>
<body>
	<?php 
		$class=$_GET['class'];
		$type=$_GET['type'];
		$status=$_GET['status'];
		$id=$_GET['id'];
		$name=$_GET['name'];
		$description=$_GET['description'];		
		$level2pc=$_GET['level2pc'];
		$level=$_GET['level'];		
		$Observation=$_GET['Observation'];	
		$source=$_GET['source'];
		
		require('conexao.php');
		//$alterar ="update usuarios set id='$id', name='$name', description='$description', level2pc='$level2pc', level='$level', Observation='$Observation' where id='$id' ";
		$alterar ="update exercicio set id='$id', name='$name', class='$class', description='$description', type='$type', level2pc='$level2pc', level='$level', status='$status', Observation='$Observation', source='$source' where id='$id' ";
		mysqli_query($db,$alterar) or die ('Não foi possível alterar');
	?>
	<h1>Alterado Com Sucesso!</h1>
</body>
</html>