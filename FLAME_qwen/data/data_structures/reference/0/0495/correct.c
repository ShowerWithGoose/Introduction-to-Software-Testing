#include <stdio.h>

int main()
{
    char ch = 0, ch_prev, ch_next; // current, previous, next character
    char ch_temp;
    while (ch_prev = ch, ~scanf("%c", &ch))
    {
        if (ch == '-') // if the current character is '-' and prev character is a num or a letter, starts expanding
        {
            if (ch_prev >= '0' && ch_prev <= '9')
            {
                if (!~scanf("%c", &ch_next)){printf("%c", ch);break;} // input another letter
                if (ch_next >= ch_prev && ch_next <= '9') // can form a expand
                {
                    for (ch_temp = ch_prev + 1; ch_temp <= ch_next; ch_temp++) // the 1st letter has already been outputed, output from the 2nd
                    {
                        printf("%c", ch_temp);
                    }
                    ch = ch_temp - 1; // update the last character to ch
                }
                else // cannot, skip
                {
                    printf("-%c", ch_next);
                    ch = ch_next;
                }
            }
            else if (ch_prev >= 'a' && ch_prev <= 'z')
            {
                if (!~scanf("%c", &ch_next)){printf("%c", ch);break;} // input another letter
                if (ch_next >= ch_prev && ch_next <= 'z') // can form a expand
                {
                    for (ch_temp = ch_prev + 1; ch_temp <= ch_next; ch_temp++) // the 1st letter has already been outputed, output from the 2nd
                    {
                        printf("%c", ch_temp);
                    }
                    ch = ch_temp - 1; // update the last character to ch
                }
                else // cannot, skip
                {
                    printf("-%c", ch_next);
                    ch = ch_next;
                }
            }
            else if (ch_prev >= 'A' && ch_prev <= 'Z')
            {
                if (!~scanf("%c", &ch_next)){printf("%c", ch);break;} // input another letter
                if (ch_next >= ch_prev && ch_next <= 'Z') // can form a expand
                {
                    for (ch_temp = ch_prev + 1; ch_temp <= ch_next; ch_temp++) // the 1st letter has already been outputed, output from the 2nd
                    {
                        printf("%c", ch_temp);
                    }
                    ch = ch_temp - 1; // update the last character to ch
                }
                else // cannot, skip
                {
                    printf("-%c", ch_next);
                    ch = ch_next;
                }
            }
            else // cannot form a expand, skip
                printf("%c", ch);
        }
        else // regular char, skip
            printf("%c", ch);
    }
    return 0;
}

