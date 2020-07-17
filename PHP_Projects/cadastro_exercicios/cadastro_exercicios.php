<html>
	<head>	
		<meta http-equiv="refresh" content="2; url=Admin.php">
		<meta charset=".utf-8">
		<script type="text/javascript"></script>
	</head>
<body>
<?php
	ini_set('display_errors', 0 );
	error_reporting(0);
?>
<?php

	$id=$_POST ['id'];
	$name=$_POST ['name'];
	$class=$_POST ['class'];
	$description=$_POST ['description'];
	$type=$_POST ['type'];
	$level2pc=$_POST ['level2pc'];
	$level=$_POST ['level'];
	$source=$_POST ['source'];
	
	echo"Valor de Código a ser guardado: ";
	echo nl2br($_POST['source']);
	
		
	
	Require ('conexao.php');
	$sqlinsert ="insert into exercicio values ('$id','$name','$class','$description','$type','$level2pc','$level','0','$source')";
	
	mysqli_query($db, $sqlinsert) or die ('NÃO FOI POSSIVEL INSERIR :(');
	echo "<script> alert ('cadastro realizado com sucesso :)')</script>"; 
	
?>

</body>
</html>