#include<stdio.h>
#include<string.h>
char str[101];

int main()
{
    gets(str); // @@ Compilation error: 'gets' is unsafe and removed in C11; use fgets or scanf.
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
                printf("%c",str[k]); // @@ Logical error: should be str[i] to print the remaining digits after the decimal point.
            }
        }
        printf("e-%d",k-1);
    }
    return 0;
    
}