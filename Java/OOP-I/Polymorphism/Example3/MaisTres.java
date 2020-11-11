public class MaisTres implements Series {
	private int inicio;
	private int valor;

	public MaisTres() {
		inicio = 0;
		valor = 0;
	}

	public int getNext() {
		valor += 3;
		return valor;
	}

	public void reset() {
		valor = inicio;
	}

	public void setStart(int x) {
		inicio = x;
		valor = x;
	}

}