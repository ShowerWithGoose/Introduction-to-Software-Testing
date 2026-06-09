#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int i,j,k,l,m,n;
    gets(str); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers. It should be replaced with 'fgets'.]
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
        for(k=0;str[k]!='0';k++) // @@ [This loop condition is incorrect: it stops when encountering a '0', but the input specification says there are no trailing zeros after the decimal point, and digits before the decimal point (if more than one digit) cannot start with 0. Also, this branch logic does not correctly handle numbers without trailing zeros as claimed.]
        {
            k==1?printf(".%c",str[k]):printf("%c",str[k]);
        }
        for(l=k;str[l]!='\0';l++);
        
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
        printf("e%d",2*m-n+1); // @@ [The exponent calculation '2*m - n + 1' is incorrect. The correct exponent for scientific notation when moving the decimal point from its original position to after the first digit is 'm - 1', where m is the number of digits before the decimal point.]
            }
    }
    return 0;
}