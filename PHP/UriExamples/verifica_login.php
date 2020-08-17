<?php
	session_cache_expire(60);
	session_start(); 

	if(!$_SESSION['usuario']) {
		header('Location: index.php');
		exit();
	}
?>