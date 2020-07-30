public class Entrevistador {
	String idioma;
	public void entrevista(Falante f){
    	if(f instanceof Aluno){
    		System.out.println("Olá, Aluno!");
    	} 
    	else if (f instanceof Robo){
    		System.out.println("Olá, Robo");
    		Robo r = (Robo) f;
    		r.reboot();
    	}
    	//idioma = f.seuidioma();
    	f.falar();
    	System.out.println("Vou entrevistar você em " + idioma);
	}
}
