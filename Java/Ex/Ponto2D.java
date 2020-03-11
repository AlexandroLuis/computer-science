public class  Ponto2D{
	double x, y, mx = my = 0;
	int i = 0;
	
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
	
	public void mostrarxy(double x, double y){
		mx = x;
		my = y;
		
		System.out.printf("%0.2f\t", mx);
		System.out.printf("%0.2f\n", my);
	}
	
	public static int geti(){
		return i;
	}

}
