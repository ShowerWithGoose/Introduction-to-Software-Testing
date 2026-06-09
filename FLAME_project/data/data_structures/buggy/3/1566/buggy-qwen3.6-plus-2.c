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
                c[i]=c[i-1];
            
            }
        
            c[1]='.';
            for(i=0;i<strlen(c);i++)
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
            if(c[i++]=='0') // @@ [Logic error: This condition checks if the character immediately after the decimal point is '0'. For input 0.00000009..., c[n+1] is '0', so this branch is taken. It prints "0e0" (or similar incorrect format) instead of handling the leading zeros correctly to find the first significant digit.]
            {
                printf("%ce0",c[n]); // @@ [Output error: Prints the digit before the decimal point (which is 0) followed by "e0". This is incorrect for numbers like 0.000...9. It should not enter this block if there are non-zero digits later, or the logic for finding the first non-zero digit is flawed because it breaks out of the loop but then checks a fixed position.]
            }
            else
            {
                printf("%c.",c[m]);
        
                for(i=m+1;i<strlen(c);i++)
                {
                    printf("%c.",c[i]); // @@ [Format error: Prints each subsequent digit followed by a dot '.', resulting in output like "9.1.2.3..." instead of "9.123...". The dot should only be printed once after the first significant digit.]
                
                }
                printf("e-%d",e);
                
            }
        
        }
    }
    return 0;
}