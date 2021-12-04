public class Triangulo extends Shape {
	private String estilo;

	public Triangulo(String nomeFig, double altura, double largura, String estilo1) {
		super(nomeFig, altura, largura);
		estilo = estilo1;

	}

	public void mostraEstilo() {
		System.out.println("Estilo = " + estilo);
	}

	public double area() {
		return (getLargura() * getAltura()) / 2;
	}

}