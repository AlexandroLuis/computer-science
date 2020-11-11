public class InsufficientFundsException extends Exception { 
	private double valor;
	private double saldo;
	
	public InsufficientFundsException(double valor, double saldo){ 
		this.valor = valor;
		this.saldo = saldo;
	}
	@Override
	public String toString(){
		return "seu saldo é insuficiente!";
	}
}
