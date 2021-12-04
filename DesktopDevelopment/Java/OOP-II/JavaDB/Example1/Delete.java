package Pack02748;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class Delete {
	public static void main(String[] args) {
		String url = "jdbc:postgresql://localhost:5432/MCH"; 
		String usuario = "postgres";
		String senha = "postgres"; 
		PreparedStatement statement;

		try {
			Connection connection = DriverManager.getConnection(url, usuario, senha); 
			String sql = "DELETE FROM Estudante WHERE estudanteId = ?";
			statement = connection.prepareStatement(sql);
			statement.setInt(1, 2);
			statement.executeUpdate();
			connection.close();
		}catch (SQLException exceptionatbaseconnection) {
			System.out.println("Erro na exclusão pois " + exceptionatbaseconnection.toString());
		}
	}
}
