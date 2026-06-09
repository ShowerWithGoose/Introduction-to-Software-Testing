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
    for(int i=0;i<strlen(s);i++) // @@ [The loop condition uses strlen(s), but 'fig' and 'num' arrays are shorter; also, 'i' is used to index 'fig', which has fewer elements than 's'. This causes out-of-bound access and incorrect logic flow.]
    {
        if(fig[i]=='*'||fig[i]=='/') // @@ [When i exceeds the actual number of operators stored in 'fig', this accesses uninitialized/garbage values, leading to undefined behavior.]
        {
            num0=num[i]; // @@ [This should start from the current accumulated value or correct operand, not num[i], which may not correspond to the right operand after prior reductions. Also, if i >= l, num[i] is invalid.]
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
            i=k;
        }
        if(fig[i]=='+'||fig[i]=='-') // @@ [Same issue: fig[i] may be uninitialized or beyond valid operator count. Also, this block runs even after handling * /, possibly reprocessing operators.]
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
        if(fig[i]=='=') // @@ [Again, fig[i] may be garbage. Also, '=' is stored in fig, but the loop may process it multiple times or at wrong time.]
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