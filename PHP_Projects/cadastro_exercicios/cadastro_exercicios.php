<html>
	<head>	
		<meta http-equiv="refresh" content="2; url=index.php">
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
	$description=$_POST ['description'];
	$class=$_POST ['class'];
	$level=$_POST ['level'];
	$source=$_POST ['source'];
	
		
	
	Require ('conexao.php');
	$sqlinsert ="insert into exercicio values ('$id','$name','$description','$class','$level','$source')";
	
	mysqli_query($db, $sqlinsert) or die ('NÃO FOI POSSIVEL INSERIR :(');
	echo "<script> alert ('cadastro realizado com sucesso :)')</script>"; 
	
?>

</body>
</html>