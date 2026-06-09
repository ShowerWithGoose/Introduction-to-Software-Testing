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
        printf("%c", '.'); // @@ [This prints a '.' even when there are no digits after the first non-zero digit, violating the requirement that trailing zeros are not present and that the mantissa should not have unnecessary decimal points. Also, it prints the '.' before checking if more digits exist.]
        for (int j = ct; in[j] != '\n' && in[j] != '\0'; j++) // @@ [Loop starts at `ct`, which is the index of the first non-zero digit, so it prints that digit again, causing duplication. Should start at `ct + 1`. Also, input from `scanf` with %s doesn't include '\n', so checking for '\n' is unnecessary.]
        {
            printf("%c", in[j]);
        }
        int num = ct - 1;
        printf("e-%d", num);
    }
    else if (in[0] > '0' && in[0] <= '9' && in[1] == '.')
    {
        printf("%se0", in); // @@ [This prints the original number including the decimal point and all digits, but according to the problem, if there's only one digit before the decimal point (which is true here), the scientific notation should just be that digit followed by "e0" — not the whole string. For example, input "5.67" should output "5.67e0", but this is acceptable per problem? However, note: problem says if base is decimal, must have one digit before and after decimal. But "5." would be invalid. However, input guarantees digits after decimal. So maybe okay? But wait: what if input is "5.0"? But problem states: "all digits are significant (i.e., there are no trailing zeros after the decimal point)", so "5.0" won't appear. So this may actually be correct. However, consider: the problem says if only one digit before decimal, it can be 0 — but here it's non-zero. And output format allows decimal with one digit before and after. But this prints the entire string, which is correct only if there's exactly one digit before decimal. Since condition is `in[1] == '.'`, yes, so "5.123" → "5.123e0", which is correct. So maybe not an error. But wait: what if input is "1."? But problem says digits before and after decimal point exist. So this case may not occur. So perhaps this line is okay. However, the real issue is in the first branch.]
    }
    else if (in[0] > '0' && in[0] <= '9' && in[1] >= '0' && in[1] <= '9')
    {
        int ct2;
        for (ct2 = 2; in[ct2] != '.'; ct2++); // num of integrity // @@ [If the input has no decimal point (though problem says it does), this loop runs out of bounds. But problem states input has digits before and after decimal, so '.' exists. However, if the number is like "123.45", ct2 becomes 3 (index of '.'). Then the loop below skips the '.' correctly. But note: the loop condition assumes '.' appears after at least two digits, which is true per problem (since first digit non-zero, and multiple digits before decimal).]
        printf("%c.", in[0]);
        for (int q = 1;in[q] != '\0' && in[q] !='\n'; q++) // @@ [Again, '\n' check is unnecessary because scanf("%s") doesn't read newline. Also, when q == ct2 (the '.'), it skips it, which is correct. But note: the loop prints all digits except '.', starting from index 1. However, this includes digits after the decimal as well, which is correct. But what about the length? It should work. However, consider: input "123.45" → prints "1." then "2345", so "1.2345e2", which is correct. So logic seems okay. But potential issue: if the input ends right after '.', but problem says digits after decimal exist, so safe.]
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