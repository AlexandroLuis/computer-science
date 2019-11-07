#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#define T 6
int MAPA[T][T],c[T][T];
int L = 0, Ganhador;
int Player2[]= {0,0,0,0};
char Player[4][20];
int m1 = 0, m2 = 0, m3 = 0, m4 = 0, m5 = 0;


void randval() // FUNÇÃO CUJO ALEATORIZA OS VALORES DO VETOR DE 1 ATÉ 10
{
    int i, j, C;
    int V = 0, V2 = 0;

    for(i = 0; i < T; i++)
    {
        for(j = 0; j < T; j++)
        {
            MAPA[i][j] = rand () % 16;
            c[i][j] = '~';
        }
    }

    for(i = 1; i <= T; i++)
    {
        C = 0;
        while(C < 2)
        {
            V  = rand () % 5;
            V2 = rand () % 5;
            MAPA[V][V2] = i+10;
            C++;
        }

    }
}

void Player3() // FUNÇÃO CUJO "PRINTA"  INFOS, COMO PLACAR E MAPA
{
    int j, k, l, m;


    for(j = 0; j< L; j++)// NOME E PONTOS DO JOGADOR
    {
        printf("|Nome: %s |Pontos: %d|\n",Player[j], Player2[j]);
    }

    printf("\nMAPA:\n\t"); // ESCREVE "MAPA" NO PLANO

    for(k = 65; k < 71; k++)// EM HEXADECIMAL MOSTRA AS COLUNAS DE A ATÉ F
    {
        printf("%c\t", k);
    }

    printf("\n\n");

    for(l = 0; l < T; l++) // MOSTRA O MAPA E SEU VALOR, CASO NÃO USADO 0 "~", CASO USADO "X"
    {
        printf("%d\t", (l+1));
        for(m = 0; m < T; m++)
        {
            printf("%c\t",c[l][m]);
        }
        printf("\n");
    }
}

void Player4() // FUNÇÃO CUJO CALCULA JOGADAS
{
    int o;
    int LINHAC = 0, soma = 0;
    char COLUNA;

    for(o = 0; o < L; o++)
    {
        do
        {
            printf("\nTurno do(a) %s", Player[o]);
            printf("\n\nDigite a coluna : ");
            fflush(stdin);
            scanf("%c", &COLUNA);
            soma = COLUNA - 65;
            printf("Digite a linha  : ");
            scanf("%d", &LINHAC);
        }
        while(c[LINHAC-1][soma] != '~');

        if((MAPA[LINHAC][soma] == 11) && (m1 < 2))
        {
            Player2[o] -= 10;
            c[LINHAC-1][soma] = 'O';
            m1++;
        }
        else
        {
            if((MAPA[LINHAC][soma] == 12) && (m2 < 2))
            {
                Player2[o] += 10;
                c[LINHAC-1][soma] = '+';
                m2++;
                system("cls");
            }
            else
            {
                if((MAPA[LINHAC][soma] == 13)&& (m3 < 2))
                {
                    Player2[o] += 10;
                    c[LINHAC-1][soma] = '-';
                    m3++;
                }
                else
                {
                    if((MAPA[LINHAC][soma] == 14)&& (m4 < 2))
                    {
                        Player2[o] *= rand () % 3;
                        c[LINHAC-1][soma] = '§';
                        m4++;
                    }
                    else
                    {
                        if((MAPA[LINHAC][soma] == 15 && (m5 < 2)))
                        {
                            Player2[o] = Player2[o] * 0.7;
                            c[LINHAC-1][soma] = '°';
                            m5++;
                        }
                        else
                        {
                            Player2[o] += MAPA[LINHAC-1][soma];
                            c[LINHAC-1][soma] = 'X';
                        }
                    }
                }
            }
        }
        system("cls");
        Player3();
    }
}

int main() // PLANO DO JOGO
{
    srand(time(NULL));
    system("color 6");
    setlocale(LC_ALL,"");
    randval();

    int i, j, tst;
    float Maior = -9999;

    printf("\n\n\t|1 - jogar");
    printf("\n\t|2 - sair\n");
    scanf("%d",&tst);
    system("cls");
    if(tst == 1)
    {
        printf("DIGITE A QUANTIDADE DE JOGADORES: ");//LER A QUANTIDADE DE JOGADORES
        while ( L < 2 || L > 4)
        {
            scanf("%d", &L);
        }

        for(i = 0; i< L; i++)//NOME DOS JOGADORES
        {
            printf("Digite seu nome:  ");
            scanf("%s", Player[i]);
        }

        system("cls");

        for(i = 0; i < ((T*T)/L); i++)// ANALISA A QUANTIDADE DE JOGADAS TOTAL
        {
            Player3();// REFERENCIA A FUNÇÃO PLAYER3
            Player4(m1,m2,m3,m4);// REFERENCIA A FUNÇÃO PLAYER4
            system("cls");
        }
        for(j = 0; j < L; j++)
        {
            if(Player2[j] > Maior)
            {
                Maior = Player2[j];
                Ganhador = j;
            }
        }
        system("color D");
        printf("O Vencedor é %s com %.0f pontos!", Player[Ganhador], Maior);// MOSTRA O VENCEDOR
    }

    else
    {
        system("exit");
    }
}
