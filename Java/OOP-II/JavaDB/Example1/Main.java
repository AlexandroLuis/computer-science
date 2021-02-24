public class Main {
	public static void main(String[] args) {
		String url = "jdbc:postgresql://localhost:5432/MCH"; 
		String usuario = "postgres";
		String senha = "postgres"; 
		PreparedStatement statement;

		try{
			Connection connection = DriverManager.getConnection(url, usuario, senha); 
			String sql = "SELECT * FROM Estudante";
			statement = connection.prepareStatement(sql);
			ResultSet rs = statement.executeQuery();
			System.out.println("Preencha os dados do usuario com Id, Nome e idade!");
			while(rs.next()){
				int codigo = rs.getInt("estudanteId"); 
				String nome = rs.getString("nome"); 
				int idade = rs.getInt("idade"); 
				System.out.println(codigo + "\t" + nome + "\t" + idade);
			}
		}catch(SQLException exceptionatbaseconnection){
			System.out.println("Não Foi possível a Conexão pois " + exceptionatbaseconnection.toString());
		}
	}
}
