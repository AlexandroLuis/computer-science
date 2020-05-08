public class Retangulo extends TwoDShape {
 public String area;
 public boolean req() {
     if(largura == altura)
        return 1;
    else
        return 0;
 }
 public double area() {
 return (largura * altura);
 }
 public void mostraarea() {
 System.out.println("Retangulo = " + area);
 }
}
