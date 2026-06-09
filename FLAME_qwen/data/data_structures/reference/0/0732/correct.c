#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define NumberOf(a) (sizeof(a)/sizeof(a[0]))
#define eps 1e-7
#include<stdio.h>
#include<string.h>
#include <ctype.h>

int Expand(char l,char r)
{
    if(isupper(l)&&isupper(r)&&r>l)
    {
        return 1;
    }
    else if(islower(l)&& islower(r)&&r>l)
    {
        return 1;
    }
    else if(isdigit(l)&& isdigit(r)&&r>l)
    {
        return 1;
    }
    else
        return -1;
}
int main()
{
    char str [1000]={};
    scanf("%s",str);
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {
        if(Expand(str[i],str[i+2])==1&&str[i+1]=='-')
        {
            int distance=str[i+2]-str[i];
            for(int k=0;k<distance;k++)
            {
                printf("%c",str[i]+k);
            }
           i++;
        }
        else
        {
            printf("%c",str[i]);
        }
    }
    return 0;
}




