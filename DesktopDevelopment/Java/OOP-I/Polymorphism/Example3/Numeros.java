public class Numeros {
	public static void main(String[] args){
		Numero numero = new Sum();
		
		numero.ShowNumero(new MaisDois()); //CHAMADA DO POLIMORFISMO
		numero.ShowNumero(new MaisTres());
	}
}