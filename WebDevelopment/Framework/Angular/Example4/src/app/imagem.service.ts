import { Injectable } from '@angular/core';
import { AngularFireDatabase } from '@angular/fire/compat/database';
import { AngularFireStorage, AngularFireUploadTask } from '@angular/fire/compat/storage';
import { Observable } from 'rxjs';
import { map, finalize } from 'rxjs/operators';

export class MyData{
  name? : string;
  downloadURL? : string;
}

@Injectable({
  providedIn: 'root'
})
export class ImagemService {
  task? : AngularFireUploadTask;
  UploadedFile? : Observable<string>;
  fileName? : string;

  constructor(private storage : AngularFireStorage, private db : AngularFireDatabase) { }

  async uploadStorage(file : File){
    if(file.type.split('/')[0] != "image")
      return;

    this.fileName = file.name;
    const path = `imagens/${new Date().getTime()}_${file.name}`;
    const fileRef = this.storage.ref(path);
    this.task = this.storage.upload(path, file);

    this.task.snapshotChanges().pipe(
      finalize(() => {
        this.UploadedFile = fileRef.getDownloadURL();
        this.UploadedFile.subscribe((resp) => {
          this.uploadDatabase({
            name : file.name,
            downloadURL : resp
          });
        });
      })).subscribe()
  }

  uploadDatabase(image : MyData){
    return this.db.database.ref("imagens").push(image)
    .then((resp) => {
      //true;
    })
    .catch((error) => {
      //false;
    })
  }

  getImages(){
    return this.db.list("imagens").snapshotChanges().pipe(
      map((action) => {
        return action.map((dados) => ({
          key : dados.payload.key,
          data : dados.payload.val()
        }))
      })
    )
  }

}
