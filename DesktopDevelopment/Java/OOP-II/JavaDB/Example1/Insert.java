package Pack02748;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Insert{
	public static void main(String[] args) {
		String url = "jdbc:postgresql://localhost:5432/MCH"; 
		String usuario = "postgres";
		String senha = "postgres"; 
		PreparedStatement statement;

		try{
			Connection connection = DriverManager.getConnection(url, usuario, senha);
			String sql = "INSERT INTO Estudante (estudanteId, nome, idade) VALUES(?,?,?)"; 
			statement = connection.prepareStatement(sql); 
			statement.setInt(1, 1);
			statement.setString(2, "@&%#?");
			statement.setInt(3, 1232);
			statement.executeUpdate();
			connection.close();
		}catch (SQLException exceptionatbaseconnection){
			System.out.println("Erro Na Inserção: " + exceptionatbaseconnection.toString());
		}
	}
}
