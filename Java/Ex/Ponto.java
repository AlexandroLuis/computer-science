public class Ponto{
	public static void main(String[] args){
		Ponto2D ponto1 = new Ponto2D(3, 5);
		Ponto2D ponto2 = new Ponto2D();
			
		ponto1.mostrarxy();
		ponto2.mostrarxy();
		
		System.out.println(Ponto2D.geti());
	}
}
