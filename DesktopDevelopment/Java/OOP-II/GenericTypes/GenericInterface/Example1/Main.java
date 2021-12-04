public class ClassA<T> implements Contencao<T> {
  T[] vetor1;

  ClassA(T[] o) {
	vetor1 = o;
  }
  // Implementa Contencao().
  public boolean contem(T o) {
	for (T x : vetor1)
		if (x.equals(o))
			return true;
		return false;
  }
}

public interface Contencao<T> {
	boolean contem(T o);
}
