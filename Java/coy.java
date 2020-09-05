public class ExcecaoA extends Exception {
	@Override
	public String toString() {
		return "Exceção A";
	}
}

public class ExceptionB extends ExceptionA { 
	@Override
	public String toString() {
		return "Exceção B";
	}
}

public class ExceptionC extends ExceptionB {
	@Override
	public String toString() {
		return "Exceção C";
	}
}

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
