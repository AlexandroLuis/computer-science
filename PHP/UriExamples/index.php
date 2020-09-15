<!--  
	Desenvolvido por https://github.com/Alexandro-845
	Versão 1.0 - 2020
-->
<html>
<head>
    <meta charset="utf-8">
    <title>Página Inicial- Exercicios URI</title>
	<link rel="shortcut icon" href="Images/favicon.ico" />
	<script src="https://apis.google.com/js/platform.js" async defer></script>
	<meta name="google-signin-client_id" content="384602407862-g2t95qbtuto07r923qlic2317dbrkboa.apps.googleusercontent.com">
</head>
<body>
	<div class="g-signin2" data-onsuccess="onSignIn"><a href="Admin.php">Entrar!</a></div>
		<p id='erro'></p>
	<script>
		function onSignIn(googleUser){
			var profile = googleUser.getBasicProfile();
			var userID = profile.getId(); 
			var userName = profile.getName(); 
			var userPicture = profile.getImageUrl(); 
			var userEmail = profile.getEmail(); 			 
			var userToken = googleUser.getAuthResponse().id_token; 	
				
			//document.getElementById('erro').innerHTML = userEmail;
			if(userEmail !== ''){
				var dados = {
					userID:userID,
					userName:userName,
					userPicture:userPicture,
					userEmail:userEmail
				};
				$.post('login.php', dados, function(retorna){
					if(retorna === '"erro"'){
						var erro = "Usuário não encontrado com esse e-mail";
						document.getElementById('erro').innerHTML = erro;
					}else{
							window.location.href = retorna;
					}
					
				});
			}else{
				var erro = "Usuário não encontrado!";
				document.getElementById('erro').innerHTML = erro;
			}
		}		
	</script>	
</body>
</html>