#include <stdio.h>
#include <stdlib.h>

int main()
{
    int P, G, i, j, B = 0, V;
    int soma, maior, piloto, pos, cand2;

    scanf("%d %d", &G, &P);
    while(P != 0 && G != 0)
    {
        piloto = cand2 = maior = 0;
        scanf("%d %d", &G, &P);
        int M[P][2];

        for(i = 0; i < P; i++){
            for(j = 0; j < 2; j++){
                M[i][j] = 0;
            }
        }

        for(i = 0; i < P; i++)
        {
            scanf("%d", &pos);
            M[i][0] = pos;
        }

        scanf("%d", &V);
        for(i = 0; i < V; i++)
        {
            scanf("%d", &B);
            for(j = 0; j < B; j++)
            {
                scanf("%d", &soma);
                M[i][1] += soma;
            }
        }
        for(i = 0; i < P; i++)
        {
            if(M[i][1] > maior)
            {
                piloto = i;
                maior = M[i][1];
            }
            else if(M[i][1] == maior)
            {
                cand2 = i;

            }
        }
        if(cand2 == 0)
            printf("%d\n", M[piloto][0]);
        else{
            printf("%d %d",M[piloto][0], M[cand2][0]);
        }

    }
}
