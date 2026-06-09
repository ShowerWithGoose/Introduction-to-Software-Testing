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
    
    printf("%c", a[0]);
    for(i=1;a[i]!='\0';i++)
    {
        if(a[i]=='-'&&a[i-1]<a[i+1])
        {
            if(a[i-1]>='a'&&a[i+1]<='z') // @@ The condition checks if the start is lowercase and end is within 'a'-'z' range, but fails to ensure they are of the same type (e.g., 'B' is not >= 'a', so this block is skipped correctly for B-e, but the logic for determining "same type" is incomplete across all branches. Specifically, for 'B-e', a[i-1]='B' is not >= 'a', so it goes to next else if. 'B' is >= 'A', and 'e' <= 'Z' is false. So it goes to next. 'B' >= '0' is true, 'e' <= '9' is false. So it falls through to else. Wait, let's trace B-e. i points to '-'. a[i-1]='B', a[i+1]='e'. Condition a[i]=='-' is true. a[i-1] < a[i+1] ('B' < 'e') is true. Enter block. Check 1: 'B' >= 'a' is false. Check 2: 'B' >= 'A' is true. 'e' <= 'Z' is false. Check 3: 'B' >= '0' is true. 'e' <= '9' is false. Falls through to inner else? No, there is no inner else for the type checks. The code structure is: if (type1) {...} else if (type2) {...} else if (type3) {...}. If none match, nothing is printed for the expansion part, but the '-' itself is also not printed because the outer else prints a[i] only if the outer if condition fails. Here the outer if succeeds, so we enter the block. If no inner if matches, nothing happens for this iteration. Then loop continues. Next char 'e' is printed by the else branch? No, the else branch is attached to the outer if. So if outer if is true, else is skipped. So '-' is consumed, nothing printed. Next iteration i points to 'e'. a[i] is not '-', so else branch prints 'e'. Output: "Be". Expected: "B-e". The error is that when the types don't match (like B and e), the code should output the '-' character as well. Currently, if the outer if condition is met (it is a '-' and prev < next), but the inner type checks fail, the '-' is swallowed and not printed. We need to handle the case where expansion conditions are not fully met (specifically type mismatch) by printing the '-' character.
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='A'&&a[i+1]<='Z')
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='0'&&a[i+1]<='9')
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        } // @@ Missing else clause here to print '-' when the character is '-' and prev < next, but types do not match. For example, in "B-e", 'B' < 'e' is true, so we enter this block. But 'B' and 'e' are not same type. None of the inner if/else if blocks execute. The '-' is effectively deleted. We need an else { printf("%c", a[i]); } here.
        
        else
        {
            printf("%c", a[i]);
        }
        
    }
    
    
    return 0;
}