#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000];
    gets(s);
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
                    printf("%c",s[i]); // @@ The logic skips the decimal point correctly, but the loop condition `i<len` combined with `i++` inside the if block causes the index to advance twice when the dot is found. However, the real issue in the provided buggy output vs expected output for input `87899.9999999999000999` is that the reference code (which this is supposed to be compared against or is a variant of) often fails due to precision or string handling. Let's look closely at the specific failure. Input: `87899.9999999999000999`. Expected: `8.78999999999999000999e4`. Buggy: `8.7899999999999000999e4`. The buggy output is missing two '9's. This suggests data loss. The `gets` function is unsafe but usually reads correctly. The issue is likely in how the digits are printed. Wait, looking at the buggy output `8.7899999999999000999e4` vs expected `8.78999999999999000999e4`. The expected has `...9999999999000999`. The buggy has `...999999999000999`. It seems like some digits are dropped. In the `else` block, the loop `for(i=1;i<len;i++)` prints characters. If `s[i]=='.'`, it increments `i` again. This effectively skips the character after the dot if not careful? No, `i++` in the loop header happens after the body. Inside the body, if `s[i]=='.'`, we do `i++`. Then the loop header does `i++`. So if `i` was at the dot, `i` becomes `dot_index + 1`. Then loop header makes it `dot_index + 2`. This skips the first digit after the decimal point! That is the error.
            }
        
        }
        printf("e%d",m-1);
        
    }
    
    
    return 0;
}