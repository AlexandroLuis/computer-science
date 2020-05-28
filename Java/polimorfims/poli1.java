public class Animal{
	public void emitirsom(){
		System.out.printf("Nha Nha Nha");
	}
}

public class Cachorro extends Animal{
	@Override
	public void emitirsom(){
		System.out.printf("Au Au Au");
	}
}

public class Gato extends Animal{
	@Override
	public void emitirsom(){
		System.out.printf("Miau Miau Miau");
	}
}

public class Preguica extends Animal{
	@Override
	public void emitirsom(){
		System.out.printf("AAAAAAHHHHZZZZ");
	}
}

public class Som{
  public void somdoanimal(Animal animal){
       animal.emitirsom();
  }

public class LojaApp {
	public static void main(String[] args){
		Som animal = new Som();
		
		animal.somdoanimal(new Cachorro());
		animal.somdoanimal(new Gato());
		animal.somdoanimal(new Preguica());
	}
}
