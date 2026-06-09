#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int i,j,k,l,m,n;
    gets(str); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings with modern compilers. It should be replaced with 'fgets'.]
    if(str[0]=='0')
    {
        for(i=2;str[i]=='0';i++);
        //printf("%d",i);
        for(j=i;str[j]!='\0';j++)
        {
            j==i+1 ? printf(".%c",str[j]):printf("%c",str[j]);
        }
        //printf("%d",j);
        //printf("%c",str[j]);
        printf("e-%d",i-1);
    }
    else if(str[strlen(str)-1]=='0')
    {
        for(k=0;str[k]!='0';k++) // @@ [This loop condition is incorrect: it stops when encountering a '0', but the input specification states there are no trailing zeros after the decimal point, and leading digits (before decimal) are non-zero except when the number starts with "0.". This logic does not correctly handle general cases and may lead to undefined behavior if no '0' is found (infinite loop or buffer overrun).]
        {
            k==1?printf(".%c",str[k]):printf("%c",str[k]);
        }
        for(l=k;str[l]!='\0';l++); // @@ [This loop does nothing useful; it just finds the end of string starting from index k, but l will be strlen(str), which doesn't help compute exponent correctly. Also, the exponent calculation below uses l-1 which is likely wrong.]
        
        printf("e%d",l-1);    
    }
    else
    {
        if(str[1]=='.')
        {
            printf("%s",str);
            printf("e0");
        }
        else{
        
        for(m=0;str[m]!='.';m++)
        {
            if(m==1) printf(".%c",str[m]);
            else printf("%c",str[m]);        
        }
        for(n=m+1;str[n]!='\0';n++)
        {
            printf("%c",str[n]);
        }
        printf("e%d",2*m-n+1); // @@ [The exponent formula '2*m - n + 1' is mathematically incorrect for converting decimal to scientific notation. The correct exponent should be (number of digits before decimal - 1), which is m - 1 (since m is the index of '.'), but this expression gives unpredictable results.]
            }
    }
    return 0;
}