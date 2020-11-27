import java.util.*;
class Main {
	public static void main(String[] args) {
		ArrayList <String> ArrayNames = new ArrayList<>();

		Collections.reverse(ArrayNames);
		
		ArrayNames.add("Nome 1");
		ArrayNames.add("Nome 2");
		ArrayNames.add("Nome 3");
		ArrayNames.add("Nome 4");
		ArrayNames.add("Nome 5");
		
		Iterator<String> iterator = ArrayNames.iterator();
		
		while (iterator.hasNext()) 
            System.out.print(iterator.next() + " "); 
	}
}
