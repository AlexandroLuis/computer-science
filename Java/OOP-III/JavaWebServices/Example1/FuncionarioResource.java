@Repository
public interface FuncionarioRepository extends JpaRepository < Funcionario, Integer > {}
@RestController
@RequestMapping(value = "/fcn")
public class FuncionarioResource {
  @Autowired
  FuncionarioService fs;
  @GetMapping
  ResponseEntity < List < Funcionario >> read() {
    List < Funcionario > list = fs.read();
    return ResponseEntity.ok().body(list);
  }
  @PostMapping
  ResponseEntity < Funcionario > create(@RequestBody Funcionario funcionario) {
    Funcionario func = fs.create(funcionario);
    return ResponseEntity.ok().body(func);
  }
  @PutMapping(value = "/{id}")
  ResponseEntity < Void > update(@PathVariable Integer id, @RequestBody Funcionario funcionario) throws ObjectNotFoundException {
    fs.update(id, funcionario);
    return ResponseEntity.noContent().build();
  }
  @DeleteMapping(value = "/{id}")
  ResponseEntity < Void > delete(@PathVariable Integer id) throws
  ObjectNotFoundException {
    fs.delete(id);
    return ResponseEntity.noContent().build();
  }
}
