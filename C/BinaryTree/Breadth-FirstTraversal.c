/**
	"MostrarOrdemAltura" é a primeira função a ser chamada para mostrar
	os valores que estão na árvore, sendo necessário saber o tamanho da arvore,
	pela função, sendo uma função int há o retorno do tamanho da árvore
	sendo assim, em uma estrutura de repetição, a função "MostrarNivel"  
	verifica o elemento no nível em que está e passa para o proximo elemento no
	mesmo nível, ou no proximo nível caso já tenha sido apresentado os elementos
	do mesmo.
	Devido a estrutura de repetição de "MostrarOrdemAltura"
	onde é adquirida essa altura em "Altura", faz a chamada dos valores em
	"MostrarNivel", e assim atualizando o proximo endereço e avançando ná arvore
	de cima pra baixo, da esquerda pra direita.
**/
void MostrarOrdemAltura(Data **Valor){
    int h = Altura(Valor);
    for(int i = 1; i <= h; i++)
        MostrarNivel(Valor, i);
}

void MostrarNivel(Data **Valor, int Nivel){
    if (Valor == NULL)
        return 0;
    if (Nivel == 1)
        printf("%d ", Valor->data);
    else if (Nivel > 1)
    {
        MostrarNivel(Valor->left, Nivel-1);
        MostrarNivel(Valor->right, Nivel-1);
    }
}
 
int Altura(Data **node){
    if (node==NULL)
        return 0;
    else{
        int EAltura = Altura(node->left);
        int DAltura = Altura(node->right);
 
        if (EAltura > DAltura)
            return(EAltura+1);
        else 
			return(DAltura+1);
    }
}
