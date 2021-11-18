@Entity
public class Funcionario {
  private String nome;
  private Integer idade;
  private String departamento;
  private String cargo;
  public String getNome() {
    return nome;
  }
  public void setNome(int nome) {
    this.nome = nome;
  }
  public Integer getIdade() {
    return idade;
  }
  public void setIdade(int idade) {
    this.idade = idade;
  }
  public String getDepartamento() {
    return departamento;
  }
  public void setDepartamento(int departamento) {
    this.nome = departamento;
  }
  public Integer getCargo() {
    return cargo;
  }
  public void setCargo(int cargo) {
    this.cargo = cargo;
  }
  @PostConstruct
  public void init() {
    FuncionarioListFromDB = DatabaseOperation.getFuncionarioListFromDB();
  }
  public ArrayList FuncionarioList() {
    return funcionarioListFromDB;
  }
  public String saveFuncionarioDetails(FuncionarioBean newFuncionarioObj) {
    return DatabaseOperation.saveFuncionarioDetailsInDB(newFuncionarioObj);
  }
  public String editFuncionarioRecord(int funcionariotId) {
    return DatabaseOperation.editFuncionarioRecordInDB(funcionarioId);
  }
  public String updateFuncionarioDetails(FuncionarioBean updateFuncionarioObj) {
    return DatabaseOperation.updateFuncionarioDetailsInDB(updateFuncionarioObj);
  }
  public String deleteFuncionarioRecord(int funcionarioId) {
    return DatabaseOperation.deleteFuncionarioRecordInDB(funcionarioId);
  }
}

package com.jsf.crud.db.operations;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.Map;
import javax.faces.context.FacesContext;
import com.jsf.crud.FuncionarioBean;
public class DatabaseOperation {
  public static Statement stmtObj;
  public static Connection connObj;
  public static ResultSet resultSetObj;
  public static PreparedStatement pstmt;
  public static Connection getConnection() {
    try {
      Class.forName("com.mysql.jdbc.Driver");
      String db_url = "jdbc:mysql://localhost:4004/ListaFuncionarios",
        db_userName = "root",
        db_password = "";
      connObj = DriverManager.getConnection(db_url, db_userName, db_password);
    } catch (Exception sqlException) {
      sqlException.printStackTrace();
    }
    return connObj;
  }
  public static ArrayList getListaFuncionariosFromDB() {
    ArrayList ListaFuncionarios = new ArrayList();
    try {
      stmtObj = getConnection().createStatement();
      resultSetObj = stmtObj.executeQuery("select * from funcionario_record");
      while (resultSetObj.next()) {
        FuncionarioBean stuObj = new FuncionarioBean();
        stuObj.setNome(resultSetObj.getString("funcionario_nome"));
        stuObj.setIdade(resultSetObj.getInteger("funcionario_idade"));
        stuObj.setDepartamento(resultSetObj.getString("funcionario_departamento"));
        stuObj.setCargo(resultSetObj.getString("funcionario_cargo"));
        ListaFuncionarios.add(stuObj);
      }
      System.out.println("Total Records Fetched: " + ListaFuncionarios.size());
      connObj.close();
    } catch (Exception sqlException) {
      sqlException.printStackTrace();
    }
    return ListaFuncionarios;
  }
  public static String saveFuncionarioDetailsInDB(FuncionarioBean newFuncionarioObj) {
      int saveResult = 0;
      String navigationResult = "";
      try {
        pstmt = getConnection().prepareStatement("insert into funcionario_record
          (funcionario_nome, funcionario_idade, funcionario_departamento, funcionario_cargo) values( ? , ? , ? , ? )
          ");
          pstmt.setString(1, newFuncionarioObj.getNome()); pstmt.setInteger(2, newFuncionarioObj.getIdade()); pstmt.setString(3, newFuncionarioObj.getDepartamento()); pstmt.setString(4, newFuncionarioObj.getCargo()); saveResult = pstmt.executeUpdate(); connObj.close();
        }
        catch (Exception sqlException) {
          sqlException.printStackTrace();
        }
        if (saveResult != 0) {
          navigationResult = "ListaFuncionarios.xhtml?faces-redirect=true";
        } else {
          navigationResult = "createFuncionario.xhtml?faces-redirect=true";
        }
        return navigationResult;
      }
      public static String editFuncionarioRecordInDB(int funcionarioId) {
          FuncionarioBean editRecord = null;
          System.out.println("editFuncionarioRecordInDB() : Funcionario Id: " + funcionarioId);
          Map < String, Object > sessionMapObj =
            FacesContext.getCurrentInstance().getExternalContext().getSessionMap();
          try {
            stmtObj = getConnection().createStatement();
            resultSetObj = stmtObj.executeQuery("select * from funcionario_record where
              funcionario_id = "+funcionarioId);
              if (resultSetObj != null) {
                resultSetObj.next();
                editRecord = new FuncionarioBean();
                editRecord.setName(resultSetObj.getString("funcionario_name"));
                editRecord.setIdade(resultSetObj.getString("funcionario_idade"));
                editRecord.setDepartamento(resultSetObj.getString("funcionario_departamento"));
                editRecord.setCargo(resultSetObj.getString("funcionario_cargo"));
              }
              sessionMapObj.put("editRecordObj", editRecord); connObj.close();
            }
            catch (Exception sqlException) {
              sqlException.printStackTrace();
            }
            return "/editFuncionario.xhtml?faces-redirect=true";
          }
          public static String updateFuncionarioDetailsInDB(FuncionarioBean updateFuncionarioObj) {
              try {
                pstmt = getConnection().prepareStatement("update funcionario_record set
                  funcionario_name = ? , funcionario_idade = ? , funcionario_departamento = ? ,
                  funcionario_cargo = ? ");
                  pstmt.setString(1, updateFuncionarioObj.getNome()); pstmt.setInt(2, updateFuncionarioObj.getIdadel()); pstmt.setString(3, updateFuncionarioObj.getDepartamento()); pstmt.setString(4, updateFuncionarioObj.getCargo()); pstmt.executeUpdate(); connObj.close();
                }
                catch (Exception sqlException) {
                  sqlException.printStackTrace();
                }
                return "/ListaFuncionarios.xhtml?faces-redirect=true";
              }
              public static String deleteFuncionarioRecordInDB(int funcionario_nome) {
                  System.out.println("deleteFuncionarioRecordInDB() : + funcionario_nome);
                    try {
                      pstmt = getConnection().prepareStatement("delete from funcionario_record where
                        funcionarionome = ");
                        pstmt.executeUpdate(); connObj.close();
                      }
                      catch (Exception sqlException) {
                        sqlException.printStackTrace();
                      }
                      return "/ListaFuncionarios.xhtml?faces-redirect=true";
                    }
                  }
