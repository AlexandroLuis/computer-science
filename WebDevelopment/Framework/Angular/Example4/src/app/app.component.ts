import { Component } from '@angular/core';
import { ImagemService } from './imagem.service';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent {
  title = 'Projeto';

  public lista_imagens? : any[];

  constructor(private imagemService : ImagemService){
    this.imagemService.getImages().subscribe((imagens) => {
      this.lista_imagens = imagens;
    })
  }

  uploadFile(event : any){
    const target = event.target as HTMLInputElement;
    const file : File = (target.files as FileList)[0];

    this.imagemService.uploadStorage(file)
    .then((data) => {
      // True
    })
    .catch((error) => {
      // False
    })
  }
}
