#include<stdio.h>
#include<string.h>
char str[101];

int main()
{
    gets(str); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow and is removed in C11. Also, some compilers may not support it, leading to compilation errors.]
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
        printf("e%d",flag-1); // @@ [If the input has no decimal point (though problem says it does), 'flag' remains 0, leading to wrong exponent. But more critically, in cases where the number has only one digit before '.', 'flag' is set correctly, but logic assumes decimal point always exists. However, main compilation issue stems from 'gets'.]
        
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
                printf("%c",str[k]); // @@ [Should print 'str[i]' instead of 'str[k]'; this causes repeated printing of the same digit. However, this is a logical error, not compilation. The compilation error is due to 'gets'.]
            }
        }
        printf("e-%d",k-1);
    }
    return 0;
    
}