public class  Ponto2D{
	private double x, y;
	static int i = 0;
	
	public Ponto2D(){
		x = y = 0;
		i++;
	}
	
	public Ponto2D(double x, double y){
		this.x = 0;
		this.y = 0;
		i++;
	}
	
	public double getx(){
		return x;
	}
	
	public double gety(){
		return y;
	}
	
	public void mostrarxy(){
		System.out.printf("%f\t", x);
		System.out.printf("%.2f\n", y);
	}
	
	public static int geti(){
		return i;
	}
}
