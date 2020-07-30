public interface Falante{
	public void falar();
	public void seuidioma();	
}

public class Aluno implements Falante{
	public void falar(){
		System.out.println("Olá!");
	}
	public void seuidioma(){
		System.out.println("Português...");
	}
	public void identificarse(){
		System.out.println("Meu nome é");
	}
}

public class Robo implements Falante{
	public void falar(){
		System.out.println("Dominar a terra!");
	}
	public void seuidioma(){
		System.ou.println("Navajo");
	}
	public void reboot(){
		System.out.println("Reiniciando...");
	}
}

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

public class Main {
	public static void main(String[] args) {
		Falante f1,f2;
		
		f1 = new Aluno();
		f2 = new Robo();
		
		Entrevistador e = new Entrevistador();
		e.entrevista(f1);
		for(int i = 0; i < 27; i++)
		    System.out.printf("-");
		System.out.println("-");
		e.entrevista(f2);
	}
}
