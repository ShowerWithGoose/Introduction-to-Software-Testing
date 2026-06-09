#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h> 

int main()
{
    char s[1000000];
    gets(s);
    int i,j,t,len;
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]==45)
        {
            j=s[i+1]-s[i-1];
            if(s[i-1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1]) // @@ The condition checks if the start is a digit and end is <= '9', but fails to ensure they are the SAME type. For "B-e", 'B' (66) is not >= 48, so this block is skipped. However, the logic for checking same type is flawed in all branches. Specifically, it doesn't check if the END character is of the same type as the START character properly in combination with the start check. More critically, for "B-e", 'B' is uppercase (65-90) and 'e' is lowercase (97-122). The code checks: 1. Digits: 'B'>=48 is true, 'e'<=57 is false. Skip. 2. Uppercase: 'B'>=65 is true, 'e'<=90 is false. Skip. 3. Lowercase: 'B'>=97 is false. Skip. Since no block executes, it falls through to the else block below? No, the structure is if(s[i]==45) { ... } else { printf("%c",s[i]); }. If the inner ifs don't match, nothing is printed for the '-' or the expansion. This is a major logic error. It should print the '-' if expansion conditions aren't met.
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t); 
            }
            else if(s[i-1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1]) // @@ Similar to above, this checks if start is uppercase and end is <= 'Z'. It does not explicitly verify that the end character is also uppercase in a robust way relative to the start, though <=90 helps. But the main issue is the missing else case to print '-' when expansion is invalid.
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t);
            }
            else if(s[i-1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1]) // @@ Similar to above.
            {
                for(t=1;t<j;t++)
                printf("%c",s[i-1]+t);
            }    
            // @@ Missing else clause here to print '-' when none of the expansion conditions are met. For input "B-e", none of the above ifs are true, so nothing is output for the '-', resulting in "Be" instead of "B-e".
        }
        else
        printf("%c",s[i]);
    }
    return 0;
}