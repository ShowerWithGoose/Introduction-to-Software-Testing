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
        if(a[i]=='-'&&a[i-1]<a[i+1]) // @@ [This condition does not verify that both surrounding characters are of the same type (e.g., both lowercase, both digits, etc.). For example, 'B' (uppercase) and 'e' (lowercase) satisfy 'B' < 'e', so it incorrectly attempts expansion.]
        {
            if(a[i-1]>='a'&&a[i+1]<='z') // @@ [This checks only that the left char is >= 'a' and right char <= 'z', but doesn't ensure both are lowercase. E.g., 'B' (not >= 'a') fails this, but what if left is lowercase and right is uppercase? Also, missing check that a[i+1] >= 'a' and a[i-1] <= 'z'.]
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='A'&&a[i+1]<='Z') // @@ [Similarly, this doesn't ensure both are uppercase. For 'B-e', a[i-1]='B' (>= 'A') and a[i+1]='e' (<= 'Z' is false, since 'e' > 'Z'), so this block is skipped. But the problem is the initial condition allowed entering the expansion block because 'B' < 'e'. However, none of the type-checking blocks trigger, so the '-' is not printed at all — leading to output "Be" instead of "B-e".]
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        else if(a[i-1]>='0'&&a[i+1]<='9') // @@ [Same issue: doesn't ensure both are digits. Also, if none of these conditions match, the '-' is silently skipped (not printed), which is wrong. The else clause only prints a[i] when the outer if fails, but if we enter the outer if and none of the inner ifs match, we skip printing the '-'.]
        {
            for(j=a[i-1]+1;j<a[i+1];j++)
            {
                printf("%c", j);
            }
        }
        }
        
        else
        {
            printf("%c", a[i]);
        }
        
    }
    
    
    return 0;
}