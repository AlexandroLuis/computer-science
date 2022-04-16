export class Produto {
    id? : string;
    nome?: string;
    preco?: number;
    

    constructor(nome:string, preco:number) {
        this.nome = nome;
        this.preco = preco;
    }
    
}
