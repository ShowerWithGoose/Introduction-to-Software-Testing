#include<stdio.h>
#include<string.h>
char str[101];

int main()
{
    gets(str); // @@ [Using `gets()` is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments (like those with strict compilation flags or newer C standards), `gets` is not available, leading to a compilation error.]
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
            for(int i=k+1;i<len;i++) // @@ [Variable `i` is declared inside the for loop, which is valid in C99+, but if the compiler uses an older standard like C89, this will cause a compilation error. However, the primary compilation error is due to `gets`.]
            {
                printf("%c",str[k]); // @@ [This should be `str[i]`, not `str[k]`. This is a logical error, but not the cause of the compilation error. The main compilation issue remains `gets`.]
            }
        }
        printf("e-%d",k-1);
    }
    return 0;
    
}