public class Cliente{
	private double dinheiro;
	public CalcDesconto(double dinheiro){
		this.dinheiro = dinheiro;
	}
	public int calcularDesconto(){
		return dinheiro - (dinheiro*0.10);
	}
}