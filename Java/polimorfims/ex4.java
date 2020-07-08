public interface Series{
	public int getNext();
	public void reset();
	public void setStart(int x);
}

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

public class Sum{ //POLIMORFISMO
  public void ShowNumero(Series numero){
	 
	reset();
	for(int i = 0; i < 5; i++
       getNext();
	   
	setStart(100);
	for(int i = 0; i < 5; i++
       getNext();
	
}

public class Numeros {
	public static void main(String[] args){
		Numero numero = new Sum();
		
		numero.ShowNumero(new MaisDois()); //CHAMADA DO POLIMORFISMO
		numero.ShowNumero(new MaisTres());
	}
}
