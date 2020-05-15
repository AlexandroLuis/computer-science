public static void Palavra(){
	
	if(nome1.equals(nome2))
        System.out.println("Contas iguais");
	else
        System.out.println("Conta diferentes");
	
	if(nome1.equalsIgnoreCase(nome2))
		System.out.println("Contas iguais ignorando case");
	else
        System.out.println("Conta diferentes mesmo com case ignorada");
	
}

public class Nomes {
	public static void main(String[] args){
		Nome nome1 = new Nome("nome um");
		Nome nome2 = new Nome("nome dois");
		
		Palavra();
	}
}
