public static void Palavra(){
	private palavra = new String[];
	private int soma = 0;
	
	if(frase.length < 8){
		for (int i = 0; i < frase.length; i++){
			if(i == 1 || i == 2 || i == ((frase.length) -1) || i == ((frase.length) -2))
				palavra[i] = frase.length - (frase.length - 1);
		}
		for (int i = 0; i < 4; i++)
			System.out.println("Nova palavras = " + palavra[i]);
	}
	else
		System.out.println("erro");
	}
}