public abstract class Shape {
	public abstract void Area();	
}

public abstract class Shape {
	private double largura;
	private double altura;
	private String nomeFig;

	public Shape(String nomeFig, double altura, double largura) {
		this.nomeFig = nomeFig;
		this.altura = altura;
		this.largura = largura;
	}

	public String getNomeFig() {
		return nomeFig;
	}

	public double getLargura() {
		return largura;
	}

	public void setLargura(double largura1) {
		largura = largura1;
	}

	public double getAltura() {
		return altura;
	}

	public void setAltura(double altura1) {
		altura = altura1;
	}

	public void mostraDim() {
		System.out.println("Largura e altura = " + largura + " e " + altura);
	}
}

public class Retangulo extends Shape {
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

public class TestaFigura {
	public static void main(String[] args) {
		Shape figura = new Shape();
		
		figura.area(new Retangulo());
		figura.area(new Triangulo());
	}
}
