#include <stdio.h>
#include <string.h>
int main()
{
    char s[10000]={}, fig[10000]={};
    int num[10000]={}, j=0, l=0;
    gets(s); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error in modern compilers due to removal from standard library]
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
    for(int i=0;i<strlen(s);i++) // @@ [Loop bound should be based on `j` (number of operators) or `l` (number of numbers), not `strlen(s)` which includes all characters including digits and equals sign; this leads to out-of-bound access of `fig` and `num` arrays]
    {
        if(fig[i]=='*'||fig[i]=='/') // @@ [Accessing `fig[i]` beyond its valid range because loop runs up to `strlen(s)` which is much larger than number of operators stored in `fig`]
        {
            num0=num[i]; // @@ [Incorrect indexing: `num[i]` may be uninitialized or wrong when `i` exceeds actual number count `l`; also logic assumes multiplication/division starts at current `i`, but doesn't account for preceding terms correctly]
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
        if(fig[i]=='+'||fig[i]=='-') // @@ [Same out-of-bound access issue as above; also this block executes even after handling * /, possibly reprocessing same operator]
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
        if(fig[i]=='=') // @@ [Again, accessing `fig[i]` with `i` possibly beyond valid range; also logic for final result does not correctly integrate initial sign (`first`) with computed `rec0`]
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
            printf("-%d\n", rec0); // @@ [Incorrectly prints negative sign separately; if `rec0` is already negative due to computation, this leads to wrong output like "--5"; should incorporate `first` into initial value instead]
            
            break;
        }
        
    }
    return 0;
}