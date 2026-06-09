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
            scanf("%c",&a[i]); // @@ [This reads an extra character after '-', but does not check if input ends (EOF) after '-', leading to undefined behavior or incorrect indexing when input ends with '-'. Also, it assumes there's always a character after '-', which may not be true.]
            if((a[i-2] <= '9' && a[i] <= '9' && a[i-2] < a[i])||(a[i-2] <= 'Z' && a[i] <= 'Z'&& a[i-2] >= 'A' && a[i-2] < a[i]) || (a[i-2] <= 'z' && a[i] <= 'z'&& a[i-2] >= 'a' && a[i-2] < a[i])) // @@ [Incorrect range checks: e.g., `a[i-2] <= '9'` alone doesn't ensure it's a digit; should also check `a[i-2] >= '0'`. Same issue for letters — missing lower bound checks for 'A' and 'a' on the left side. This can cause invalid expansions like expanding '-' between non-digit/non-letter characters.]
            {
                while(a[i-2] + j <= a[i]) // @@ [Loop condition uses `<=`, which causes output to include the ending character twice: once here and once when the next character is printed normally. Should be `<` to avoid duplication.]
                {
                    printf("%c", a[i-2] + j);
                    //printf("%d", i);
                    j++;
                }
                i--; // @@ [This decrements `i`, but the loop will increment `i` again at the end of the outer `while`, potentially skipping or misaligning indices. Logic for index management is flawed.]
            }
            else
            {
                printf("%c%c", a[i-1], a[i]); // @@ [This prints '-' (as a[i-1]) and the next char, but if the input ends right after '-', `a[i]` may be uninitialized or from previous input, causing garbage output. Also, this duplicates printing logic that should be handled uniformly.]
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