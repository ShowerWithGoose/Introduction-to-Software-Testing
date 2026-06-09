#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    int i,j,k,l,m,n;
    gets(str);
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
    else if(str[strlen(str)-1]=='0') // @@ Condition is invalid: input has no trailing zeros after decimal point; this branch may never be triggered for valid inputs, and if triggered, produces incorrect output.
    {
        for(k=0;str[k]!='0';k++) // @@ Incorrect loop condition: it searches for the first '0' character, but in a valid number without trailing zeros this loop will behave unpredictably; also the logic inside does not produce correct scientific notation.
        {
            k==1?printf(".%c",str[k]):printf("%c",str[k]); // @@ Decimal point insertion is misplaced; does not yield a proper base for scientific notation.
        }
        for(l=k;str[l]!='\0';l++);
        
        printf("e%d",l-1); // @@ Exponent calculation l-1 is incorrect; it does not represent the correct exponent.    
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
        printf("e%d",2*m-n+1); // @@ Exponent formula 2*m-n+1 is wrong; should be m-1 (number of digits before decimal minus one).
            }
    }
    return 0;
}