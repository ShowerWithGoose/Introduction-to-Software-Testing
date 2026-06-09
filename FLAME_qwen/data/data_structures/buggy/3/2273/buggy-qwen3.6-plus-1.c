#include<stdio.h>
#include<string.h>
char c[100000000];
int main()
{
    int o=0,i=0,t=0,l;
    while(scanf("%c",&c[i])!=EOF)
    {
        if(c[i]=='.')
        t=i;
        i++; // @@ Increment i for every character read to avoid overwriting the current position and correctly track the length
    }
    i--;
    if(c[0]=='0')
    {
        for(l=2;c[l]=='0';l++); // @@ Start from index 2 to skip zeros after the decimal point, as index 1 is '.'
        if(i==(l+1))
        printf("%ce-%d",c[l],l-t); // @@ The exponent should be the difference between the first non-zero digit's index and the decimal point's index
        else
        {
            int k=l;
            printf("%c.",c[l]);
            for(l++;l<i;l++)
            printf("%c",c[l]);
            printf("e-%d",k-t); // @@ The exponent should be the difference between the first non-zero digit's index and the decimal point's index
        }
    }
    else
    {
        printf("%c.",c[0]);
        for(l=1;l<i;l++) if(c[l]!='.') // @@ Skip the decimal point character to prevent printing it twice in the output
        printf("%c",c[l]);
        printf("e%d",t-1);
    }
    return 0;
}