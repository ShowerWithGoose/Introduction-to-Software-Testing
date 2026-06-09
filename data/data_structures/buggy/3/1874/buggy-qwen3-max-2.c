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
    else if(str[strlen(str)-1]=='0') // @@ [This condition assumes the last character is '0', but the problem states there are no trailing zeros after the decimal point, so this branch may never be valid. Also, it incorrectly handles numbers without a decimal point or with significant trailing digits.]
    {
        for(k=0;str[k]!='0';k++) // @@ [This loop condition is flawed: it stops at the first '0', but the number may have internal zeros that are significant (e.g., "102.3"). This leads to incorrect parsing.]
        {
            k==1?printf(".%c",str[k]):printf("%c",str[k]);
        }
        for(l=k;str[l]!='\0';l++); // @@ [This loop does nothing useful; it just finds the end of the string, but 'l' becomes strlen(str), which is then used incorrectly in exponent calculation.]
        
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
        printf("e%d",2*m-n+1); // @@ [The exponent formula '2*m - n + 1' is mathematically incorrect. The correct exponent for a number like "123.45" (m=3) should be 2, but this gives 2*3 - 5 + 1 = 2, which accidentally works for some cases but fails generally (e.g., "12.3": m=2, n=4 → 2*2-4+1=1, which is correct, but logic is not robust). However, more critically, this branch doesn't handle the case where the integer part has more than one digit correctly per scientific notation rules (should only keep one digit before decimal).]
            }
    }
    return 0;
}