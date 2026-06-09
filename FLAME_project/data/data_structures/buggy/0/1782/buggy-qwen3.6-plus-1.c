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
                while(a[i-2] + j <= a[i]) // @@ The condition uses <= which includes the end character, but the loop body prints a[i-2]+j. If j starts at 1, it prints from start+1 to end. However, the start character was already printed before encountering '-'. The logic for expansion should print characters strictly between start and end, or include end depending on interpretation. But looking at the expected output 'a-u' becomes 'abc...u'. The code prints 'a' then enters this block. It prints 'b'...'u'. This part seems okay for the first range.
                {
                    printf("%c", a[i-2] + j);
                    //printf("%d", i);
                    j++;
                }
                i--;
            }
            else
            {
                printf("%c%c", a[i-1], a[i]); // @@ When expansion is not performed (e.g., mixed case or invalid range), the code prints the '-' (a[i-1]) and the next character (a[i]). However, the initial character before '-' (a[i-2]) was already printed when it was processed as a normal character in the `else` block of the outer if. So printing a[i-1] ('-') and a[i] is correct to restore the original sequence "char-char".
                i--;
            }

        }
        else
        {
            printf("%c", a[i]);
            //printf("%d", i);
            i++;
        }

    }
}