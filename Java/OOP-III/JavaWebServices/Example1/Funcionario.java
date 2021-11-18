@Entity
public class Funcionario implements Serializable {
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  private Integer id;
  private String nome;
  private Integer idade;
  private String departamento;
  private String cargo;
  public Funcionario() {
    super();
  }
  public Funcionario(Integer id, String nome, Integer idade, String departamento, String cargo) {
    super();
    this.id = id;
    this.nome = nome;
    this.idade = idade;
    this.departamento = departamento;
    this.cargo = cargo;
  }
  public Integer getId() {
    return id;
  }
  public void setId(Integer id) {
    this.id = id;
  }
  public String getNome() {
    return nome;
  }
  public void setNome(String nome) {
    this.nome = nome;
  }
  public Integer getIdade() {
    return idade;
  }
  public void setIdade(Integer idade) {
    this.idade = idade;
  }
  public String getDepartamento() {
    return departamento;
  }
  public void setDepartamento(String departamento) {
    this.departamento = departamento;
  }
  public String getCargo() {
    return cargo;
  }
  public void setCargo(String cargo) {
    this.cargo = cargo;
  }
}
