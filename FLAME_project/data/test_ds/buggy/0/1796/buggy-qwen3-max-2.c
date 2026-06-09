#include <stdio.h>
#include <string.h>
char c[99],b[30],a[99];
int main() 
{
    gets(c);
    int i,j=0,k,n;
    for(i=0; c[i]!='\0'; i++) 
    {
        n=0;
        if(c[i]=='-') 
        {
            if(c[i-1]<c[i+1]) 
            {
                k=c[i+1]-c[i-1]-1;

                if(c[i-1]>='0'&&c[i+1]<='9') // @@ [The condition checks if the left char is >= '0' and right char <= '9', but does not ensure both are digits. For example, 'B-e' could pass if 'e' <= '9' (which it isn't), but more critically, it doesn't verify that both characters are of the same type. Also, it allows mixed cases like '0-Z' to potentially pass if Z <= '9' (which it doesn't), but the real issue is missing same-type validation.]
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='a'&&c[i+1]<='z') // @@ [Same issue: only checks lower bound on left and upper bound on right, not that both are lowercase letters. For example, 'B-e' has c[i-1]='B' (not >= 'a'), so this condition fails, which is correct in this case, but the logic is flawed for other inputs like 'a-Z' where 'a' >= 'a' and 'Z' <= 'z' is false, so it wouldn't expand, which is correct, but the condition structure is insufficient to guarantee same-type check. However, the critical error is that the program expands when it shouldn't because it doesn't validate that both sides are of the same category. In test case B-e, since 'B' is uppercase and 'e' is lowercase, they are different types, so no expansion should occur. But the current conditions might not catch all invalid cross-type cases correctly due to incomplete range checks. Actually, in this specific test case B-e, the first condition (digits) fails, second (lowercase) fails because 'B'<'a', third (uppercase) fails because 'e'>'Z', so it skips expansion and outputs '-', which is correct. Wait, but the buggy output is "Be", meaning the '-' was removed and not output. That indicates the program is not copying the '-' character when expansion doesn't happen. The real error is that when c[i]=='-' and the expansion conditions fail, the code does nothing—so the '-' is skipped and not copied to output array a[].]
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                } else if(c[i-1]>='A'&&c[i+1]<='Z') // @@ [Same as above: incomplete same-type validation. But more importantly, if none of these conditions are met (as in B-e), the '-' is never added to the output array a[], leading to its omission. The program only adds non-'-' characters in the else clause, and when it encounters '-', it either expands or does nothing—never copies the '-'.]
                {
                    for(n=1; n<=k; n++) 
                    {
                        a[j]=c[i-1]+n;
                        j++;
                    }
                }
            }
            else // @@ [Missing else block to handle the case when c[i]=='-' but c[i-1] >= c[i+1]. In this case, the '-' should be copied as-is, but the current code does nothing, so the '-' is omitted from output.]
            {
                // This block is missing: should copy '-' when expansion condition fails
            }
        }
        else
        {
            a[j]=c[i];
            j++;
        }
    }
    a[j]='\0';
    printf("%s",a);
    return 0;
}