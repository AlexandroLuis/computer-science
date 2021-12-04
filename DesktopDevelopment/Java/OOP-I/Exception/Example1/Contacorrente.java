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
