public class novo{
	public static void main(String[] args){
		conta conta1 = new conta();
		
		conta1.setsaldo = 100.00;
		conta1.settipo="corrente";
		System.out.println("saldo : " +conta1.getsaldo());
		conta1.exibe();
		
		conta2 = new conta(200.00, "corrente");
		conta2.exibe();
	}
}
