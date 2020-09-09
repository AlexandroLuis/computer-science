package arquivo;
import cliente.*;
/* Declaração da Interface GerenciadorClientes
   E dos métodos gravar e mostrar */
public interface GerenciadorClientes { 
	public void gravarClientes(Cliente[] cliente); 
	public void lerClientes();
}
