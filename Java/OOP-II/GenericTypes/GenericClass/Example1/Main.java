public class Main {
	public static void main(String[] args) {
	  Gen2<Integer> num;
      	  num = new Gen2<Integer>(5);
	  // Exibe o tipo de dado usado por num
	  num.showTipos();
	  // Obt�m o valor de num
	  int valor = num.getOb();
	  System.out.println("Valor: " + valor);
	}
}
