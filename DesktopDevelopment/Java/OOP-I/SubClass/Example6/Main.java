public class Main{
	public static void main(String[] args){
		Funcionario funcionario1 = new Funcionario("nome1", 7850);

		System.out.println(funcionario1.getnome());
		funcionario1.getSalario();
		System.out.println(funcionario1.getnome());
    System.out.println(funcionario1.Reajuste());
	}
}
