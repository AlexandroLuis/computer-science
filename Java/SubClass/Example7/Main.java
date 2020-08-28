public class Main {
  public static void main(String[] args) {
     Figura[] figuras = new figura [3];
	 
	 figuras[0] = new Quadrado();
	 figuras[1] = new Retangulo();
	 figuras[2] = new Triangulo();
	 
	 for(int i = 0; i < 3; i++){
		 figuras[i].desenhar();
		 figuras[i].apagar();
	 }
   }
}
