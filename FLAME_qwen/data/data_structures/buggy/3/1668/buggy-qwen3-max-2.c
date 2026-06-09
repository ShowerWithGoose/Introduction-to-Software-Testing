#include<stdio.h>
#include<string.h>
char str[101];

int main()
{
    gets(str); // @@ [Using `gets()` is unsafe and deprecated; it can cause buffer overflow. Moreover, some compilers may not support it, leading to compilation errors.]
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
        printf("e%d",flag-1); // @@ [If the input has no decimal point (though problem states it does), `flag` remains 0, leading to incorrect exponent. Also, `flag` is only set when '.' is found, but loop prints all non-'.' chars including after decimal, which may be okay per problem, but logic assumes '.' exists.]
        
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
                printf("%c",str[k]); // @@ [Should print `str[i]`, not `str[k]`. This causes repeated printing of the same digit instead of subsequent digits.]
            }
        }
        printf("e-%d",k-1); // @@ [Exponent calculation is off. For "0.00123", first non-zero is at index 4 ('1'), so exponent should be -3, but k=4 → e-3? Actually k starts at 2 (after "0."), so for "0.001", k=4, exponent = -(k-1) = -3, which is correct. But if input is "0.1", k=2, exponent = -1 → correct. So this may be okay, but combined with other bugs leads to wrong output.]
    }
    return 0;
    
}