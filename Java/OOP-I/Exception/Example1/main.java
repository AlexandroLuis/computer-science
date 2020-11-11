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
