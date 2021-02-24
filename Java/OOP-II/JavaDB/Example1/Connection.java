package Pack02748;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class Connection{
	public static void main(String[] args) {
		String url = "jdbc:postgresql://localhost:5432/MCH"; 
		String usuario = "postgres";
		String senha = "postgres";

		try{
			Connection connection = DriverManager.getConnection(url, usuario, senha); 
			System.out.println("Conexão Estabelecida!");
		}catch(SQLException exceptionatbaseconnection){
			System.out.println("Erro de Conexão: " + exceptionatbaseconnection.toString());
		}
	}
}
