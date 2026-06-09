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
    
    printf("%c", a[0]); // @@ This line incorrectly assumes the first character is always printed, but if the string starts with '-', it will cause undefined behavior or incorrect output. Also, it bypasses the logic for handling '-' at the start.
    for(i=1;a[i]!='\0';i++)
    {
        if(a[i]=='-'&&a[i-1]<a[i+1]) // @@ This condition does not check that both characters around '-' are of the same type (lowercase, uppercase, or digit). For example, 'B-e' has 'B' (uppercase) and 'e' (lowercase), which should not be expanded, but the condition a[i-1] < a[i+1] is true, so it incorrectly attempts expansion.
        {
            if(a[i-1]>='a'&&a[i+1]<='z') // @@ This condition only checks that a[i-1] is lowercase and a[i+1] is lowercase, but does not ensure both are lowercase letters. For 'B-e', a[i-1]='B' is not >= 'a', so this branch fails, but the else-if below also fails because a[i-1] is not >= 'A'? Actually 'B' is >= 'A', but a[i+1]='e' is not <= 'Z', so the uppercase branch also fails. Then the digit branch fails. So the else prints the '-', but the condition a[i-1]<a[i+1] already passed, leading to incorrect logic flow.
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='A'&&a[i+1]<='Z') // @@ This condition checks a[i-1] is uppercase and a[i+1] is uppercase, but for 'B-e', a[i+1]='e' is not <= 'Z', so this branch fails.
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='0'&&a[i+1]<='9') // @@ This condition checks both are digits, but for 'B-e', neither is a digit, so this branch fails.
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        }
        
        else
        {
            printf("%c", a[i]); // @@ When the outer if condition is true but none of the inner if-else branches match, this else is not executed because it belongs to the inner if-else structure? Actually, the else is attached to the outer if (the one with a[i]=='-'...), so if the outer condition is true, the inner if-else is executed, and if none of the inner conditions match, nothing is printed for that character, causing the '-' to be omitted. For 'B-e', the outer condition is true, inner conditions all fail, so '-' is not printed, resulting in "Be".
        }
        
    }
    
    
    return 0;
}