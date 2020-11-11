public class NegativeValueException extends Exception { 
	private double Valor;
	public NegativeValueException(double Valor){ 
		this.Valor = Valor;
	}
	
	public String toString() {
		return "valor Informado Negativo!" ;
	}
}
