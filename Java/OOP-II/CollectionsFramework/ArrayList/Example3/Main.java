import java.util.*;

public class Main { 
  public static void main(String[] args) { 
    ArrayList<String> Passaro = new ArrayList<>();
    Passaro.add("Arara");
	Passaro.add("Calopsita");
	Passaro.add("Aguia");
	Passaro.add("Agapornis");
	Passaro.add("Papagaio");

    ListIterator<String> iteratorPassaro = Passaro.listIterator(Passaro.size());

	while(iteratorPassaro.hasPrevious())
	  System.out.println(iteratorPassaro.previous());
  } 
}
