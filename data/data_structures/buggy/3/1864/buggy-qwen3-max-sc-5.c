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
        printf("%c", '.');
        for (int j = ct; in[j] != '\n' && in[j] != '\0'; j++)
        {
            printf("%c", in[j]); // @@ [This loop starts at `j = ct`, which prints the first non-zero digit again, causing duplication. It should start at `j = ct + 1`. Also, input from `scanf("%s", ...)` does not contain '\n', so checking for '\n' is unnecessary and may cause reading beyond intended data.]
        }
        int num = ct - 1;
        printf("e-%d", num);
    }
    else if (in[0] > '0' && in[0] <= '9' && in[1] == '.')
    {
        printf("%se0", in); // @@ [This prints the entire original string including the decimal point and all digits, but scientific notation requires only one digit before the decimal and the rest after. For example, "5.67" should become "5.67e0", which is correct per problem, but if input is "5.0", it would print "5.0e0", which violates "no trailing zeros". However, problem states input has no trailing zeros, so this may be acceptable. But more critically, if input is like "12.34", this branch won't trigger, so logic is okay here. However, the real issue is in the third branch.]
    }
    else if (in[0] > '0' && in[0] <= '9' && in[1] >= '0' && in[1] <= '9')
    {
        int ct2;
        for (ct2 = 2; in[ct2] != '.'; ct2++); // num of integrity
        printf("%c.", in[0]);
        for (int q = 1;in[q] != '\0' && in[q] !='\n'; q++)
        {
            if (q == ct2)
                continue;
            else
            {
                printf("%c", in[q]); // @@ [This loop prints all digits except the decimal point, but starts from index 1, so it includes digits before the decimal (like in[1], in[2], ..., up to just before '.') and then digits after. However, after removing the '.', the total number of digits printed after the decimal may include more than needed. More critically, if the input has no decimal point (which shouldn't happen per problem), this loop would run indefinitely. But per problem, input always has digits before and after decimal. The bigger issue: the loop condition checks for '\n', which won't exist because scanf("%s") stops at whitespace and doesn't include newline. Also, when q reaches ct2 (the '.'), it skips it, which is correct. However, the output format requires that if there's only one digit before decimal originally (like "5.6"), it should be printed as "5.6e0", which is handled in second branch. This third branch handles multi-digit integer part like "123.45". But the output becomes "1.2345e2", which is correct. However, the loop prints from q=1 onward (excluding '.'), so for "123.45", it prints "2", "3", "4", "5" → "1.2345e2", which is correct. So maybe not an error here? But wait: what if the number is "10.5"? Then in[0]='1', in[1]='0', so this branch triggers. ct2 will be 2 (since in[2]=='.'). Then it prints "1." then loops q from 1: q=1 → '0' (not '.' so prints), q=2 → '.' → skip, q=3 → '5' → prints. So output: "1.05e1" — which is correct. So perhaps this branch is okay. But the real bug is in the first branch printing duplicate digit.]
        }
        printf("e%d", ct2-1);
    }
}