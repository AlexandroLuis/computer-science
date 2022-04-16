import { Component, OnInit } from '@angular/core';
import { FormBuilder, FormGroup, Validators } from '@angular/forms';
import { Router } from '@angular/router';
import { timeStamp } from 'console';
import { UsuarioService } from 'src/app/services/usuario.service';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.scss']
})
export class LoginComponent implements OnInit {
  public formLogin: FormGroup;

  constructor(private router: Router, private formBuilder : FormBuilder, private usuarioService: UsuarioService) { 
    this.formLogin = this.formBuilder.group({
      email : ["", [Validators.required, Validators.email]],
      password: ["", [Validators.required]]
    })
  }

  ngOnInit(): void {
  }

  private validarFormulario() : void {
    for(let campos in this.formLogin.controls) {
      this.formLogin.controls[campos].markAllAsTouched();
    }
  }

  public submitForm() {
    this.validarFormulario();
    if(!this.formLogin.valid) {
      return;
    }
    this.logarComEmailPassword();
  }

  logarComEmailPassword(){
    this.usuarioService.loginComEmailPassword(
      this.formLogin.controls['email'].value, 
      this.formLogin.controls['password'].value
    )
      .then(()=>{
        alert("logou");
        this.router.navigate(["/listaDeProdutos"]);
      })
      .catch((error)=>{
        alert(error);
      })
  }

  logarComGoogleCount(){
    this.usuarioService.loginComGoogleCount()
    .then(()=>{
      alert("logou");
      this.router.navigate(["/listaDeProdutos"]);
    })
    .catch((error)=>{
      alert(error);
    })
  }



}
