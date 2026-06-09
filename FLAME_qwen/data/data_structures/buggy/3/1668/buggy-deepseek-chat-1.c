#include<stdio.h>
#include<string.h>
char str[101];

int main()
{
    gets(str); // @@ gets() is unsafe and not standard; should use fgets() or scanf()
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
            else flag=k; // @@ flag is set to the index of '.' but never used correctly; should be used to compute exponent
        }
        printf("e%d",flag-1); // @@ flag-1 is incorrect; exponent should be number of digits before decimal point minus 1, but flag may be 0 if no '.' found
        
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
        if(k!=len-1) // @@ condition is incorrect; should check if there are more digits after the first non-zero digit
        {
            printf(".");
            for(int i=k+1;i<len;i++)
            {
                printf("%c",str[k]); // @@ should print str[i] instead of str[k]; this prints the same character repeatedly
            }
        }
        printf("e-%d",k-1); // @@ exponent calculation is incorrect; should count leading zeros after decimal point
    }
    return 0;
    
}