#include<stdio.h>
#include<string.h>
int main()
{
    char a[10001];
    int i = 0, j = 1;
    while(scanf("%c", &a[i]) != EOF)
    {
        if(a[i] == '-')
        {

            i++;
            scanf("%c",&a[i]);
            if((a[i-2] <= '9' && a[i] <= '9' && a[i-2] < a[i])||(a[i-2] <= 'Z' && a[i] <= 'Z'&& a[i-2] >= 'A' && a[i-2] < a[i]) || (a[i-2] <= 'z' && a[i] <= 'z'&& a[i-2] >= 'a' && a[i-2] < a[i]))
            {
                while(a[i-2] + j <= a[i])
                {
                    printf("%c", a[i-2] + j);
                    //printf("%d", i);
                    j++;
                }
                i--;
            }
            else
            {
                printf("%c%c", a[i-1], a[i]); // @@ [This prints '-' followed by next char when expansion shouldn't happen, but it should print the '-' and next char as-is only after already printing the previous char. However, the previous char was already printed in the else clause before encountering '-', leading to duplication or incorrect output. Also, logic fails to handle multiple ranges correctly because of flawed input reading and state management.]
                i--;
            }

        }
        else
        {
            printf("%c", a[i]); // @@ [This prints every non-'-' character immediately, which causes issues when a '-' follows because the character before '-' is already printed, but then during '-' handling, it may print extra characters or mishandle context. Specifically, in "a-uB-F", 'u' is printed here, then '-' is read, then 'B' is read; since 'u' and 'B' are different types, it prints "-B", resulting in "u-B" becoming "uB" (missing '-'), but expected is to keep "-B" as literal if not expandable. However, per problem, non-expandable patterns should be output unchanged — so "uB-F" should become "uB-F" unless B-F is valid (which it is). But due to immediate printing, 'u' is already out, then "-B" is handled incorrectly.]
            //printf("%d", i);
            i++;
        }

    }
}