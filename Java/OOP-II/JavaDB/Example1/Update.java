package Pack02748;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Update{
	public static void main(String[] args) {
		String url = "jdbc:postgresql://localhost:5432/MCH"; 
		String usuario = "postgres";
		String senha = "postgres"; 
		PreparedStatement statement;

		try{
			Connection connection = DriverManager.getConnection(url, usuario, senha); 
			String sql = "UPDATE Estudante SET nome = ? WHERE estudanteId = ?"; 
			statement = connection.prepareStatement(sql); 
			statement.setString(1, "@&%#?"); 
			statement.setInt(2, 1);
			statement.executeUpdate();
			connection.close();
		}catch(SQLException exceptionatbaseconnection){
			System.out.println("Não Foi Possivel receber dados para atualizar pois " + exceptionatbaseconnection.toString());
		}
	}
}
