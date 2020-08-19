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
		$id=$_GET['id'];
		$name=$_GET['name'];
		$class=$_GET['class'];
		$description=$_GET['description'];
		$type=$_GET['type'];
		$level2pc=$_GET['level2pc'];
		$level=$_GET['level'];
		$status=$_GET['status'];
		$Observation=$_GET['Observation'];
		$source=$_GET['source'];
		
		require('conexao.php');
		//$alterar ="update usuarios set id='$id', name='$name', description='$description', level2pc='$level2pc', level='$level', Observation='$Observation', source='$source' where id='$id' ";
		$alterar ="update usuarios set id='$id', name='$name', class='$class', description='$description', type='$type', level2pc='$level2pc', level='$level', status='$status', Observation='$Observation', source='$source' where id='$id' ";
		mysqli_query($db,$alterar) or die ('Não foi possível alterar');
		echo"Alterado Com Sucesso!";
	?>
</body>
</html>