package collectionsI;
import java.util.ArrayList;

public class Main {
	public static void main(String[] args) {
		ArrayList<ContaBanco> conta = new ArrayList<>();
		conta.add(new ContaBanco(1, 1000));
		conta.add(new ContaBanco(2, 2000));
		conta.add(new ContaBanco(3, 0));
		
		System.out.println("Total de contas: " + contas.size());
		double valor = 3;
		for(ContaBanco c : conta) {
			if(c.getSaldo() == 0) {
				c.deposito(300);
			} else {
				c.deposito(valor);
				c.saque(100);
			}
			valor+=10;
		}
		System.out.println(contas);
		contas.remove(0);
		System.out.println("Total de contas: " + contas.size());
		System.out.println(contas);
		System.out.println("1° Conta registrada: " + contas.get(0));
		System.out.println("Última conta registrada: " + contas.get(contas.size() - 1));	
	}
}
