public class TestaFigura {
	public static void main(String[] args){
		Figura figura = new Figura();
		
		figura.areatotal(new circulo());
		figura.areatotal(new quadrado());
		figura.areatotal(new circulo());
	}
}