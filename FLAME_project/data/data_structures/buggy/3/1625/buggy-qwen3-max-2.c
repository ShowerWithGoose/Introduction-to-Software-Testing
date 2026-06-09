#include <stdio.h>
#include <string.h>

int main()
{
    char s[105];
    gets(s); // @@ [Using `gets()` is unsafe and may cause buffer overflow; more critically, it reads the entire line including the newline, but the logic below assumes the last character is part of the number. However, the main error is elsewhere.]
    int len=strlen(s);
    
    int num1=0;
    int i=0;
    while(s[i]!='.')
    {
        i++;
        num1++;
    }
    if(num1>1)
    {
        printf("%c.",s[0]);
        for(i=1;i<len-1;i++) // @@ [This loop stops at `len-2`, skipping the last character of the input. The condition should be `i < len` and skip the '.' manually, or handle the decimal part correctly. Because `s[len-1]` is the last digit (not a newline, since `gets` removes it), this misses the final digit.]
        {
            if(s[i]!='.')
            printf("%c",s[i]);
        }
        printf("e%d",num1-1);
    }
    else if(num1=1&&s[0]!='0') // @@ [This uses assignment `=` instead of comparison `==`. It sets `num1` to 1, which always evaluates to true if `s[0]!='0'`, but breaks intended logic. Should be `num1 == 1`.]
    {
        for(i=0;i<len;i++)
        {
            printf("%c",s[i]);
        }
        printf("e0");
    }
    else
    {
        int num2=0;
        i=2;
        while(1)
        {
            if(s[i]!='0') 
            break;
            i++;
            num2++;
        }
        if(i==len-1) // @@ [If the non-zero digit is at the last position (`i == len-1`), this prints only that digit without a decimal point, which is correct per spec. But note: due to earlier off-by-one in other branch, consistency is broken. However, this branch may work for its case. The primary bug causing the test failure is in the `num1>1` branch missing the last digit.]
        {
            printf("%ce-%d",s[i],num2+1);
        }
        else
        {
            printf("%c.",s[i]);
            while(i!=len-1) // @@ [This loop starts by incrementing `i` before printing, so it skips the character right after the first non-zero digit. For example, if `i` points to first non-zero at position k, it then does `i++` and prints from k+1 onward, missing the digit at k+0 after the decimal point. Should print current `i` first or adjust loop structure. However, in the given test case, this branch isn't taken, so not the cause of the specific WA.]
            {
                i++;
                printf("%c",s[i]);
            }
            printf("e-%d",num2+1);
        }
    }
        
}