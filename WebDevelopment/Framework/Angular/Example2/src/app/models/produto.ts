export class Produto {
    private _nome : string;
    private _preco : number;

    constructor (nome : string, preco : number){
        this._nome = nome;
        this._preco = preco;
    }
    public getNome() : string{
        return this._nome;
    }
    public getPreco() : number{
        return this._preco;
    }
    public setNome(nome: string) : void{
        this._nome = nome;
    }
    public setPreco(preco : number) : void{
        this._preco = preco;
    }
}
