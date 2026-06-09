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
            scanf("%c",&a[i]); // @@ [This reads an extra character after '-', but doesn't validate that there actually is a next character; also, it overwrites the '-' position and breaks input sequence handling. Additionally, when EOF is encountered during this second scanf, the program behavior is undefined.]
            if((a[i-2] <= '9' && a[i] <= '9' && a[i-2] < a[i])||(a[i-2] <= 'Z' && a[i] <= 'Z'&& a[i-2] >= 'A' && a[i-2] < a[i]) || (a[i-2] <= 'z' && a[i] <= 'z'&& a[i-2] >= 'a' && a[i-2] < a[i])) // @@ [The condition checks only upper bound for a[i] (e.g., a[i] <= '9') but not lower bound (e.g., a[i] >= '0'), leading to incorrect classification of characters like ':' or ';' as digits. Same issue applies to letters.]
            {
                while(a[i-2] + j <= a[i]) // @@ [Loop condition should be '<' instead of '<=', because expansion from 'a' to 'd' should produce 'b','c' only (not including 'd' again since it will be printed later). Also, this prints the entire range including the end character which may already be part of the input.]
                {
                    printf("%c", a[i-2] + j);
                    //printf("%d", i);
                    j++;
                }
                i--; // @@ [This decrements i after processing, but the logic of index management is flawed and leads to skipping or reprocessing characters.]
            }
            else
            {
                printf("%c%c", a[i-1], a[i]); // @@ [This prints '-' and the next character, but a[i-1] is '-', and a[i] is the character after '-', which is correct in intent, but due to earlier overwriting and index manipulation, it may print wrong or uninitialized values.]
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