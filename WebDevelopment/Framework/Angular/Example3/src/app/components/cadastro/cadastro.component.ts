import { Component, OnInit } from '@angular/core';
import { FormBuilder, FormGroup, Validators } from '@angular/forms';
import { Router } from '@angular/router';
import { UsuarioService } from 'src/app/services/usuario.service';

@Component({
  selector: 'app-cadastro',
  templateUrl: './cadastro.component.html',
  styleUrls: ['./cadastro.component.scss']
})
export class CadastroComponent implements OnInit {
  public formCadastrar: FormGroup;

  constructor(private router: Router, private formBuilder : FormBuilder, private usuarioService: UsuarioService) { 
    this.formCadastrar = this.formBuilder.group({
      email : ["", [Validators.required, Validators.email]],
      password: ["", [Validators.required]],
      confirmPassword: ["", [Validators.required]]
    });
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
    this.cadastrar();
  }

  cadastrar() {
    if(this.formCadastrar.controls['password'].value == this.formCadastrar.controls['confirmPassword'].value){
      this.usuarioService.cadastrarComEmailPassword(
        this.formCadastrar.controls['email'].value, 
        this.formCadastrar.controls['password'].value
      )
      .then(()=>{
        alert("Cadastrou");
        this.router.navigate(["/login"]);
      })
      .catch((error)=>{
        alert(error);
      })
    }else { alert("erro"); }
  }
}