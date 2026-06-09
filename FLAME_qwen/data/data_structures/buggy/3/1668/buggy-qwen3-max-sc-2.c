#include<stdio.h>
#include<string.h>
char str[101];

int main()
{
    gets(str); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow. Additionally, some compilers/environments may not support it, leading to compilation errors or runtime issues.]
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
        printf("e%d",flag-1); // @@ [If the input has no decimal point (though problem states it does), 'flag' remains 0, leading to incorrect exponent. Also, 'flag' is only set when '.' is found, but loop prints all non-'.' chars including those after '.', which may include extra digits beyond intended mantissa.]
        
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
                printf("%c",str[k]); // @@ [This prints str[k] repeatedly instead of str[i], causing wrong fractional part in scientific notation.]
            }
        }
        printf("e-%d",k-1); // @@ [Exponent calculation is off by one in some cases; e.g., "0.001" should yield e-3, but k=4 (index of '1'), so k-1=3 → e-3 is correct, but logic may fail for edge cases like "0.1". Also, if input is "0.0", behavior is undefined per problem constraints, but code doesn't validate input.]
    }
    return 0;
    
}