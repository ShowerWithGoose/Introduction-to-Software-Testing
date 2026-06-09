#include<stdio.h>
#include<string.h>

int main()
{
    char s[200];
    scanf("%s",s);
    
    int i,k,t=0,m;
    for(i=0;i<(strlen(s));i++)
    {
        if(s[i]=='.')
        {
            k=i; // @@ [k is used uninitialized if input has no decimal point, leading to undefined behavior]
        }
        if(s[i]=='0')
        {
            t++;
        }
        else 
        {
            t=0;
        }
    }
    if(k>1||(k==1&& s[0]!='0')) // @@ [k may be uninitialized here if input contains no '.', causing undefined behavior]
    {
        printf("%c",s[0]);
        printf(".");
        
        for(i=1;i<strlen(s)-t;i++)
        {
            if(i==k)
            continue;
            else
            printf("%c",s[i]);
        }
        printf("e%d",k-1); // @@ [k may be uninitialized if no '.' in input, leading to incorrect exponent]
    }
    else if(k=1) // @@ [assignment instead of comparison: should be '==' not '=', causing logical error and unintended side effect]
    {
        for(i=1;i<strlen(s);i++)
        {
            if(s[i]!='0'&&s[i]!='.')
            {
                m=i-1;
                break;
            }
        }
        printf("%c",s[m+1]); // @@ [m may be uninitialized if loop doesn't break (e.g., all zeros after decimal), leading to undefined behavior]
        if(strlen(s)==t+m+2) // @@ [m may be uninitialized; also logic for trailing zeros via 't' is flawed because 't' counts total zeros, not trailing ones]
        {
            printf("e-%d",m);
        }
        else
        {
            printf(".");
            for(i=m+2;i<strlen(s)-t;i++)
            {
                printf("%c",s[i]);
            }
        }
    }
    return 0;
}