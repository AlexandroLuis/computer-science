EntityManagerFactory entityManagerFactory = Persistence.createEntityManagerFactory("Usuario");
EntityManager entityManager = entityManagerFactory.createEntityManager();
EntityManagerFactory entityManagerFactory = Persistence.createEntityManagerFactory("Turma");
EntityManager entityManager = entityManagerFactory.createEntityManager();
EntityManagerFactory entityManagerFactory = Persistence.createEntityManagerFactory("Jogo");
EntityManager entityManager = entityManagerFactory.createEntityManager();
EntityManagerFactory entityManagerFactory = Persistence.createEntityManagerFactory("Regra");
EntityManager entityManager = entityManagerFactory.createEntityManager();
EntityManagerFactory entityManagerFactory = Persistence.createEntityManagerFactory("Alternativa");
EntityManager entityManager = entityManagerFactory.createEntityManager();
EntityManagerFactory entityManagerFactory = Persistence.createEntityManagerFactory("Instituicao");
EntityManager entityManager = entityManagerFactory.createEntityManager();

@Entity
public class Usuario {
  @Id
  private int Id;
  private String Nome;
  private String Email;
  private String Senha;
  private String Tipo;
  @ManyToMany
  private List < Turma > turmas = new ArrayList < > ();
  @ManyToMany
  private List < Jogo > jogos = new ArrayList < > ();
}
@Entity
public class Alternativa {
  @Id
  private int Id;
  private String Perguntas;
  private String Alternativa1;
  private String Alternativa2;
  private String Alternativa3;
  private String Alternativa4;
  private String RespostaCerta;
  private int Etapa;
  private String Dica;
  @OneToMany(mappedBy = “jogo”)
  private Jogo jogo;
}
@Entity
public class Turma {
  @Id
  private int Id;
  private String Nome;
  @ManyToMany
  private List < Usuario > usuarios = new ArrayList < > ();
  @ManyToMany
  private List < Jogos > jogos = new ArrayList < > ();
  @OneToMany(mappedBy = “instituicao”)
  private Instituicao inst;
}
@Entity
public class Jogo {
  @Id
  private int Id;
  private String Nome;
  @ManyToMany
  private Usuario usuario;
  @ManyToMany
  private List < Usuario > participantes = new ArrayList < > ();
  @OneToMany(mappedBy = “jogo”)
  private List < Alternativa > alternativas = new ArrayList < > ();
  @OneToMany(mappedBy = “jogo”)
  private List < Regra > regras = new ArrayList < > ();
}
@Entity
public class Regra {
  @Id
  private int Id;
  private String Regra;
  private String PontoFase1;
  private String PontoFase2;
  private String PontoFase3;
  private Time TempoJogo;
  @OneToMany(mappedBy = “jogo”)
  private Jogo jogo;
}
@Entity
public class Instituicao {
  @Id
  private int Id;
  private String Instituicao;
  @OneToMany(mappedBy = “instituicao”)
  private List < Turma > Turmas = new ArrayList < > ();
}
