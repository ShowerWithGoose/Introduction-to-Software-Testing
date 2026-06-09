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
                    printf("%c",s[i]); // @@ The logic skips the decimal point correctly, but the loop condition `i<len` combined with `i++` inside the `if` block causes it to skip the character immediately following the decimal point if not handled carefully. However, looking at the specific failure: Input `87899.9999999999000999`. The code prints `8.` then iterates. `i=1` ('7') -> print. `i=2` ('8') -> print. `i=3` ('9') -> print. `i=4` ('9') -> print. `i=5` ('.') -> i becomes 6. `i=6` ('9') -> print. This part seems logically okay for skipping the dot. The issue is likely elsewhere or subtle. Let's re-read the expected vs buggy. Buggy: `8.7899999999999000999e4`. Expected: `8.78999999999999000999e4`. The buggy output is missing a '9' and has shifted zeros. Wait, `87899.9999999999000999`. Digits after dot: `9999999999000999`. That's 16 digits. Buggy output after dot: `7899999999999000999`. That's 19 digits? No. `8.` + `7899` (from before dot) + `9999999999000999` (from after dot). Total digits after dot in output: 4 + 16 = 20. Expected: `8.` + `7899` + `9999999999000999`. The expected output is `8.78999999999999000999e4`. Let's count digits in expected mantissa after dot: `78999999999999000999`. That is 20 digits. Buggy mantissa after dot: `7899999999999000999`. That is 19 digits. It seems one '9' is lost. In the input `87899.9999999999000999`, there are ten '9's after the decimal point before `000999`. Input: `87899.` followed by `9999999999` (10 nines) then `000999`. Total 16 digits after dot. The integer part is `87899`. Mantissa should be `8.7899` + `9999999999000999`. So `8.78999999999999000999`. The buggy output is `8.7899999999999000999`. It is missing one '9'. Why? The loop `for(i=1;i<len;i++)` prints characters. If `s[i]=='.'`, it increments `i` again. This effectively skips the '.'. It does NOT skip the next character. So `i=5` is '.', `i` becomes 6. Next iteration `i` becomes 7? No, the `for` loop does `i++` at the end of the iteration. So if `i=5`, we enter loop. `s[5]=='.'`. `i` becomes 6. End of loop body. `for` increment `i++` makes `i=7`. So `s[6]` is SKIPPED. That is the bug. The first digit after the decimal point is skipped.]
            }
        
        }
        printf("e%d",m-1);
        
    }
    
    
    return 0;
}