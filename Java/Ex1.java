public class conta{		// atributos private
	private int saldo;
	private String tipo;
	
	public conta(){		// construtor
	}
	public conta(double saldo1, String tipo1){
		saldo = saldo1;
		tipo = tipo1;
	}
	
	public void setsaldo(double saldo1){ // método modificador 
		saldo = saldo1;
	}
	
	public void settipo(String tipo1){
		tipo = tipo1;
	}
	
	public double getSaldo(){ // metodo de acesso 
		return saldo;
	}

	public void exibe(){		// metodos public
		System.ou.println(conta+" "+saldo);
	}
}

public class usarconta{
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
