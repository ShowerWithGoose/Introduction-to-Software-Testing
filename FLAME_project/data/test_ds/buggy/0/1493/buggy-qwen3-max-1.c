#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
int main()
{
    int i;
    char a[1006], j;

    gets(a);
    
    printf("%c", a[0]); // @@ [If the input string starts with '-', this prints '-' without checking context, but more critically, if the string is empty, this causes undefined behavior. However, the main issue is in expansion logic.]
    for(i=1;a[i]!='\0';i++)
    {
        if(a[i]=='-'&&a[i-1]<a[i+1]) // @@ [This condition does not ensure that both surrounding characters are of the same type (e.g., both lowercase, both digits). For example, 'B' (uppercase) and 'e' (lowercase) satisfy 'B' < 'e', so it enters the block incorrectly.]
        {
            if(a[i-1]>='a'&&a[i+1]<='z') // @@ [This only checks that the left char is >= 'a' and right char <= 'z', but doesn't ensure the left char is <= 'z' or the right char is >= 'a'. So mixed cases like 'B-e' could pass if conditions are partially met, but actually here 'B'<'a', so this block is skipped. However, the real flaw is lack of full range validation for same category.]
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='A'&&a[i+1]<='Z') // @@ [Similarly, this doesn't check that a[i+1] >= 'A' or a[i-1] <= 'Z'. In test case 'B-e', a[i-1]='B' (ok), but a[i+1]='e' which is > 'Z', so this condition fails. But the initial condition a[i-1] < a[i+1] is true ('B'=66, 'e'=101), so it skips all expansion blocks and falls through—however, note that in this buggy code, when expansion conditions fail, it does NOT print the '-'. Wait: look at control flow.]
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='0'&&a[i+1]<='9') // @@ [Same issue: missing validation that both ends are digits. Also, if none of these if/else-if blocks execute, the '-' is never printed because the else clause only runs when the outer if (a[i]=='-'...) is false.]
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        } // @@ [Critical error: if a[i] is '-' and a[i-1] < a[i+1] is true, but the character types don't match (like 'B-e'), then none of the inner if blocks run, and the code does nothing—so the '-' is omitted from output. That's why "B-e" becomes "Be" instead of "B-e". The '-' must be printed in such cases, but it isn't.]
        
        else
        {
            printf("%c", a[i]);
        }
        
    }
    
    
    return 0;
}