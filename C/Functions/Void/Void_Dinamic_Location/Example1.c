#include <stdio.h>
#include <stdlib.h>
void incrementa_num(int *num);


void incrementa_num(int *num)
{
    *num += 1;
}

int main()
{
    int num = 10;

    incrementa_num(&num);
    printf("%d", num);

    return 0;
}
