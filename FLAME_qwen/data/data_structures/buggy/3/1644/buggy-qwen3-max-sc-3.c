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
    if(k>1||(k==1&& s[0]!='0')) // @@ [if input has no '.', k is uninitialized, causing incorrect condition evaluation]
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
        printf("e%d",k-1);
    }
    else if(k=1) // @@ [assignment (=) used instead of comparison (==), always evaluates to true and sets k=1]
    {
        for(i=1;i<strlen(s);i++)
        {
            if(s[i]!='0'&&s[i]!='.')
            {
                m=i-1;
                break;
            }
        }
        printf("%c",s[m+1]); // @@ [m may be uninitialized if loop doesn't break (e.g., all zeros after decimal)]
        if(strlen(s)==t+m+2) // @@ [m may be uninitialized, leading to undefined behavior]
        {
            printf("e-%d",m);
        }
        else
        {
            printf(".");
            for(i=m+2;i<strlen(s)-t;i++) // @@ [m may be uninitialized; also, t counts trailing zeros incorrectly in presence of '.']
            {
                printf("%c",s[i]);
            }
        }
    }
    return 0;
}