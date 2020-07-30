public class TestaFigura {
	public static void main(String[] args) {
		Shape figura = new Shape();
		
		figura.area(new Retangulo());
		figura.area(new Triangulo());
	}
}
