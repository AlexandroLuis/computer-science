public class FuncionarioService {
  @Autowired
  FuncionarioRepository fr;
  public Funcionario create(Funcionario funcionario) {
    return fr.save(funcionario);
  }
  public List < Funcionario > read() {
    List < Funcionario > funcionarios = fr.findAll();
    return funcionarios;
  }
  public Funcionario update(Integer id, Funcionario newFuncionario) throws
  ObjectNotFoundException {
    Optional < Funcionario > funcionario = fr.findById(id);
    if (funcionario == null) {
      throw new ObjectNotFoundException("Funcionário não encontrado! Id:
        " + funcionario.get().getId());
      }
      funcionario.get().setNome(newFuncionario.getNome());
      funcionario.get().setIdade(newFuncionario.getIdade());
      funcionario.get().setDepartamento(newFuncionario.getDepartamento());
      funcionario.get().setCargo(newFuncionario.getCargo());
      return fr.save(funcionario.get());
    }
      public void delete(Integer id) throws ObjectNotFoundException {
        Optional < Funcionario > funcionario = fr.findById(id);
        if (funcionario.get() == null) {
          throw new ObjectNotFoundException("Funcionário não encontrado! Id:" + funcionario.get().getId());
        }
        fr.deleteById(id);
      }
	}
