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
