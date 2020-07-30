public class Iniciavetor{
	public static void main(String[] args){
		int V1[] = new int [5];
		
		for(int i = 0; i < V1.length; i++){
				V1[i] = (i*3)+5;
		}
		
		for(int i = 0; i < V1.length; i++){
			System.out.print("Valores = \t"+ V1[i]);
			System.out.println("");
		}
	}
}
