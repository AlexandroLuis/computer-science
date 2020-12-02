import java.util.*;

public class Main {
  public static void main(String[] args) {
    Integer integerArray[] = {9, 6, 10};
    String stringArray[] = {"A, ", "B, ","C!"};
	Double DoubleArray[] = {9.610, 6.910, 10.96};
	Character CharacterArray[] = {'A'};
	
	printArray(integerArray);
	//printArray(stringArray);
	printArray(DoubleArray);
	//printArray(CharacterArray);
	
	//REMOVER OS *//* PARA TESTAR!
  }
  public static <E extends Number> void printArray(E[] array) {
	for (E element : array)
		System.out.printf("%s ", element);
	System.out.println();
	}
}
