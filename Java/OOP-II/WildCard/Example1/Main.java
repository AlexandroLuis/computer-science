import java.util.ArrayList;
import java.util.List;
public class Main {
	public static void main(String[] args) {
		List<Esporte> esportes = new ArrayList<Esporte>();

		esportes.add(new Corrida());
		esportes.add(new Natacao());

		praticarEsportes(esportes);
	}
	
	public static void praticarEsportes(List<? extends Esporte> esportes) {
		for (Esporte b : esportes) {
			b.praticar();
		}
	}
}
