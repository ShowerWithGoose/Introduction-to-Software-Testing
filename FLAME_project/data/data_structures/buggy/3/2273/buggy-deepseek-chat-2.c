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
        else
        i++;
    }
    i--;
    if(c[0]=='0')
    {
        for(l=1;c[l]=='0';l++);
        if(i==(l+1))
        printf("%ce-%d",c[l],l); // @@ Error: When the input is "0.9", l becomes 1, and i is 1 (since i-- after reading "0.9" gives i=1). The condition i==(l+1) becomes 1==2 which is false, so it goes to the else branch and prints "9.e-1" instead of "9e-1". The logic for determining when to omit the decimal point is incorrect; it should check if there is exactly one significant digit after the decimal point with no other digits.
        else
        {
            int k=l;
            printf("%c.",c[l]);
            for(l++;l<i;l++)
            printf("%c",c[l]);
            printf("e-%d",k);
        }
    }
    else
    {
        printf("%c.",c[0]);
        for(l=1;l<i;l++)
        printf("%c",c[l]);
        printf("e%d",t-1);
    }
    return 0;
}