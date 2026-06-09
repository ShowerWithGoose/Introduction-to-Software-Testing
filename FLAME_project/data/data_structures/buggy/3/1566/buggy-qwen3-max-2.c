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
            if(c[i++]=='0') // @@ [This condition is flawed: it only checks the first digit after decimal and assumes it's zero, but 'i' was already incremented in the loop above; also, this branch leads to printing ".e0" incorrectly]
            {
                printf("%ce0",c[n]); // @@ [c[n] is '.', so this prints ".e0", which is invalid scientific notation]
            }
            else
            {
                printf("%c.",c[m]);
        
                for(i=m+1;i<strlen(c);i++)
                {
                    printf("%c.",c[i]); // @@ [This prints each digit followed by a '.', causing output like "9.1.2.3...", which is wrong]
                
                }
                printf("e-%d",e); // @@ [The exponent calculation is incorrect: for input "0.00000009123...", the first non-zero is at index 9 (0-based), n=1, so e = 9 - 1 = 8, but it should be -8; also, the sign is handled as negative, but logic for magnitude is off due to indexing]
                
            }
        
        }
    }
    return 0;
}