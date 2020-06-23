void calculaSort(int vet[ ], int n, int exp){
   int aux[n];
   int i, indice[10] = {0};
   for (i = 0; i < n; i++)
     indice[ (vet[i]/exp)%10 ]++;
  for (i = 1; i < 10; i++)
    indice[i] += indice[i - 1];
  for (i = n - 1; i >= 0; i--) {
    aux[indice[ (vet[i]/exp)%10 ] - 1] = vet[i];
    indice[ (vet[i]/exp)%10 ]--;
   }
  for (i = 0; i < n; i++)
    vet[i] = aux[i];
  }
void radixSort(int vet[ ], int n)
{
 int exp, maior;
 maior = retornaMaior(vet,n);
 for (exp = 1; maior/exp > 0; exp *= 10)
 calculaSort(vet, n, exp);
}
