public class Main{
	public static void main(String[] args) {
		LUZ[] luz = new LUZ[3];
		int i = 0;
		luz[i] = LUZ.Vermelho; 
		luz[++i] = LUZ.Ambar; 
		luz[++i] = LUZ.Verde; 
		
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
