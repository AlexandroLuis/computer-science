EntityManagerFactory entityManagerFactory = Persistence.createEntityManagerFactory("Character");
EntityManager entityManager = entityManagerFactory.createEntityManager();
EntityManagerFactory entityManagerFactory = Persistence.createEntityManagerFactory("Account");
EntityManager entityManager = entityManagerFactory.createEntityManager();
EntityManagerFactory entityManagerFactory = Persistence.createEntityManagerFactory("Region");
EntityManager entityManager = entityManagerFactory.createEntityManager();
EntityManagerFactory entityManagerFactory = Persistence.createEntityManagerFactory("Creep");
EntityManager entityManager = entityManagerFactory.createEntityManager();
EntityManagerFactory entityManagerFactory = Persistence.createEntityManagerFactory("Item");
EntityManager entityManager = entityManagerFactory.createEntityManager();
EntityManagerFactory entityManagerFactory = Persistence.createEntityManagerFactory("CreepInstantiation");
EntityManager entityManager = entityManagerFactory.createEntityManager();
EntityManagerFactory entityManagerFactory = Persistence.createEntityManagerFactory("ItemInstantiation");
EntityManager entityManager = entityManagerFactory.createEntityManager();

//Singleton
@Entity
public class Character {
  @Id
  private String CharName;
  private int level;
  private int ExpPoints;
  private int MaxHitPoints;
  private int CurrHitPoints;
  private int MaxMana;
  private int CurrMana;
  @OneToMany(mappedBy = "account")
  private Account Dono;
  @OneToMany(mappedBy = “character”)
  private List < ItemInstantiation > Carrying = new ArrayList < > ();
}

@Entity
public class Region {
  @Id
  private String RegionName;
  private String Climate;
  private String Precipitation;
  //Singleton
  private String Foliage;
  @OneToMany(mappedBy = "region")
  private List < Character > PlayersIn = new ArrayList < > ();
  @OneToMany(mappedBy = “region”)
  private List < CreepInstantiation > IsType = new ArrayList < > ();
}

@Entity
public class Account {
  @Id
  private String AcctName;
  private String Password;
  private String LastSignedOn;
  private String SbscrbrName;
  private String SbscrbrAddress;
  private String SbscrbrEMail;
  private String SbscrbrPhone;
  private Date AcctCreatedOn;
  @OneToMany(mappedBy = "account")
  private List < Character > Chars = new ArrayList < > ();
}

@Entity
public class Creep {
  @Id
  private String CreepName;
  private String HitPoints;
  private String Mana;
  private String Attack;
  @ManyToMany
  private List < Character > RanInto = new ArrayList < > ();
  @OneToMany(mappedBy = “creep”)
  private List < CreepInstantiation > IsType = new ArrayList < > ();
}

//Singleton
@Entity
public class CreepInstantiation {
  @Id
  private int IDNum;
  @OneToMany(mappedBy = “creep”)
  private Creep creep;
  @OneToMany(mappedBy = “region”)
  private Region region;
  @OneToMany(mappedBy = “creepinstantiation”)
  private List < ItemInstantiation > Carrying = new ArrayList < > ();
}

//Singleton
@Entity
public class ItemInstantiation {
  @Id
  private int IDNum;
  private String modifier;
  @OneToMany(mappedBy = “item”)
  private Item IsType;
  @OneToMany(mappedBy = “creepinstantiation”)
  private List < CreepInstantiation > Carrying2 = new ArrayList < > ();
  @OneToMany(mappedBy = “character”)
  private List < Character > Carrying = new ArrayList < > ();
}

@Entity
public class Item {
  @Id
  private String ItemName;
  private String ItemType;
  private int ItemDamage;
  @OneToMany(mappedBy = “item”)
  private List < ItemInstantiation > IsType = new ArrayList < > ();
}
