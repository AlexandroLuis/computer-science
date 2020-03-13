public class Mediadouble{
	public static void main(String[] args){
		double V1[] = new double [5];
		double S = 0;
		for(int i = 0; i < V1.length; i++){
				V1[i] = ((i*2)+5)/3;
				S += V1[i]; 
		}
		
		System.out.println(S);
	}
}
