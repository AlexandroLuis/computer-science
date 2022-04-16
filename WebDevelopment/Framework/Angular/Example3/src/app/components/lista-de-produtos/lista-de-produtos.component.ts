import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { Produto } from 'src/app/models/produto';
import { ProdutoFirebaseService } from 'src/app/services/produto-firebase.service';
import { UsuarioService } from 'src/app/services/usuario.service';

@Component({
  selector: 'app-lista-de-produtos',
  templateUrl: './lista-de-produtos.component.html',
  styleUrls: ['./lista-de-produtos.component.scss']
})
export class ListaDeProdutosComponent implements OnInit {

  public lista_produtos : Produto[] = [];

  ngOnInit(): void {
   this.produtoService.getProdutos().subscribe(res =>{
    this.lista_produtos = res.map(e => {
      return{
        id : e.payload.doc.id,
        ...e.payload.doc.data() as Produto
      }as Produto;
    })
   })
  }
  constructor(private router: Router, private produtoService: ProdutoFirebaseService, private usuarioService: UsuarioService) {
    
  }
  public excluir(produto : Produto) : void {
    let resultado = confirm("Deseja excluir o produto: " + produto.nome + "?");
    if(resultado) {
      this.produtoService.deletarProduto(produto)
      .then(()=>{ alert("delete")})
      .catch (()=>{ alert("no delete")})
    }
  }

  public editar(produto : Produto) : void {
    this.router.navigate(['/editarProduto', produto.id])
  }
  public irParaCriarProduto() : void {
    this.router.navigate(['/criarProduto']);
  }

  public logout(){
    this.usuarioService.logout()
    .then(()=> {
      this.router.navigate(["/login"])
    })
    .catch(()=> { alert("erro") })
  }
}
