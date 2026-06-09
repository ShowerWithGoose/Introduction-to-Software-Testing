#include <stdio.h>
#include <string.h>
char in[101];
char *ptr;
int whe;
void fa(char in[])
{
    if (*(in) == '0')
    {
        int cnt = 1;
        in += 2; // @@ [If the input is "0.x", this skips the '0' and '.', but if the string length is less than 3 (e.g., "0."), this leads to undefined behavior by accessing out-of-bounds memory.]
        while (*(in++) == '0') // @@ [This loop increments `in` before checking, which may skip the first non-zero digit or access beyond the string if all digits after '.' are zero (though problem states no trailing zeros, but still unsafe). Also, if the string ends right after '.', this dereferences '\0' and compares to '0', then increments past it.]
            cnt += 1;
        in -= 1; // @@ [This attempts to backtrack after overshooting in the loop, but logic is flawed: if the first character after '.' is non-zero, the loop body doesn't run, so `in` was incremented once in condition, then decremented—correct. But if loop runs, `in` points one past last '0', then decrement puts it at first non-zero—seems okay, but relies on precise pointer arithmetic that may break on edge cases like "0.0" (though problem says no trailing zeros, so maybe not). However, more critically, if input is just "0" (no decimal point), this code assumes there's a '.' at index 1, which isn't guaranteed by problem? Problem says: "has digits before and after the decimal point", so input always has a decimal point. So maybe safe? But still, the initial `in += 2` assumes format "0.digits", which is valid per problem. However, the real error is below:]
        printf("%c", *(in)); // @@ [If the input after skipping zeros is empty (shouldn't happen per problem constraints), this could print garbage. But main issue is next:]
        in += 1;
        while (*(in) != '\0') // @@ [This prints remaining digits without a decimal point. But scientific notation requires either a single digit (if no fractional part) or one digit before and some after decimal. Here, if there are multiple digits after the first non-zero, they are printed directly after the first digit with no decimal point, violating output format. For example, input "0.00123" should output "1.23e-3", but this prints "123e-3". Missing the decimal point after the first digit.]
            printf("%c", *(in++));
        printf("e-%d", cnt); // @@ [Exponent calculation is off: for "0.001", first non-zero at position 3 (0-indexed: '0','.','0','0','1'), so exponent should be -3. Here, cnt starts at 1, increments twice (for two '0's after '.'), so cnt=3, prints e-3 — correct. So exponent may be okay, but missing decimal point is critical.]
    }
    else
    {
        ptr = strchr(in, '.'); // @@ [Assumes there is always a decimal point. Problem states: "has digits before and after the decimal point", so this is safe.]
        whe = ptr - in + 1; // @@ [whe becomes index of '.' plus 1. For "123.45", ptr-in=3, whe=4. Then exponent is whe-2 = 2, which is correct (1.2345e2). So exponent logic seems okay.]
        printf("%c.", *(in++)); // @@ [Prints first digit and a decimal point — good.]
        while (*(in) != '\0')
        {
            if (*(in) == '.')
                in += 1; // @@ [Skips the decimal point — correct.]
            else
                printf("%c", *(in++)); // @@ [Prints all other digits — so for "123.45", outputs "1.2345e2" — correct.]
        }
        printf("e%d", whe - 2); // @@ [As above, seems correct.]
    }
}
int main(int argc, char const *argv[])
{
    scanf("%s", in); // @@ [No bounds checking — input could overflow in[101]. But problem likely assumes valid input within limits. Not the cause of compilation error though.]
    fa(in);
    return 0;
}