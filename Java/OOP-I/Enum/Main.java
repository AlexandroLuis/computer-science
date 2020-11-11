public class Main{
	public static void main(String[] args) {
		Luz[] luz = new Luz[3];
		int i = 0;
		luz[i] = Luz.Vermelho; 
		luz[++i] = Luz.Ambar; 
		luz[++i] = Luz.Verde; 
		
		for(i = 0; i < 3; i++){
		    switch (luz[i]) {
		    case Vermelho:
		    	System.out.println("palestra indisponível");
			    break;
		    case Ambar:
		    	System.out.println("palestra sendo liberada");
			    break;
		    case Verde:
			    System.out.println("palestra disponivel");
		    	break;
		    }		 
		}
	}
}
