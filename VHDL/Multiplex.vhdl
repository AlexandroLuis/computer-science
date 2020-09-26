Library ieee;
Use ieee.std_logic_1164.all;
Entity multiplex2p1 is
	Generic(n: natural);
		Port(a, b: IN std_logic_vector(n-1 downto 0);
		 sel: IN std_logic_vector(2 downto 0);
		 s: OUT std_logic_vector(2 downto 0)
		);
End multiplex2p1; 
Architecture mult of multiplex2p1 is
Begin
	s<= 11 when a = ‘1’ && b = ‘1’ else
		10 when a = ’0’ && b = ’1’ else
		‘00’;
End mult; 
