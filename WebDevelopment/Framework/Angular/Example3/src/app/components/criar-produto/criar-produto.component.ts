import { Component, OnInit } from '@angular/core';
import { FormBuilder, FormGroup, Validators } from '@angular/forms';
import { Router } from '@angular/router';
import { ProdutoFirebaseService } from 'src/app/services/produto-firebase.service';

@Component({
  selector: 'app-criar-produto',
  templateUrl: './criar-produto.component.html',
  styleUrls: ['./criar-produto.component.scss']
})
export class CriarProdutoComponent implements OnInit {
  public formCadastrar: FormGroup;
  constructor(private router: Router, private produtoService: ProdutoFirebaseService, private formBuilder : FormBuilder) { 
    this.formCadastrar = this.formBuilder.group({
      nome : ["", [Validators.required, Validators.minLength(5)]],
      preco: ["", [Validators.required]]
    })
  }

  ngOnInit(): void {
  }
  private validarFormulario() : void {
    for(let campos in this.formCadastrar.controls) {
      this.formCadastrar.controls[campos].markAllAsTouched();
    }
  }
  public submitForm() {
    this.validarFormulario();
    if(!this.formCadastrar.valid) {
      return;
    }
    this.salvar();
  }
  public salvar() : void {
    this.produtoService.criarProduto(this.formCadastrar.value)
    .then(()=>{
      this.router.navigate(["/listaDeProdutos"])
    })
    .catch((error)=>{
      console.log(error)
    })
  }
}
