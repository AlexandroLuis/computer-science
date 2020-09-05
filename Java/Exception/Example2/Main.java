public class Main {
	public static void main(String[] args) {
		try{
			throw new ExceptionC();
			}catch(ExceptionA exceptionA) {
				System.out.println(exceptionA);
		}
		try{
			throw new ExceptionB();
			}catch(ExceptionA exceptionA){ 
				System.out.println(exceptionA);
		}
	}
}
