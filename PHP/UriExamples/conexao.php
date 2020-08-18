<!--  
	Desenvolvido por https://github.com/Alexandro-845
	Versão 1.0 - 2020
-->
<?PHP 
	$hostname='localhost';	//Nome do Seervidor
	$username='root';		//Nome do Usuario do servidor
	$pass='';				//Senha do servidor
	$bd='uriexamples';		//Nome do banco de dados
	
	//Conecta ao banco de dados
	$db=Mysqli_Connect($hostname, $username, $pass);	 
	Mysqli_Select_db($db, $bd);	
?>