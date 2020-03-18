public class ordem{
	public static void main(String[] args){
		double V1[] = new double [10];
		int S = G = D = 0, X = 3;
    int ma = b = me = ig = 0;
		for(int i = 0; i < V1.length; i++){
				V1[i] = ((3+i*3)-3); 
        if(V1[i] > X){
          ma++;
        }
        else if(V1[i] < X){
          me++;
        }
        else{
          ig++;
        }
		}
    System.out.println(ma);
    System.out.println(me);
    System.out.println(ig);
    
    b = 0;
    for(int i = 0; i < 9; i++){
        if(V1[i] < V1[i+1] || V[i] == V1[i+1])
         b += 0;
        else if(V1[i] > V1[i+1])
          b += 1;
        else
          b += 999; 
		}
    
    if(b == 0)
      System.out.println("crescente");
    else if(b == 9)
      System.out.println("decrescente);    
	  else
    System.out.println("aleatória");
  }
}
