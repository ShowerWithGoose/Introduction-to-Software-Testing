#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

char str[200];

int main()
{
    int i=0,j=0,cnt_f=0,cnt_b=0,flag=0;
    
    while(str[i]=getchar()) // @@ [The loop condition is incorrect: getchar() returns EOF on end-of-file or error, which may be -1 (non-zero), causing infinite loop. Also, it stores '\n' into str but doesn't null-terminate the string, leading to undefined behavior in strlen().]
    {
        if(str[i]=='\n')
        {
            break;
        }
        if(str[i]=='.')
        {
            flag=1;
        }
        if(flag==0)
        {
            cnt_f++;
        }
        else
        {
            cnt_b++; // @@ [cnt_b counts digits after decimal including newline; also, cnt_b is never used in output logic, making this variable redundant and possibly misleading.]
        }
        i++;
    }
    
    if(str[0]=='0')
    {
        for(i=2;i<strlen(str);i++) // @@ [strlen(str) is undefined because str is not null-terminated; this leads to reading uninitialized memory.]
        {
            if(str[i]!='0')
            {
                printf("%c",str[i]);
                break;
            }
        }
        if(i<strlen(str)-2) // @@ [Again, strlen(str) is invalid due to missing null terminator; also, logic for printing decimal point is flawed—should only print '.' if there are more digits after the first non-zero.]
        {
            printf(".");
        }
        for(j=i;j<strlen(str)-2;j++) // @@ [Invalid strlen usage; also, subtracting 2 assumes newline is at end, but newline was stored without null termination, so indexing is off.]
        {
            printf("%c",str[j]);
        }
        printf("e-%d",i-1); // @@ [Exponent calculation is incorrect: for input like "0.00123", i starts at 2, finds '1' at i=4, so exponent should be -3, but i-1 = 3 → outputs e-3? Wait: i=4 → e-3 is correct? But logic fails for edge cases like "0.1" (i=2, e-1 correct). However, due to missing null terminator, strlen is garbage, so loop bounds are wrong.]
    }
    else if(str[0]!='-')
    {
        printf("%c.",str[0]);
        for(i=1;i<strlen(str)-1;i++) // @@ [strlen(str) undefined; also, subtracting 1 assumes newline is last char, but no null terminator → unpredictable behavior.]
        {
            if(str[i]=='.')
            {
                continue;
            }
            printf("%c",str[i]);
        }
        printf("e%d",cnt_f-1); // @@ [cnt_f counts digits before decimal correctly, but if input has trailing newline included in count? Actually, cnt_f stops at '.', so it's okay—but overall logic fails due to string not being null-terminated.]
    }
    else
    {
        printf("-");
        if(str[1]=='0')
        {
            for(i=3;i<strlen(str);i++) // @@ [Same issue: strlen(str) undefined due to missing null terminator.]
            {
                if(str[i]!='0')
                {
                    printf("%c",str[i]);
                    break;
                }
            }
            if(i<strlen(str)-2) // @@ [Invalid strlen; also, logic for decimal point and digit printing suffers same issues as positive zero case.]
            {
                printf(".");
            }
            for(j=i;j<strlen(str)-2;j++) // @@ [Invalid bounds due to no null terminator and incorrect offset assumptions.]
            {
                printf("%c",str[j]);
            }
            printf("e-%d",i-2); // @@ [Exponent may be miscalculated due to incorrect i value from broken loop bounds.]
        }
        else
        {
            printf("%c.",str[1]);
            for(i=2;i<strlen(str)-1;i++) // @@ [strlen undefined; loop may read beyond intended input.]
            {
                if(str[i]=='.')
                {
                    continue;
                }
                printf("%c",str[i]);
            }
            printf("e%d",cnt_f-2); // @@ [cnt_f counts from start until '.', but for negative numbers, cnt_f includes '-' as non-decimal? Actually, flag is set only after '.', and cnt_f increments only when flag==0. Since str[0]=='-', then for i=0: flag=0 → cnt_f=1; i=1: if digit, cnt_f=2, etc. So cnt_f includes the '-' as a pre-decimal character? No: because str[0] is '-', then at i=0: flag=0 → cnt_f becomes 1. Then i=1: if it's a digit, still flag=0 → cnt_f increments. So cnt_f = number of characters before '.' including '-'. Thus, cnt_f-2 may be wrong. For "-12.34", cnt_f=3 ('-', '1', '2'), so exponent = 3-2 = 1, which is correct (1.234e1). But this relies on correct cnt_f, which is okay. However, the bigger issue is the string not being null-terminated, making all strlen calls dangerous.]
        }
    }
    return 0;
}