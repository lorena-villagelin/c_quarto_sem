#include <stdio.h>
#include <stdlib.h>

int soma(float S[], int n, float x)
{
    int i, j;
    for(i=0; i<n-2; i++)
    {
        for(j=1;j<n;j++)
        {
            if((S[i]+S[j])==x) return 0;
        }
    }
    return 1;
}

int main()
{
    float S[5], x;
    int n=5, r;

    S[0]=2.9;
    S[1]=1.1;
    S[2]=3.2;
    S[3]=4.5;
    S[4]=7.6;

    x=5;

    r=soma(S, n, x);
    printf("%d", r);
}
