#include<stdio.h>
#include<string.h>
char str[101];

int main()
{
    gets(str);
    int len,k,flag=0;
    len=strlen(str);
    if(str[0]!='0')
        {
        printf("%c.",str[0]);
        for(k=1;k<len;k++)
        {
            if(str[k]!='.')
            {
                printf("%c",str[k]);
            }
            else flag=k;
        }
        printf("e%d",flag-1);
        
        }
    else{
        for(k=2;k<len;k++)
        {
            if(str[k]!='0')
            {
                printf("%c",str[k]);    
                break;
            }
        }
        if(k!=len-1)
        {
            printf(".");
            for(int i=k+1;i<len;i++)
            {
                printf("%c",str[k]); // @@ The loop should print str[i] not str[k], otherwise it repeats the first non-zero digit.
            }
        }
        printf("e-%d",k-1);
    }
    return 0;
    
}