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
        printf("%c", '.'); // @@ [This prints a '.' even when there are no digits after the first non-zero digit, which may result in trailing decimal point or extra digits. Also, it prints the first non-zero digit twice: once before '.' and once again inside the loop starting at j=ct.]
        for (int j = ct; in[j] != '\n' && in[j] != '\0'; j++) // @@ [Loop starts at 'ct', which is the index of the first non-zero digit, so this duplicates that digit. Should start at j = ct + 1. Also, input from scanf with %s doesn't include '\n', so checking for '\n' is unnecessary.]
        {
            printf("%c", in[j]);
        }
        int num = ct - 1;
        printf("e-%d", num);
    }
    else if (in[0] > '0' && in[0] <= '9' && in[1] == '.')
    {
        printf("%se0", in); // @@ [This prints the entire input as-is followed by "e0", but according to spec, if there's only one digit before '.', it should be printed without modification only if it's already normalized. However, per problem description, this case is valid and matches expected format, so this line may actually be correct. But note: if input is like "5.67", output becomes "5.67e0", which is acceptable per problem statement. So possibly not an error. However, the real issue is in other branches.]
    }
    else if (in[0] > '0' && in[0] <= '9' && in[1] >= '0' && in[1] <= '9')
    {
        int ct2;
        for (ct2 = 2; in[ct2] != '.'; ct2++); // num of integrity // @@ [If the input has no decimal point (though problem says it does), this loop runs past end of string causing undefined behavior. Also, assumes decimal point exists after at least two digits.]
        printf("%c.", in[0]);
        for (int q = 1;in[q] != '\0' && in[q] !='\n'; q++) // @@ [Again, '\n' check is unnecessary because scanf("%s") doesn't store newline. More critically, this loop prints all characters except skipping the decimal point, but includes digits after decimal correctly. However, combined with earlier logic, may produce correct base part.]
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