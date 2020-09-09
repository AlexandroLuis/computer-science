package principal;
import arquivo.*;
import cliente.*;
import entradadados.*;

public class ClienteApp {/* Classe ClienteApp */
	public static void main(String[] args) {
		GerenciadorClientesArquivo gerenciador = new GerenciadorClientesArquivo(); /* Declara uma variável gerenciador de arquivos */
		Cliente[] cliente = new Cliente[10]; /* Declara um vetor de 10 posições para armazenar o nome dos clientes */
		inicializaClientes(cliente); /* Chama o método para declarar o vetor clientes */
		for(int i = 0; i < 10 ; i++){ /* Salvar o nome dos 10 clientes */
			System.out.printf("Informe o %d� cliente: ", i+1);
			cliente[i].setNome(Console.input());
		}
		gerenciador.gravarClientes(cliente); /* Chama o Método e Grava o nome dos clientes no arquivo */
		System.out.println();
		gerenciador.lerClientes(); /* Chama o Método para mostrar o nome dos clientes  */
	}
	public static void inicializaClientes(Cliente[] cliente) { /* Método que declara o vetor cliente */
		for(int i = 0; i < 10; i++) {
			cliente[i] = new Cliente();
		}
	}
}
