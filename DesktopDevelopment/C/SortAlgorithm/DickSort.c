/*
    DickSort Developed by Alexandro 2020
*/

#include <stdio.h>
#include <stdlib.h>

/* Swap Values case Array[i] > Array[i+1]  */
void Swap(int *V, int s){
    int i, aux;
    for(i = 0; i < s-1; i++) {
        if(*(V+i) > *(V+i+1)){
            aux = *(V+i);
            *(V+i) = *(V+i+1);
            *(V+i+1) = aux;
        }
    }
}

/* Verify if Array[i] > Array[i+1] and return stop value to Sort function  */
int Verify(int *V, int s){
    while(--s >= 1){
        if(*(V+s) < *(V+s-1))
            return 0;
    }
    return 1;
}

/* Recursive, if Verify Still false, Swap values */
int Sort(int *V, int s){
    if(Verify(V, s) != 1){
        Swap(V, s);
        Sort(V, s);
    }
}

int main(){
    int i, *V, s = 50;

    V = malloc(s* sizeof(int));

    for(i = 0; i < s; i++){
        *(V+i) = rand()%100;
    }

    printf("Unordered:\n");
    for(i = 0; i < s; i++)
        printf("%d ", *(V+i));

    Sort(V, s);/* 50 is Array size */

    printf("\nOrdered:\n");
    for(i = 0; i < s; i++)
        printf("%d ", *(V+i));
}
