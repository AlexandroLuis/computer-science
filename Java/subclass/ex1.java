public class Retangulo extends TwoDShape {
 public String area;
 public boolean req() {
     if(largura == altura)
        return 1;
    else
        return 0;
 }
 public setarea(double largura, double altura){
	this.largura = largura;
	this.altura = altura;
 }
 public getarea(){
  return largura*altura;
 }
 public double area() {
 return (largura * altura);
 }
 public void mostraarea() {
 System.out.println("Retangulo = " + area);
 }
}
