#include<stdio.h>
#include<string.h>
char str[101];

int main()
{
    gets(str); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments, 'gets' is not available, leading to compilation errors.]
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
        printf("e%d",flag-1); // @@ [If the input has no decimal point (though problem says it does), 'flag' remains 0, leading to wrong exponent. But more pressingly, in cases where the number has only one digit before '.', e.g., "5.6", this works, but logic assumes decimal point always exists. However, main error is elsewhere.]
        
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
                printf("%c",str[k]); // @@ [This prints str[k] repeatedly instead of str[i]; should be str[i]. This causes incorrect mantissa digits after the decimal point.]
            }
        }
        printf("e-%d",k-1); // @@ [Exponent calculation is off by one in some cases. For example, "0.001" should give e-3, but k=4 (index of '1'), so k-1=3 → e-3 is correct. However, combined with earlier logic flaws, this may still fail. But primary bugs are 'gets' and printing str[k] instead of str[i].]
    }
    return 0;
    
}