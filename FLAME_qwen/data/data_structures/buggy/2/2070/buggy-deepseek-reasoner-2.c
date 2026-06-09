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
        for(int p=0;p<strlen(s);p++) // @@ [The loop shifts the string left, removing the leading minus. However, this approach incorrectly treats the first number as positive during arithmetic, and only negates the final result. For expressions like "-3+2", the computed result is -(3+2) = -5 instead of -1.]
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
                i=k;
            }else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='=')
            {
                fig[j]=s[i];
                j++;
            }else
            continue;
        }
    
    
    int num0=num[0], rec0=0, k=0;
    char str='+';
    for(int i=0;i<strlen(s);i++) // @@ [Loop should iterate over fig array length (j) instead of strlen(s) to avoid out-of-bounds access on fig.]
    {
        if(fig[i]=='*'||fig[i]=='/')
        {
            num0=num[i];
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
            i=k; // @@ [This line sets i to the index of the operator that terminated the * or / chain (e.g., '+' or '='). After the loop body, the for loop increments i, causing this operator to be skipped. As a result, the subsequent handling of that operator (like addition or the final '=') is never executed.]
        }
        if(fig[i]=='+'||fig[i]=='-')
        {
            if(str=='+')
            {
                rec0+=num0; // @@ [After adding num0 to rec0, num0 should be updated to the next number (e.g., num[i+1]) for correct processing of consecutive '+' or '-' operators. Otherwise, the same num0 is reused, leading to incorrect results.]
                str=fig[i];
            }else if(str=='-')
            {
                rec0-=num0; // @@ [Same issue as above: num0 is not updated to the next number, causing errors with consecutive +/-.]
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