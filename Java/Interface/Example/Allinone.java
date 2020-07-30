public interface Instrumento{
  public void tocar();
  public void nome();
  public void afinar();
}

public class Corda implements Instrumento{
	public void tocar(){
	   System.out.println("Tocando Violão");
	}
	public void nome(){
	  System.out.println("Violão.");	
	}
	public void afinar(){
    	System.out.println("Afinando a Corda do violão!");
	}
}

public class Percussão implements Instrumento{
	public void tocar(){
	   System.out.println("Tocando Pandeiro...");
	}
	public void nome(){
	  System.out.println("Pandeiro!");	
	}
	public void afinar(){
    	System.out.println("Afinando o Pandeiro");
	}
}

public class Sopro implements Instrumento{
	public void tocar(){
	   System.out.println("Tocando Flauta...");
	}
	public void nome(){
	  System.out.println("Flauta é o nome do instrumento!");	
	}
	public void afinar(){
    	System.out.println("Verificando a afinação da Flauta.");
	}
}

public class SoproMadeira extends Sopro{
	public void tocar(){
	   System.out.println("Tocando Flauta de madeira");
	}
	public void nome(){
	  System.out.println("Flauta de madeira é o nome do instrumento!");	
	}
	public void afinar(){
    	System.out.println("Verificando a afinação da Flauta que é de madeira.");
	}
}

public class SoproMetal extends Sopro{
	public void tocar(){
	   System.out.println("Tocando Flauta de metal...");
	}
	public void nome(){
	  System.out.println("Flauta de metal é o nome do instrumento!");	
	}
	public void afinar(){
    	System.out.println("Verificando a afinação da Flauta que é de metal.");
	}
}

public class Main {
    public static void main (String[] args) {
	Instrumento[] orquestra = new Instrumento[5];
	int i = 0;
	
    	orquestra[i++] = new Sopro();
        orquestra[i++] = new Corda();
   	orquestra[i++] = new Percussao();
        orquestra[i++] = new SoproMadeira();
	orquestra[i]   = new SoproMetal();
	
	for(i = 0; i < 5; i++){
	    orquestra[i].tocar();
	    orquestra[i].nome();
	    orquestra[i].afinar());
	}
    }
}
