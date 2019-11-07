<HTML>
<HEAD>
<meta charset=".utf-8">
<script type="text/javascript"></script>
 </HEAD>
<BODY>

<?php
ini_set('display_errors', 0 );
error_reporting(0);
?>


<?php 

	$VA=$_POST ['valorA'];
	$VB=$_POST ['valorB'];
	$VC=$_POST ['valorC'];
	$X1=$_POST ['valorX'];
	$Y1=$_POST ['valorY'];
	$Z1=$_POST ['valorZ'];
	
	
	
	$MX = (-$VA / $VB);
	$M = (-$VC / $VB);
	
	Echo("
	Vetorial:");?><br><?PHP 
	Echo("&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
	(X, Y, Z) = ($X1, $Y1, $Z1) + ($VA, $VB, $VC)
	");?><br><br><?PHP
	Echo("
	Paramétrica:
	");?><br><?PHP 
	Echo("
	&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
	X = $X1 + $VA T");?><br><?PHP Echo("
	&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
	Y = $Y1 + $VB T");?><br><?PHP Echo("
	&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
	Z = $Z1 + $VC T");?><br><br><?PHP
	Echo("
	Simétrica:
	");?><br><?PHP
	Echo("&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
	((X - ($X1)) / $VA) = ((Y - ($Y1)) / $VB) = ((Z - ($Z1)) / $VC)
	");?><br><br><?PHP
	Echo("
	Reduzida:
	");?><br><?PHP
	Echo("&nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
	Y = $MX + $M
	");
	
?>

</body>
<br><br><br>
<a href="Equacoes.html">Voltar</a>
</html>
