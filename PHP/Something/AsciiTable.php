<html>
<head>
	<meta charset="utf-8">
</head>
<body>
	<table border="1">
		<tr>
			<td width="150">Inteiro</td>
			<td width="150">Caractere</td>
			<td width="150">Binário</td>
			<td width="150">Octal</td>
			<td width="150">Ponto Flutuante</td>
			<td width="150">Hexadecimal</td>
			<td width="150">Notação Cientifica</td>
		</tr>
		<?php
			$i = 0;
			while($i++ < 255){
				echo"
				<tr>
					<td>";printf("%d", $i);echo"</td>
					<td>";printf("%c", $i);echo"</td>
					<td>";printf("%b", $i);echo"</td>
					<td>";printf("%o", $i);echo"</td>
					<td>";printf("%f", $i);echo"</td>
					<td>";printf("%X", $i);echo"</td>
					<td>";printf("%e", $i);echo"</td>
				</tr>";
				?><br><?php
			}
		?>
	</table>
</body>
</html>
