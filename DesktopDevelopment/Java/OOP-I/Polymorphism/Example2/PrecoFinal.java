public class PrecoFinal {
	public static void main(String[] args){
		ClienteDesconto cliente = new ClienteDesconto();
		
		cliente.DescontoFinal(new Cliente());
		cliente.DescontoFinal(new Clienteespecial());
	}
}