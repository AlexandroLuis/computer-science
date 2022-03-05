import { Component } from '@angular/core';
import { Produto } from './models/produto';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent {
  public lista_produtos : Produto[] = [];
  public nome : string| undefined;
  public preco : number | undefined;
  public edicao : boolean = false;
  public indice : number = -1;

  constructor(){
    this.lista_produtos.push(new Produto("Camiseta", 30));
    this.lista_produtos.push(new Produto("Calça", 70));
  }

  public salvar(){
    if(!this.nome || !this.preco)
      return;
    else{
      if(this.indice == -1){
        this.lista_produtos.push(new Produto(this.nome, this.preco));
        this.nome = undefined;
        this.preco = undefined;
      }
      else{
         this.lista_produtos[this.indice].setNome(this.nome);
         this.lista_produtos[this.indice].setPreco(this.preco);
         this.edicao = false;
         this.indice = -1;
      }
    }
  }
  
  public excluir(index : number){
    this.lista_produtos.splice(index, 1);

  }

  public editar(index : number) : void{
    this.edicao = true;
    this.nome = this.lista_produtos[index].getNome();
    this.preco = this.lista_produtos[index].getPreco();
    this.indice = index;
    this.salvar();
  }
}
