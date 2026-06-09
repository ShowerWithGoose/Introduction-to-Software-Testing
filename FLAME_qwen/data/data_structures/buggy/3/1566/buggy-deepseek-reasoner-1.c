#include<stdio.h>
#include<string.h>
int main()
{
    char c[101],a; // @@ Unused variable 'a' may cause a warning; if -Werror is used, it becomes an error.
    int i,n,e=0,m;
    gets(c); // @@ Use of 'gets' is deprecated and removed in C11; may cause compilation error in strict standards.
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
            if(c[i++]=='0')
            {
                printf("%ce0",c[n]);
            }
            else
            {
                printf("%c.",c[m]);
        
                for(i=m+1;i<strlen(c);i++)
                {
                    printf("%c.",c[i]); // @@ Logic error: extra '.' printed after each digit, not a compilation error but erroneous output.
                
                }
                printf("e-%d",e);
                
            }
        
        }
    }
    return 0;
}