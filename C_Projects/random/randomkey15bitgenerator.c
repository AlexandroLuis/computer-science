#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int Linha = 17;
    int A[Linha];
    int i, j, k, c = 0;

    for(i = 0; i < Linha; i++)
        A[i] = 0;

    for(i = 0; i < Linha; i++){
        for(j = 0; j < 36; j++){
            if(j < 10){
                A[i] = j;
                for(k = 0; k < Linha; k++){
                    if(k == 5 || k == 11)
                        printf("-");
                    else
                        (A[k]<10)?printf("%d", A[k]):printf("%c", A[k]);
                }
                printf("\n\n");
            }
            else if(j > 9 && j < 10){
                A[i] = 65;
                for(k = 0; k < Linha; k++){
                    if(k == 5 || k == 11)
                        printf("-");
                    else
                        (A[k]<10)?printf("%d", A[k]):printf("%c", A[k]);
                }
                printf("\n\n");
            }
            else{
                A[i] = 55+j;
                for(k = 0; k < Linha; k++){
                    if(k == 5 || k == 11)
                        printf("-");
                    else
                        (A[k]<10)?printf("%d", A[k]):printf("%c", A[k]);
                }
                printf("\n\n");
            }
            c++;
        }
    }
    printf("\nChaves Geradas : %d", c);
}
