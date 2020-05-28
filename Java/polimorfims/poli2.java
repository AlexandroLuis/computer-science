public class CalcArea{
	private double area;
	public CalcArea(double area){
		this.area = area;
	}
	public int calcarea(){
		return area;
	}
}

public class circulo extends CalcArea{
	@Override
	super();
	public int calcarea(double area){
		return area*(3*(3.14*3.14));
	}
}

public class quadrado extends CalcArea{
	@Override
	super();
	public int calcarea(double area){
		return area*2;
	}
}

public class Figura{
  public void areatotal(Figura area){
       CalcArea.calcarea();
  }

public class TestaFigura {
	public static void main(String[] args){
		Figura figura = new Figura();
		
		figura.areatotal(new circulo());
		figura.areatotal(new quadrado());
		figura.areatotal(new circulo());
	}
}
