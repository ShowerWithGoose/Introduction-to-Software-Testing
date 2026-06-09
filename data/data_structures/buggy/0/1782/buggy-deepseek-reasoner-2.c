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

            i++; // @@ Potential out-of-bounds if dash is first character (i=0 -> i=1 then a[i-2] accesses a[-1]); also fails to check next character availability.
            scanf("%c",&a[i]); // @@ No check for EOF; if input ends after dash, a[i] is undefined, leading to undefined behavior.
            if((a[i-2] <= '9' && a[i] <= '9' && a[i-2] < a[i])|| // @@ Digit condition missing lower bounds (a[i-2]>='0' and a[i]>='0'); allows non-digit characters that are <= '9'.
               (a[i-2] <= 'Z' && a[i] <= 'Z'&& a[i-2] >= 'A' && a[i-2] < a[i]) ||
               (a[i-2] <= 'z' && a[i] <= 'z'&& a[i-2] >= 'a' && a[i-2] < a[i]))
            {
                while(a[i-2] + j <= a[i])
                {
                    printf("%c", a[i-2] + j);
                    j++; // @@ j is never reset after expansion; retains its value from previous expansions, causing incorrect character offsets in subsequent dashes.
                }
                i--; // @@ Incorrect indexing: after decrement, i points to the dash character, which is overwritten by next scanf; breaks handling of consecutive dashes.
            }
            else
            {
                printf("%c%c", a[i-1], a[i]);
                i--; // @@ Same indexing issue as line 22; may cause out-of-bounds or incorrect subsequent reads.
            }

        }
        else
        {
            printf("%c", a[i]);
            i++;
        }

    }
}