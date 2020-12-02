public interface Esporte {
	void praticar();
}

public class Corrida implements Esporte {
	public void praticar() {
		System.out.println(Praticando corrida);
	}
}

public class Natacao implements Esporte {
	public void praticar() {
		System.out.println(Praticando nata��o);
	}
}
