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
                printf("%c",str[k]); // @@ This should print str[i], not str[k]. It's repeating the first non-zero digit instead of printing the subsequent digits.
            }
        }
        printf("e-%d",k-1); // @@ The exponent should be -(k - 1), but more precisely, it should be -(number of leading zeros after decimal + 1). However, the main bug is in the loop above.
    }
    return 0;
    
}