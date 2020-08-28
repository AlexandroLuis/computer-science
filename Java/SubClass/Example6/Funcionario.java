public class Funcionario extends Pessoa{
    private double salario;
    
    public Funcionario(String nome, double salario){
      super(nome);
      this.salario = 1000.20;
    }
	public void getSalario(){
		System.out.println(salario);
	}
  public String getnome(){
		return nome;
	}
	public double Reajuste(){
		return salario + (salario * 0.10);
  }
}
