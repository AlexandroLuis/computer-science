public class MaisDois implements Series {
	private int inicio;
	private int valor;

	public MaisDois() {
		inicio = 0;
		valor = 0;
	}
	
	public int getNext() {
		valor += 2;
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