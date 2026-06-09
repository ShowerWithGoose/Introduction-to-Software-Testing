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
            if(c[i++]=='0') // @@ [Logic error: This condition checks if the first digit after decimal is '0', but we already found the first non-zero digit at index m. If the number is 0.000...9, c[n+1] is '0', so this branch is taken incorrectly, printing garbage or wrong format. It should check if the number is effectively zero or handle the general case where we shift the first significant digit.]
            {
                printf("%ce0",c[n]); // @@ [Wrong output format: Prints the decimal point character 'c[n]' which is '.', followed by 'e0'. This is incorrect for numbers like 0.00000009123...]
            }
            else
            {
                printf("%c.",c[m]);
        
                for(i=m+1;i<strlen(c);i++)
                {
                    printf("%c.",c[i]); // @@ [Format error: Prints each subsequent digit followed by a dot '.', e.g., "1.2.3.". It should just print the character "%c".]
                
                }
                printf("e-%d",e);
                
            }
        
        }
    }
    return 0;
}