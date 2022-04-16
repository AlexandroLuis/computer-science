import { Injectable } from '@angular/core';
import { AngularFirestore } from '@angular/fire/compat/firestore';
import { Produto } from '../models/produto';

@Injectable({
  providedIn: 'root'
})
export class ProdutoFirebaseService {
  private _PATH : string = "produtos"

  constructor(private angularFire : AngularFirestore) { }

  getProduto(id : string){
    return this.angularFire.collection(this._PATH).doc(id).valueChanges();
  }

  getProdutos(){
    return this.angularFire.collection(this._PATH).snapshotChanges();
  }

  criarProduto(produto : Produto){
    return this.angularFire.collection(this._PATH).add(produto);
  }

  deletarProduto(produto : Produto){
    return this.angularFire.collection(this._PATH).doc(produto.id).delete();
  }

  editarProduto(produto : Produto, id : string){
    return this.angularFire.collection(this._PATH).doc(id).update({
      nome: produto.nome,
      preco : produto.preco
    });
  }

}
