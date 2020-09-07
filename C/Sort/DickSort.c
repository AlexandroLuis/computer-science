/*
    DickSort Developed by Alexandro 2020
*/

#include <stdio.h>
#include <stdlib.h>

/* Swap Values case Array[i] > Array[i+1]  */
void Swap(int *a, int n){ 
    int i, t, r;
    for(i = 0; i < n-1; i++) {
        if(a[i] > a[i+1]){
            t = a[i];
            a[i] = a[i+1];
            a[i+1] = t;
        }
    }
}

/* Verify if Array[i] > Array[i+1] and return stop value to Sort function  */
int Verify(int *a, int n){ 
    while(--n >= 1){
        if(a[n] < a[n-1])
            return 0;
    }
    return 1;
}

/* Case Verify Still false, Swap values */
void Sort(int *a, int n){
    while(Verify(a, n) != 1)
        Swap(a, n);
}

int main(){
    int i, V[] = {1,2,	3,	18,	90,	70,	25,	33,	38,	57,	82,
                  50, 38,	65,	40,	79,	18,	92,	92,	50,	50,
                  31,	28,	25,	31,	19,	71,	86,	97,	81,	62,
                  1,	5,	57,	52,	68,	49,	29,	9,	20,	5,
                  77,	17,	39,	52,	89,	56,	49,	65,	89};

    printf("Unordered:\n");
    for(i = 0; i < 50; i++)
        printf("%d ", V[i]);

    Sort(V, 50);/* 50 is Array size */

    printf("\nOrdered:\n");
    for(i = 0; i < 50; i++)
        printf("%d ", V[i]);
}
