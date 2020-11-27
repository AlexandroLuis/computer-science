import java.util.*;

class Main {
	public static void main(String[] args) {
		LinkedList <Character> List1Char = new LinkedList<>();
		LinkedList <Character> List2Char = new LinkedList<>();
		
		for (int i = 0; i < 26; i += 2) {
			List1Char.add((char) ('A' + i));
			List1Char.add((char) ('Z' - i));
		}
		for(int i = 65; i < 92; i+=5)
		    List2Char.add((char) (i));
		
		
		System.out.print("Lista original : ");
		for (char ch : List1Char)
			System.out.print(ch);
		
		Collections.sort(List1Char);
		
		System.out.print("\nLista classificada: ");
		for (char ch : List1Char)
			System.out.print(ch);
		
		Collections.replaceAll(List1Char,'T', '*');
		System.out.print("\nLista 1 sem o T: ");
		for (char ch : List1Char)
			System.out.print(ch);
			
		System.out.print("\nLista 2: ");
		for(char ch : List2Char)
	    	System.out.print(ch + ", ");
	}
}
