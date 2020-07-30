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