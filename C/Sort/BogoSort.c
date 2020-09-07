#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int n){
    int i, t, r;
    for(i = 0; i < n; i++) {
        t = a[i];
        r = rand() % n;
        a[i] = a[r];
        a[r] = t;
    }
}

int Verify(int *a, int n){
    while(--n >= 1){
        if(a[n] < a[n-1])
            return 0;
    }
    return 1;
}

void Sort(int *a, int n){
    while(Verify(a, n) != 1)
        Swap(a, n);
}

int main(){
    int i, V[] = {64, 43, 99, 2, 12, 65, 54, 76, 42, 6, 3, 9, 1, 0, 3};

    printf("Unordered:\n");
    for(i = 0; i < 15; i++)
        printf("%d ", V[i]);

    Sort(V, 15);

    printf("\nOrdered:\n");
    for(i = 0; i < 15; i++)
        printf("%d ", V[i]);
}
