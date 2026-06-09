#include<stdio.h>
#include<string.h>
char str[101];

int main()
{
    gets(str); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers. Should use 'fgets' instead.]
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
        printf("e%d",flag-1); // @@ [If the input has no decimal point (though problem states it does), 'flag' remains 0, leading to incorrect exponent. Also, 'flag' may be uninitialized if '.' is not found, causing undefined behavior.]
        
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
                printf("%c",str[k]); // @@ [Should print 'str[i]' instead of 'str[k]'; this repeats the same digit multiple times.]
            }
        }
        printf("e-%d",k-1); // @@ [Exponent calculation is incorrect for numbers like "0.001"; should be -(k-1) or similar based on position of first non-zero digit after leading zeros.]
    }
    return 0;
    
}