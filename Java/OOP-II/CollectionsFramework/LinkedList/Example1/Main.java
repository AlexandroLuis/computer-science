import java.util.*;

public class Main {
	public static void main(String[] args) {
		String[] cor1 = {"preto", "amarelo", "verde", "azul", "branco"};
		String[] cor2 = {"dourado", "prata", "marrom", "cinza"};
		List<String> list1 = new LinkedList<>(Arrays.asList(cor1));
		List<String> list2 = new LinkedList<>(Arrays.asList(cor2));
		
		System.out.println("Lista 1: ");
		printList(list1);
		System.out.println("Lista 2: ");
		printList(list2);
		list1.addAll(list2);
		
		System.out.println("Concatenação: ");
		printList(list1);
		
	}
	public static void printList(Collection<String> list) {
		for(String l: list) {
			System.out.println(l);
		}
	}
}
