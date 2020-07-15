<?php
	session_start();
?>
<html>
<head>
    <meta charset="utf-8">
    <title>Página Inicial- Exercicios URI</title>
</head>
 
<body>
    <?php
        if(isset($_SESSION['nao_autenticado'])):
    ?>
    <div class="notification is-danger">
        <p>ERRO: Usuário ou senha inválidos.</p>
    </div>
    <?php
		endif;
		unset($_SESSION['nao_autenticado']);
    ?>
    <div class="box">
        <form action="login.php" method="POST">
			<div class="field">
				<div class="control">
					 <input name="usuario" name="text" class="input is-large" placeholder="Seu usuário" autofocus="">
				</div>
			</div>
			<div class="field">
				<div class="control">
					<input name="senha" class="input is-large" type="password" placeholder="Sua senha">
				</div>
			</div>
				<button type="submit" class="button is-block is-link is-large is-fullwidth">Entrar</button>
        </form>
	</div>
</body>
</html>