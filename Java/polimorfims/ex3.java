public class Cliente{
	private double dinheiro;
	public CalcDesconto(double dinheiro){
		this.dinheiro = dinheiro;
	}
	public int calcularDesconto(){
		return dinheiro - (dinheiro*0.10);
	}
}

public class circulo extends Clienteespecial{
	@Override
	super();
	public int CalcDesconto(double dinheiro){
		return dinheiro - (dinheiro*0.20));
	}
}

public class ClienteDesconto{
  public void DescontoFinal(Cliente dinheiro){
       Desconto.CalcDesconto();
  }

public class PrecoFinal {
	public static void main(String[] args){
		ClienteDesconto cliente = new ClienteDesconto();
		
		cliente.DescontoFinal(new Cliente());
		cliente.DescontoFinal(new Clienteespecial());
	}
}
