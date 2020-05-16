public static void Processar(variavel){
	
	if(variavel != NULL){
        return variavel.toUpperCase();
	}
	else
        return NULL;
	
	
}

public class Nomes {
	public static void main(String[] args){
		Processar variavel = new Processar("not null");
		
		Processar(variavel);
	}
}
