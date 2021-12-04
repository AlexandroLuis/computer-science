#include <stdio.h>
int main()
{
    double a=0.0, M[12][12];
    char T[2];
    int i,j,p=0,r=4;
    scanf("%s", &T);
    for(i=0;i<=11;i++)
    {
        for(j=0; j<=11; j++)
            scanf("%lf", &M[i][j]);
    }
    for(i=1; i<=10;i++)
    {
        if(i<=5)
        {
            for(j=0; j<=p;j++)
                a+=M[i][j];
            p++;
        }
        else if(i>=6)
        {
        for(j=0; j<=r; j++)
            a+=M[i][j];
        r--;
        }
    }
    if(T[0]=='S')
        printf("%.1lf\n",a);
    else if(T[0]=='M')
        printf("%.1lf\n",a/30.0);
    
    return 0;
}