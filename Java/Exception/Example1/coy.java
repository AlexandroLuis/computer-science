public class Contacorrente {
	private double saldo;
	
	protected double getTaxaOperacao() {
		return 0.3;
	}
	
	public void depositar(double Valor) 
		throws NegativeValueException{ 
			if(Valor < 1) 
				throw new NegativeValueException(Valor);{
					saldo += Valor;
				}	
		}
	
	public void saque(double Valor) 
		throws NegativeValueException, InsufficientFundsException{
			if(Valor < 1)
				throw new NegativeValueException(Valor);{
					Valor += Valor - (getTaxaOperacao() * Valor);
				}
			if(Valor > saldo)
				throw new InsufficientFundsException(Valor, saldo);{
					saldo -= Valor;
				}			
		}
		
	public double getSaldo(){
		return this.saldo;
	}
}

public class Contacorrenteespecial extends Contacorrente{ 
	@Override
	protected double getTaxaOperacao(){
		return 0.1;
	}
}

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

public class NegativeValueException extends Exception { 
	private double Valor;
	public NegativeValueException(double Valor){ 
		this.Valor = Valor;
	}
	
	public String toString() {
		return "valor Informado Negativo!" ;
	}
}

public class Main {
	public static void main(String[] args){ 
		Contacorrente conta = new Contacorrente();
		
		try{
			conta.depositar(1500);
			conta.depositar(-1);
		}catch(NegativeValueException ERRO1){
			System.out.println("Erro de " + ERRO1);
		}
		try{
			conta.saque(120);//Retorna
			conta.saque(2000);//Erro

		}catch(NegativeValueException | InsufficientFundsException ERRO1){ 
			System.out.println("Erro pois o "+ ERRO1);
		}
		System.out.println("Saldo Total R$: " + conta.getSaldo());
	}
}
