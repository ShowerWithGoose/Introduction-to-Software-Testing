#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
//#define ll long long

char c0[100000];
char ans[100000];
int check(char *c,int i)
{
    if (c[i] >= '0' && c[i] <= '9' && c[i + 2] >= '0' && c[i + 2] <= '9' && c[i] < c[i + 2])    return 1;
    else if (c[i] >= 'a' && c[i ] <= 'z' && c[i + 2] >= 'a' && c[i + 2] <= 'z' && c[i  ] < c[i +2]) return 1;
    else if (c[i ] >= 'A' && c[i ] <= 'Z' && c[i + 2] >= 'A' && c[i + 2] <= 'Z' && c[i ] < c[i + 2])    return 1;
    return 0;
}
int main()
{
    scanf("%s", c0);
    int i, j;
    int len = strlen(c0);
    for (i = 0; i < len; i++)
    {
        if(c0[i] != '-' && c0[i+1]!='-')
            printf("%c",c0[i]);
        if (c0[i+1] == '-' && i != len-1)
        {
            if(check(c0,i)){
                for(j=c0[i];j<c0[i+2];j++)
                    printf("%c",j);
            }
        }
        if(c0[i]=='-'&&(check(c0,i-1)==0))
            printf("%c-",c0[i-1]);
    }

    return 0;
}


