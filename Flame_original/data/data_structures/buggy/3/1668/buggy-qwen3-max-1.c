#include<stdio.h>
#include<string.h>
char str[101];

int main()
{
    gets(str); // @@ [Using 'gets' is unsafe and deprecated; it can cause buffer overflow. Additionally, some compilers may not support it, leading to compilation errors.]
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
        printf("e%d",flag-1); // @@ [If the input has no decimal point (though problem states it does), 'flag' remains 0, leading to incorrect exponent. Also, 'flag' is only set when '.' is found, but loop prints all non-'.' chars including those after decimal, which may be correct per problem, but logic assumes '.' exists. However, main issue is use of 'gets'.]
        
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
                printf("%c",str[k]); // @@ [Should print 'str[i]' instead of 'str[k]'; this causes repeated printing of the same digit.]
            }
        }
        printf("e-%d",k-1);
    }
    return 0;
    
}