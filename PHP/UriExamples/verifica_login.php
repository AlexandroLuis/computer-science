<!--  
	Desenvolvido por https://github.com/Alexandro-845
	Versão 1.0 - 2020
-->
<?php
	session_cache_expire(60);
	session_start(); 

	if(!$_SESSION['usuario']) {
		header('Location: index.php');
		exit();
	}
?>