package entradadados;
import java.io.*;

public class Console {/* Método de Leitura do teclado ser chamado. */
	public static String input() {
		try {
			BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
			return reader.readLine();
		} catch (IOException exc) {
			throw new RuntimeException("Erro ao ler dado do teclado");
		}
		
	}
}