public class DoisGen<T>{
  T ob1;

  DoisGen(T o1) {
    ob1 = o1;
  }   
  public T getOb1() { 
    return ob1;
  }
  
  public void ShowType(){
    System.out.println(ob1.getClass().getName());
  }
}
