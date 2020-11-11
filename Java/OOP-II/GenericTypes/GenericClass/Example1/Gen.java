public class Gen<T> {
  private T ob; // declara uma refer�ncia a um objeto de tipo T

  public Gen(T o) {
    ob = o;
  }

  public T getOb() {
    return ob;
  }
  
  public void showTipos() {
	System.out.println("Tipo de T � " + ob.getClass().getName());  
  }
}
