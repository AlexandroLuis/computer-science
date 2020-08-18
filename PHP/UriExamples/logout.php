<!--  
	Desenvolvido por https://github.com/Alexandro-845
	Versão 1.0 - 2020
-->
<?php
	session_start();
	session_destroy();
	header('Location: index.php');
	exit();
?>