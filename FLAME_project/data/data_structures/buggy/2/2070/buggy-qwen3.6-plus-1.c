#include <stdio.h>
#include <string.h>
int main()
{
    char s[10000]={}, fig[10000]={};
    int num[10000]={}, j=0, l=0;
    gets(s);
    char first='+';
    if(s[0]=='-')
    {
        first='-';
        for(int p=0;p<strlen(s);p++)
        {
            s[p]=s[p+1];
        }
    }
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]>='0'&&s[i]<='9')
            {
                int k=i;
                while(s[k]>='0'&&s[k]<='9')
                {
                    num[l]=num[l]*10+(s[k]-'0');
                    k++;
                }
                l++;
                i=k; // @@ The loop increment i++ will execute after this, skipping the character immediately following the last digit. It should be i=k-1 so that the next iteration starts at k.
            }else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='=')
            {
                fig[j]=s[i];
                j++;
            }else
            continue;
        }
    
    
    int num0=num[0], rec0=0, k=0;
    char str='+';
    for(int i=0;i<strlen(s);i++) // @@ The loop condition uses strlen(s) which is the length of the original string, but the logic iterates based on operators stored in fig. It should iterate based on the number of operators parsed (j). Also, the logic inside assumes fig[i] corresponds to the operator between num[i] and num[i+1], but the indexing and state management are flawed for chained operations.
    {
        if(fig[i]=='*'||fig[i]=='/')
        {
            num0=num[i]; // @@ This resets the accumulated value to the current number, ignoring previous multiplications/divisions in the chain if not handled correctly by the outer loop structure.
            k=i;
            while(fig[k]=='*'||fig[k]=='/')
            {
                if(fig[k]=='*')
                {
                    num0=num0*num[k+1];
                    k++;
                }
                else if(fig[k]=='/')
                {
                    num0=num0/num[k+1];
                    k++;
                }
            }
            i=k; // @@ Similar to the earlier error, this skips the next character. Since the outer loop increments i, this might skip an operator or number incorrectly.
        }
        if(fig[i]=='+'||fig[i]=='-')
        {
            if(str=='+')
            {
                rec0+=num0;
                str=fig[i];
            }else if(str=='-')
            {
                rec0-=num0;
                str=fig[i];
            }
        }
        if(fig[i]=='=')
        {
            if(str=='+')
            {
                rec0+=num0;
            }else if(str=='-')
            {
                rec0-=num0;
            }
            
            if(first=='+')
            printf("%d\n", rec0);
            else if(first=='-')
            printf("-%d\n", rec0);
            
            break;
        }
        
    }
    return 0;
}