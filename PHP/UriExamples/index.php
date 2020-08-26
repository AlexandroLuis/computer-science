<!--  
	Desenvolvido por https://github.com/Alexandro-845
	Versão 1.0 - 2020
-->
<?php
	session_start();
?>
<html>
<head>
    <meta charset="utf-8">
    <title>Página Inicial- Exercicios URI</title>
	<link rel="shortcut icon" href="Images/favicon.ico" />
	<script src="https://apis.google.com/js/platform.js" async defer></script>
	<meta name="google-signin-client_id" content="384602407862-g2t95qbtuto07r923qlic2317dbrkboa.apps.googleusercontent.com">
</head>
 
<body>
    <script type="text/javascript">
		function onSignIn(googleUser){
			var profile = googleUser.getBasicProfile();	  
			var id_token = googleUser.getAuthResponse().id_token; 
			 
			console.log('Token: ' + id_token);
			console.log('ID: ' + profile.getId()); 
			console.log('Name: ' + profile.getName());
			console.log('Image URL: ' + profile.getImageUrl());
			console.log('Email: ' + profile.getEmail());	  
		}
	</script>
	<div class="g-signin2" data-onsuccess="onSignIn">
</body>
</html>