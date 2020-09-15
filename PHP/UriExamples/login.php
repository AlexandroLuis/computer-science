<!--  
	Desenvolvido por https://github.com/Alexandro-845
	Versão 1.0 - 2020
-->
<?php
	session_start();

	include_once("conexao.php");
	$email = filter_input(INPUT_POST, 'userEmail', FILTER_SANITIZE_STRING);

	$result_usuario = "SELECT * FROM usuarios WHERE email='$email' LIMIT 1";
	$resultado_usuario = mysqli_query($bd, $result_usuario);
	
	if(($resultado_usuario) AND ($resultado_usuario->num_rows != 0)){
		$userName = filter_input(INPUT_POST, 'userName', FILTER_SANITIZE_STRING);
		$_SESSION['userName'] = $userName;
		$resultado = 'Admin.php';
		echo $resultado;
	}else{
		$resultado = 'Erro, Nenhum Usuario Encontrado!';
		echo(json_encode($resultado));
	}
?>