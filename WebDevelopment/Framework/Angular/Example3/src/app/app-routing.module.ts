import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { CadastroComponent } from './components/cadastro/cadastro.component';
import { CriarProdutoComponent } from './components/criar-produto/criar-produto.component';
import { EditarProdutoComponent } from './components/editar-produto/editar-produto.component';
import { ListaDeProdutosComponent } from './components/lista-de-produtos/lista-de-produtos.component';
import { LoginComponent } from './components/login/login.component';
import { UsuarioGuard } from './services/usuario.guard';

const routes: Routes = [
  {path: 'login',component: LoginComponent},
  {path: 'cadastro',component: CadastroComponent},
  {path: 'listaDeProdutos', component: ListaDeProdutosComponent, canActivate : [UsuarioGuard]},
  {path: 'criarProduto',component: CriarProdutoComponent, canActivate : [UsuarioGuard]},
  {path: 'editarProduto/:indice', component: EditarProdutoComponent, canActivate : [UsuarioGuard]},
  {path: '**', redirectTo: '/login'},
  {path: '', redirectTo: '/login', pathMatch:'full'}
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
