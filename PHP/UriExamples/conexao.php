<?PHP 

	$hostname='localhost';	
	$username='root';	
	$pass='';		
	$bd='uriexamples';	
	$db=Mysqli_Connect($hostname, $username, $pass);
	
	Mysqli_Select_db($db, $bd);
	
?>