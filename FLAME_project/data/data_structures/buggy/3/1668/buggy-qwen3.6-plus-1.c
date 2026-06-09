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
                printf("%c",str[i]); // @@ [the reason for the error: The original code used str[k] which prints the first non-zero digit repeatedly. It should use str[i] to print the subsequent digits of the number.]
            }
        }
        printf("e-%d",k-1);
    }
    return 0;
    
}