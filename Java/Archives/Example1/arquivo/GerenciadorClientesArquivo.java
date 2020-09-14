package arquivo;
import cliente.*;
import java.io.*;
/* Classe GerenciadorClientesArquivo, Grava e Le nome no arquivo clientes.txt */
public class GerenciadorClientesArquivo implements GerenciadorClientes{
	@Override
	public void gravarClientes(Cliente[] cliente) {/* Método para salvar nome no arquivo */
		BufferedWriter writer = null; /* Declara "writer" como null */
		try {
			writer = new BufferedWriter(new FileWriter("clientes.txt")); /* Cria o arquivo */
			for(int i = 0; i < 10; i++) {
				writer.write(cliente[i].getNome()); /* escreve o nome no arquivo */
				writer.newLine();	
			}
		} catch(IOException exc) { /* Excessão para erro de entrada e saída */
			System.out.println("Erro de I/O " + exc);
		} finally { /* Sempre vai executar e verificar se */
			try {
				if(writer != null) { /* Marquivo writer está vazio, pois não foi passado nomes */
					writer.close(); /* Fecha o arquivo */
				}
			} catch(IOException exc) { /* Mostra a mesnagem a seguir caso exc seja válido */
				System.out.println("Fechando arquivo " + exc);
			}
		}
	}

	@Override
	public void lerClientes(){/* Método para mostrar os clientes que estão no arquivo */
		String s;
		try (BufferedReader br = new BufferedReader(new FileReader("clientes.txt"))) {/* br recebe o arquivo clientes.txt */
			System.out.println("Clientes cadastrados no arquivo:");
			while((s = br.readLine()) != null ) { /* enquanto br tiver linhas preenchidas */
				System.out.println(s); /* Mostra o nome */
			} 
		} catch(IOException exc) {/* Excessão para erros de IO */
			System.out.println("Erro de I/O: " + exc);
		}
		
	}

}
