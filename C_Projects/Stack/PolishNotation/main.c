# include <stdio.h>
# include <stdlib.h>
#include "pilha_LE.h"

void transfereTempPos( Pilha **pPos, Pilha **pTemp, Pilha *aux ) {
    aux = ( *pTemp ) -> prox; //ponteiro auxiliar do tipo pilha guarda o link de pTemp
    ( *pTemp ) -> prox = *pPos; //pTemp passa a apontar para o endereço de pPos
    *pPos = *pTemp; //pPos recebe pTemp
    *pTemp = aux; //pTemp recebe aux que guarda o link de pTemp (anterior)
}
void leOperacao( Pilha **pPos, Pilha **pTemp ) {
    char op;
    Pilha *aux; //declara ponteiro auxiliar
    
    scanf( "%c", &op ); //lê uma operação
    while( op != '\n' ) {
        switch( op ) { //verifica a operação digitada
            case '+':
            case '-':

                while( ( *pTemp ) && ( (*pTemp) -> op != '(' ) ) {
                    transfereTempPos( &( *pPos ), &( *pTemp ), aux ); // caso não encontre uma abertura de parênteses chama a função para efetuar a transferência de infixa para pós fixa.
                }

                PUSH( &( *pTemp ), aux, op ); //apos encerrar o while insere o caracter na pilha pTemp;
                
                break;

            case '*':
            case '/':
	//trata prioridades multiplicação e divisão, caso não haja parênteses em nossa expressão
                while( ( *pTemp ) && ( (*pTemp) -> op != '+' && (*pTemp) -> op != '-'
                        && (*pTemp) -> op != '(' ) ) { 
                    		transfereTempPos( &( *pPos ), &( *pTemp ), aux ); //transfere infixa para pos fixa enviando como parâmetro a pilha pós fixa, a pilha temporaria e o ponteiro auxiliar
                }

                PUSH( &( *pTemp ), aux, op ); //insere na pilha temporária o carácter na pilha temporária.
                
                break;

            case ')':
            	//validando expressão quando há parênteses.
                while( ( *pTemp ) && ( (*pTemp) -> op != '(' ) ) {
                    transfereTempPos( &( *pPos ), &( *pTemp ), aux ); // se não encontrar uma abertura de parênteses o programa vai ignorar e transferir normalmente infixa para pós fixa;
                }

                if( (*pTemp) && (*pTemp) -> op == '(' ) { // caso encontre uma abertura de parênteses  irá excluir esse carácter da pilha temporária.
                    aux = *pTemp;
                    *pTemp = (*pTemp) -> prox;
                    free( aux );
                }
                
                break;

            case '(':
                PUSH( &( *pTemp ), aux, op );//caso seja um parênteses simplesmente irá inserir na pillha temporária.
                break;

            default:
                PUSH( &( *pPos ), aux, op ); // caso op não seja nenhuma das opções acima, será inserido normalmente na pilha pós fixa;
                break;
        }
        scanf( "%c", &op );
    }

    while( *pTemp ) {
        transfereTempPos( &( *pPos ), &( *pTemp ), aux ); //enquanto houver conteúdo em pTemp a transferencia da pilha temporária para a pilha PosFixa continuará;
    }
    
}
int main() {
    Pilha *pPos; //declara pilha Pós Fixa
    Pilha *pTemp; //declara pilha temporária
    inicializaPilha(&pPos); //inicializa pilha Pós Fixa
    inicializaPilha(&pTemp); //inicializa pilha temporária 
    printf( "Operacao Infixa: " );
    leOperacao( &pPos, &pTemp ); //chama a função leOperacao
    printf( "Operacao Posfixa: " );
    imprimePilha( pPos ); //imprime pilha pós fixa
    printf( "\n" );
    return 0;
}
