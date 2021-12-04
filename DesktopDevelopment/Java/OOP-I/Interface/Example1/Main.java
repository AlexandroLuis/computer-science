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
	   orquestra[i].afinar();
	}
  }
}
