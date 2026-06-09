#include <stdio.h>
int main()
{
    char in[200];
    scanf("%s", in);
    if (in[0] == '0' && in[1] == '.')
    {
        //<1
        int ct;
        for (ct = 2; in[ct] == '0'; ct++)
            ; // num of zeros+2
        printf("%c", in[ct]);
        printf("%c", '.'); // @@ [This prints a '.' even when there are no digits after the first non-zero digit, which may result in trailing decimal point or extra digits. Also, it prints the first non-zero digit twice: once before '.' and once again in the loop below.]
        for (int j = ct; in[j] != '\n' && in[j] != '\0'; j++) // @@ [Loop starts at 'ct', which is the index of the first non-zero digit, so this duplicates that digit. Should start at ct+1. Also, input from scanf with %s won't contain '\n', so checking for '\n' is unnecessary.]
        {
            printf("%c", in[j]);
        }
        int num = ct - 1;
        printf("e-%d", num);
    }
    else if (in[0] > '0' && in[0] <= '9' && in[1] == '.')
    {
        printf("%se0", in); // @@ [This prints the entire input as-is followed by "e0", but scientific notation requires only one digit before the decimal point. For example, input "5.67" should become "5.67e0", which is correct, but the problem states that if it's an integer base, it should have no decimal point. However, since input has decimal point, this might be acceptable. But note: if input is like "123.45", this branch won't trigger, so maybe not the main issue. However, this line is actually okay for numbers like "5.67".]
    }
    else if (in[0] > '0' && in[0] <= '9' && in[1] >= '0' && in[1] <= '9')
    {
        int ct2;
        for (ct2 = 2; in[ct2] != '.'; ct2++); // num of integrity // @@ [If the input has no decimal point (though problem says it does), this loop runs out of bounds. But per problem, input always has digits before and after decimal, so safe? However, if the number has only two digits before '.', e.g., "12.34", then ct2 becomes 2 (since in[2]=='.'). That's okay.]
        printf("%c.", in[0]);
        for (int q = 1;in[q] != '\0' && in[q] !='\n'; q++) // @@ [Again, '\n' check is unnecessary. More importantly, this loop prints all characters except skipping the decimal point. But it includes digits after the decimal correctly. However, note that after removing '.', the total length changes, but we're just printing, so okay.]
        {
            if (q == ct2)
                continue;
            else
            {
                printf("%c", in[q]);
            }
        }
        printf("e%d", ct2-1);
    }
}