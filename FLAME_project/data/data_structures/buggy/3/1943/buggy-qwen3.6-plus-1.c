#include<stdio.h>
#include<string.h>
int main()
{
    char c[100];
    gets(c);
    int num=0,flag=0,i=0,judge=0;
    if(strlen(c)==1)
    {
        printf("%c",c[0]);
        printf("e0");
    }
    else
    {
        if(c[0]=='0')
        {
            for(num=1,i=2;c[i]=='0';i++)
                num++;
            while(c[i]!='\0')
            {
                if(judge==1)
                    printf(".");
                judge++;
                printf("%c",c[i]);    
                i++;
            }
            printf("e-%d",num);
        }
        else
        {
            while(c[i]!='.'&&c[i]!='\0')
            {
                if(judge==1) // @@ The condition `judge==1` is intended to print the decimal point after the first digit, but `judge` is incremented immediately after checking. For the first digit (index 0), `judge` is 0, so it prints the digit. Then `judge` becomes 1. For the next character (which is '.'), `judge` is 1, so it prints '.', which is correct for the base format. However, the logic inside the loop prints characters one by one. If the number has multiple digits before the decimal point (e.g., 87899.), the loop will print '8', then '.', then '7', '8', '9', '9'. This results in "8.7899" instead of "8.7899...". The issue is that the decimal point should only be printed once, after the first significant digit, and the subsequent digits before the original decimal point should be printed as part of the mantissa without additional dots. The current logic inserts a dot after the first digit, which is correct for scientific notation base, but it fails to skip the original decimal point correctly in the subsequent logic or handles the transition poorly. Actually, looking at the buggy output `8.7899.999...`, it seems the code prints the first digit '8', then sets judge=1. Then it encounters '7' (next char? No, `i` increments). Let's trace: `i=0`, `c[0]='8'`. `judge=0`. Prints '8'. `judge` becomes 1. `i` becomes 1. Loop continues. `c[1]='7'`. `judge==1` is true. Prints '.'. `judge` becomes 2. Prints '7'. `i` becomes 2. This creates "8.7". Then `c[2]='8'`. `judge==1` is false. Prints '8'. This creates "8.78". This logic is fundamentally flawed for numbers with more than 2 digits before the decimal point because it only prints one dot after the first digit, but the `while` loop continues to process all digits before the decimal point. The standard scientific notation requires exactly one non-zero digit before the decimal point. The code attempts to do this by printing the first digit, then a dot, then the rest. But the `while` loop condition `c[i]!='.'` means it stops at the decimal point. So for "87899.", it processes '8', '7', '8', '9', '9'. 
                // Trace for "87899.":
                // i=0, c[0]='8', judge=0. Print '8'. judge=1. i=1.
                // i=1, c[1]='7', judge=1. Print '.'. judge=2. Print '7'. i=2. Output so far: "8.7"
                // i=2, c[2]='8', judge=2. Print '8'. i=3. Output: "8.78"
                // i=3, c[3]='9', judge=2. Print '9'. i=4. Output: "8.789"
                // i=4, c[4]='9', judge=2. Print '9'. i=5. Output: "8.7899"
                // i=5, c[5]='.'. Loop terminates.
                // Then it prints "." again? No, the `else` block below handles the decimal point.
                // The code then enters the `else` block because `c[i]=='.'`.
                // It prints ".". Output: "8.7899."
                // Then it loops through the rest: "9999999999000999".
                // Final output: "8.7899.9999999999000999e4".
                // The error is that the digits after the first one but before the decimal point are being printed as part of the integer sequence in the first loop, but they should be part of the fractional part of the scientific notation base. The first loop should only print the first digit. The subsequent digits before the original decimal point should be printed in the second part (after the decimal point of the scientific notation).
                printf(".");
                judge++;
                printf("%c",c[i]);
                i++;
            }
            if(c[i]=='\0')
            {
                printf("e%d",judge-1);
            }
            else
            {
                printf(".");  // @@ This prints an extra decimal point. The first loop already printed a decimal point after the first digit if there were more digits. If the number is like "8.78...", the first loop prints "8", then judge=1, then next char is '.', loop ends. Then this line prints ".". So we have "8.". Then the next loop prints the rest. This seems okay for "8.78". But for "87.8", first loop: i=0 '8' (print 8, judge=1), i=1 '7' (judge==1, print '.', judge=2, print '7'). Loop ends at i=2 ('.'). Output "8.7". Then this line prints ".". Output "8.7.". Then next loop prints "8". Result "8.7.8". This is wrong. The logic for handling the decimal point placement is incorrect.
                for(i++;c[i]!='\0';i++)
                {
                    printf("%c",c[i]);
                }
                printf("e%d",judge-1);
            }
        }
    }
        

    return 0;
}