#include<stdio.h>
#include<string.h>
int main()
{
    char c[101],a; // @@ unused variable 'a'
    int i,n,e=0,m;
    gets(c);
    for(i=0;i<strlen(c);i++)
    {
        if(c[i]=='.')
        n=i; // @@ variable 'n' not initialized; if no '.' found, n is undefined
         
    }
    if(strlen(c)==1)
    {
        printf("%ce0",c[0]);
    }
    else if(strlen(c)==3&&c[0]=='0') // @@ condition too specific; fails for numbers like "0.05" (length 4)
    {
        printf("%ce-1",c[2]); // @@ only works for single digit after decimal; ignores trailing digits
    }
    else
    {
        if(c[0]!='0')
        {
            e=n-1;
            for(i=n;i>1;i--)
            {
                c[i]=c[i-1]; // @@ shifts characters left but may cause off-by-one if n=1; works but fragile
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
            if(c[i++]=='0') // @@ post-increment used in condition; logic flawed and uses uninitialized 'm' if no break occurred
            {
                printf("%ce0",c[n]); // @@ prints decimal point '.' as base digit; incorrect
            }
            else
            {
                printf("%c.",c[m]); // @@ prints digit followed by a period, but should be only digit (base integer would be wrong here)
        
                for(i=m+1;i<strlen(c);i++)
                {
                    printf("%c.",c[i]); // @@ prints each subsequent digit with a period, resulting in extra periods
                
                }
                printf("e-%d",e);
                
            }
        
        }
    }
    return 0;
}