public class conta{		// atributos private
	private double saldo;
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
	
	public double getsaldo(){ // metodo de acesso 
		return saldo;
	}

	public void exibe(){		// metodos public
		System.ou.println(saldo+" "+tipo);
	}
}
