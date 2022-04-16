import { Component, OnInit } from '@angular/core';
import { FormGroup, FormBuilder, Validators } from '@angular/forms';
import { ActivatedRoute, Router } from '@angular/router';
import { Produto } from 'src/app/models/produto';
import { ProdutoFirebaseService } from 'src/app/services/produto-firebase.service';

@Component({
  selector: 'app-editar-produto',
  templateUrl: './editar-produto.component.html',
  styleUrls: ['./editar-produto.component.scss']
})
export class EditarProdutoComponent implements OnInit {
  public formEditar: FormGroup;
  public id: any;
  public lista_produtos : Produto[] = [];
  constructor(private router: Router, private actRoute: ActivatedRoute, private produtoService: ProdutoFirebaseService,private formBuilder : FormBuilder) { 
    this.formEditar = this.formBuilder.group({
      nome : ["", [Validators.required, Validators.minLength(5)]],
      preco: ["", [Validators.required]]
    })
  }

  ngOnInit(): void {
    this.actRoute.params.subscribe((parametros) => {
      if(parametros['indice']) {
        this.id = parametros['indice']
        this.produtoService.getProduto(parametros["indice"])
        .subscribe(res =>{
          let produtoRef : any = res;
          this.formEditar = this.formBuilder.group({
            nome : [produtoRef.nome, [Validators.required, Validators.minLength(5)]],
            preco: [produtoRef.preco, [Validators.required]]
          })
        })
      }
    });
  }
  public salvar() : void {
    this.produtoService.editarProduto(this.formEditar.value, this.id)
    .then(() => {
      this.router.navigate(["/listaDeProduto"])
    })
    .catch(() => {})
  }
  private validarFormulario() : void {
    for(let campos in this.formEditar.controls) {
      this.formEditar.controls[campos].markAllAsTouched();
    }
  }
  public submitForm() {
    this.validarFormulario();
    if(!this.formEditar.valid) {
      return;
    }
    this.salvar();
  }
}
