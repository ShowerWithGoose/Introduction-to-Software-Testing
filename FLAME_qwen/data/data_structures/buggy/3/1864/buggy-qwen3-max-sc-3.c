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
        printf("%c", '.'); // @@ [This prints a '.' unconditionally, but if the number has only one non-zero digit after leading zeros (e.g., "0.005"), it should output just "5e-3", not "5.e-3". Also, the loop below starts at `j = ct`, which includes the first non-zero digit again, causing duplication.]
        for (int j = ct; in[j] != '\n' && in[j] != '\0'; j++) // @@ [Loop starts at `ct`, which is the index of the first non-zero digit, so it prints that digit again after already printing it above, leading to duplication. Should start at `ct + 1`. Also, input from `scanf("%s", ...)` does not contain '\n', so checking for '\n' is unnecessary.]
        {
            printf("%c", in[j]);
        }
        int num = ct - 1;
        printf("e-%d", num);
    }
    else if (in[0] > '0' && in[0] <= '9' && in[1] == '.')
    {
        printf("%se0", in); // @@ [This prints the entire input as-is followed by "e0", but according to the problem, if there's only one digit before the decimal point (which is non-zero), and some digits after, the scientific notation should be of the form "d.dd...e0". However, this is acceptable per problem statement only if the input already matches the normalized form. But the problem says: "If it’s a decimal, it must have one significant digit before and after the decimal point" — but what if there are multiple digits after? Actually, this case is correct only when the input is like "5.123", which should become "5.123e0", so this line may be okay. However, note that the problem says "no trailing zeros", so input is clean. So maybe not an error here. But wait: what if input is "5."? The problem states "has digits before and after the decimal point", so this case won't occur. So this line might be okay. However, the real issue is in other branches.]
    }
    else if (in[0] > '0' && in[0] <= '9' && in[1] >= '0' && in[1] <= '9')
    {
        int ct2;
        for (ct2 = 2; in[ct2] != '.'; ct2++); // num of integrity // @@ [This loop assumes there is always a '.' after at least two digits. But if the input has no decimal point at all (though problem says it has digits before and after decimal point), this would cause undefined behavior. However, per problem, input always has decimal point. But more critically: if the number is like "123.45", then ct2 will stop at index 3 ('.'), which is correct. But the next part:]
        printf("%c.", in[0]);
        for (int q = 1;in[q] != '\0' && in[q] !='\n'; q++) // @@ [Again, checking for '\n' is unnecessary because `scanf("%s")` doesn't include newline. More importantly, this loop prints all characters except when q == ct2 (the decimal point). But note: the decimal point is at ct2, so it skips it. However, the digits printed include in[1], in[2], ..., skipping the '.', which is correct. BUT: what if the number is "12.34"? Then ct2=2 (since in[2]=='.'). Then we print in[0]='1', then '.', then for q=1: in[1]='2' → print, q=2: skip, q=3: '3', q=4:'4'. So output is "1.234e1", which is correct. So logic seems okay. However, the exponent is ct2-1: for "12.34", ct2=2, exponent=1 → correct. But what about "123.4"? ct2=3, exponent=2 → "1.234e2" → correct. So this part may be okay.]
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