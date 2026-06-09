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
        printf("%ce-1",c[2]); // @@ Error: This condition is too specific and does not handle all cases where the number is less than 1 (e.g., "0.001" has length 5, not 3). Also, the exponent calculation is incorrect; it should be based on the position of the first non-zero digit, not hardcoded as -1.
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
            if(c[i++]=='0') // @@ Error: This condition checks the wrong position and uses post-increment incorrectly. It should check if no non-zero digit was found after the decimal point (i.e., m is uninitialized), but the logic is flawed and may cause undefined behavior.
            {
                printf("%ce0",c[n]); // @@ Error: This prints the decimal point character instead of the correct digit. For input like "0.0", it should output "0e0", but this prints ".e0".
            }
            else
            {
                printf("%c.",c[m]);
        
                for(i=m+1;i<strlen(c);i++)
                {
                    printf("%c.",c[i]); // @@ Error: This incorrectly adds a '.' after every digit, producing output like "1.2.3." instead of "1.23".
                
                }
                printf("e-%d",e);
                
            }
        
        }
    }
    return 0;
}