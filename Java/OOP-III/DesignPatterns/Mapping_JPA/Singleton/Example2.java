EntityManagerFactory entityManagerFactory = Persistence.createEntityManagerFactory("Inquilino");
EntityManager entityManager = entityManagerFactory.createEntityManager();
EntityManagerFactory entityManagerFactory = Persistence.createEntityManagerFactory("Corretor");
EntityManager entityManager = entityManagerFactory.createEntityManager();
EntityManagerFactory entityManagerFactory = Persistence.createEntityManagerFactory("Proprietario");
EntityManager entityManager = entityManagerFactory.createEntityManager();
EntityManagerFactory entityManagerFactory = Persistence.createEntityManagerFactory("Imovel");
EntityManager entityManager = entityManagerFactory.createEntityManager();
EntityManagerFactory entityManagerFactory = Persistence.createEntityManagerFactory("Aluguel");
EntityManager entityManager = entityManagerFactory.createEntityManager();

@Entity
public class Inquilino {
  @Id
  private int CodInq;
  private String Nome;
  @OneToOne
  private Aluguel aluguel;
  @OneToOne
  private Imovel imovel;
  @OneToMany(mappedBy = “corretor”)
  private Corretor corr;
}
@Entity
public class Aluguel {
  @Id
  private int CodAlug;
  private int CodInq;
  private Date DataAlug;
  private Date DataVenc;
  private float ValorAlug;
  private int CodImov;
  private int CodCorr;
  @OneToOne
  private Inquilino inquilino;
  @OneToOne
  private Imovel imovel;
}
@Entity
public class Imovel {
  @Id
  private int CodImov;
  private String Descricao;
  private int CodProp;
  private float ValorAlug;
  private bool Alugado;
  @OneToOne
  private Inquilino inquilino;
  @OneToOne
  private Aluguel alug;
  @OneToMany(mappedBy = “proprietario”)
  private Proprietario prop;
}
@Entity
public class Proprietario {
  @Id
  private int CodProp;
  private String Nome;
  @OneToMany(mappedBy = “corretor”)
  private Corretor corr;
  @OneToMany(mappedBy = “proprietario”)
  private List < Imovel > Imoveis = new ArrayList < > ()
}
@Entity
public class Corretor {
  @Id
  private int CodCorr;
  private String Nome;
  @OneToMany(mappedBy = “corretor”)
  private List < Proprietario > Proprietarios = new ArrayList < > ()
  @OneToMany(mappedBy = “proprietario”)
  private List < Inquilino > Inquilinos = new ArrayList < > ()
}
