#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000];
    gets(s); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers due to security risks. Use 'fgets' instead.]
    int i=0;
    int len=strlen(s);
    int m=0;
    if(s[1]=='.')
    {
        if(s[0]!='0')
        {
         printf("%se0",s);
        }
    else    if(s[0]=='0')
    {
        i=2;
        while(s[i]=='0')
        {
            i++;
        }
        if(i==len-1)
        {
            printf("%ce-%d",s[i],i-1);
        }
        else
        {
            m=i-1;
            printf("%c.",s[i]);
            i++;
            while(i<len)
            {
                printf("%c",s[i]);
                i++;
            }
            printf("e-%d",m);
            
            
        }
    }
    }
    else
    {
        for(i=0;i<len;i++)
        {
            if(s[i]=='.')
            break;
        }
        m=i;
        printf("%c.",s[0]);
        for(i=1;i<len;i++)
        {
            if(s[i]=='.')
            {
                i++;
            }
            else
            {
                    printf("%c",s[i]);
            }
        
        }
        printf("e%d",m-1);
        
    }
    
    
    return 0;
}