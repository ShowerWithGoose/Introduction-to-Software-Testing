#include <stdio.h>
#include <string.h>
int main()
{
    char s[10000]={}, fig[10000]={};
    int num[10000]={}, j=0, l=0;
    gets(s); // @@ [Using `gets` is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments, `gets` is not available, leading to a compilation error.]
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
    for(int i=0;i<strlen(s);i++) // @@ [Looping based on `strlen(s)` is incorrect here because `fig` and `num` arrays are shorter; this causes out-of-bounds access to `fig[i]` when `i` exceeds the number of operators. Should loop over `j` (number of operators) instead.]
    {
        if(fig[i]=='*'||fig[i]=='/') // @@ [Accessing `fig[i]` beyond its valid range due to incorrect loop bound leads to undefined behavior or wrong logic.]
        {
            num0=num[i]; // @@ [Incorrect indexing: should start from current term, but logic assumes `num[i]` corresponds correctly, which fails due to prior parsing issues and loop bounds.]
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
        if(fig[i]=='+'||fig[i]=='-') // @@ [Again, `fig[i]` may be out of bounds; also, this block doesn't handle cases where multiplication/division has already consumed terms, leading to double use or skipped terms.]
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
        if(fig[i]=='=') // @@ [Same out-of-bounds issue; also, the handling of the final result does not account for the initial sign correctly in all cases.]
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
            printf("-%d\n", rec0); // @@ [This prints "-X" even if `rec0` is negative, which could lead to "--5" or incorrect sign handling. Should apply `first` to the value before printing, not format string.]

            break;
        }
        
    }
    return 0;
}