#include<stdio.h>
#include<string.h>
int main()
{
    char c[101],a;
    int i,n,e=0,m;
    gets(c); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C11 standard]
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
            if(c[i++]=='0') // @@ [This condition checks only the first digit after decimal; logic is flawed and may access out-of-bound if input ends right after '.']
            {
                printf("%ce0",c[n]); // @@ [c[n] is '.', so this prints ".e0" which is invalid scientific notation]
            }
            else
            {
                printf("%c.",c[m]);
        
                for(i=m+1;i<strlen(c);i++)
                {
                    printf("%c.",c[i]); // @@ [Incorrectly prints a '.' after every digit, e.g., "1.2.3." instead of "1.23"]
                
                }
                printf("e-%d",e);
                
            }
        
        }
    }
    return 0;
}