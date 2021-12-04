//Entidade Escohida:
@Entity
public class Inquilino {
  @Id
  @GeneratedValue(strategy = GenerationType.IDENTITY)
  private Integer codInq;
  private String nome;
  @OneToMany(mappedBy = ”inquilino”)
  private List < Inquilino > inquilinos = new ArrayList < > ();
  @OneToMany(mappedBy = ”codInq”)
  private List < Aluguel > alugueis = new ArrayList < > ();
}

//Querie
public Inquilino Querie(Integer id) {
    Query jpqlQuery = getEntityManager().createQuery("SELECT i FROM Inquilino i WHERE
      i.codInq =: id ");
      jpqlQuery.setParameter("id", id);
      return (Inquilino) jpqlQuery.getSingleResult();
    }
    //Querie Nomeada
    public Inquilino QuerieNomeada(Integer id) {
      Query namedQuery = getEntityManager().createNamedQuery("Inquilino.findByUserId");
      namedQuery.setParameter("codInq", id);
      return (Inquilino) namedQuery.getSingleResult();
    }
    //Querie Criteria
    public UserEntity QuerieCriteria(Integer id) {
      CriteriaBuilder criteriaBuilder = getEntityManager().getCriteriaBuilder();
      CriteriaQuery < Inquilino > criteriaQuery = criteriaBuilder.createQuery(Inquilino.class);
      Root < Inquilino > userRoot = criteriaQuery.from(Inquilino.class);
      Inquilino queryResult = getEntityManager().createQuery(
		criteriaQuery.select(userRoot).where(
			criteriaBuilder.equal(userRoot.get("id"), id)
			)
		).getSingleResult();
      return queryResult;
    }
