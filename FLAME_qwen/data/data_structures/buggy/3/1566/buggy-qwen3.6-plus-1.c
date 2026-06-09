#include<stdio.h>
#include<string.h>
int main()
{
    char c[101],a;
    int i,n,e=0,m;
    gets(c);
    for(i=0;i<strlen(c);i++)
    {
        if(c[i]=='.')
        n=i;
         
    }
    if(strlen(c)==1)
    {
        printf("%ce0",c[0]);
    }
    else if(strlen(c)==3&&c[0]=='0')
    {
        printf("%ce-1",c[2]);
    }
    else
    {
        if(c[0]!='0')
        {
            e=n-1;
            for(i=n;i>1;i--)
            {
                c[i]=c[i-1]; // @@ The character shifting logic incorrectly overwrites data and fails to properly remove the decimal point or maintain string termination, resulting in corrupted output.
            
            }
        
            c[1]='.';
            for(i=0;i<strlen(c);i++) // @@ Using strlen(c) after improper string modification may yield an incorrect length or print garbage characters.
            {
                printf("%c",c[i]);
                
            }
            printf("e%d",e);
        }
        else
        {
            for(i=n+1;i<strlen(c);i++)
            {
                if(c[i]!='0')
                {
                    m=i;
                    e=m-n;
                    break;
                }
        
            }
            i=n+1;
            if(c[i++]=='0') // @@ Incorrectly checks the first digit after the decimal and increments i; the logic fails to properly handle leading zeros after the decimal point.
            {
                printf("%ce0",c[n]); // @@ Prints the decimal point character '.' instead of a significant digit, resulting in invalid scientific notation.
            }
            else
            {
                printf("%c.",c[m]);
        
                for(i=m+1;i<strlen(c);i++)
                {
                    printf("%c.",c[i]); // @@ Incorrectly appends a dot after every subsequent digit instead of printing them consecutively, corrupting the mantissa.
                
                }
                printf("e-%d",e);
                
            }
        
        }
    }
    return 0;
}