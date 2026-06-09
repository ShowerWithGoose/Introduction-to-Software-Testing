#include<stdio.h>
#include<string.h>
char str[101];

int main()
{
    gets(str); // @@ [Using 'gets' is unsafe and deprecated; it can cause buffer overflow. More critically, in many modern environments, 'gets' is not available, leading to compilation errors.]
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
        printf("e%d",flag-1); // @@ [If the input has no decimal point (though problem says it does), 'flag' remains 0, leading to wrong exponent. But more pressingly, in the case where there is a decimal point, this logic works only if '.' appears after first digit. However, the main compilation issue stems from 'gets'.]
        
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
                printf("%c",str[k]); // @@ [This should be 'str[i]', not 'str[k]'; this causes incorrect digits to be printed (repeating the first non-zero digit). However, this is a logical error, not the cause of the compilation error. The primary compilation error is due to 'gets'.]
            }
        }
        printf("e-%d",k-1);
    }
    return 0;
    
}