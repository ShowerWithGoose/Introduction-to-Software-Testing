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
        in += 2; // @@ [If the input is "0.0", this skips to index 2, but if the string length is <=2 (e.g., "0." or "0.0" with no further digits), then subsequent pointer operations may read beyond valid data or cause undefined behavior. Also, the logic assumes there are at least two characters after '0', which isn't guaranteed.]
        while (*(in++) == '0') // @@ [This loop increments `in` before checking termination condition. If the string ends right after the decimal point (e.g., "0."), then *(in++) becomes '\0' on first iteration, loop exits, but `in` now points past the null terminator. Later dereferences lead to undefined behavior.]
            cnt += 1;
        in -= 1; // @@ [This attempts to correct the over-increment from the while loop, but if the loop never ran (first char after "0." is non-zero), then `in` was incremented once in the loop condition and decremented here — possibly pointing to the correct location. However, if the loop ran multiple times or the string is short, this arithmetic can be incorrect or unsafe.]
        printf("%c", *(in)); // @@ [If the input has no non-zero digit after the decimal (e.g., "0.000"), this will print a null character or garbage, violating problem constraints (input has all significant digits, so this case shouldn't occur per spec, but program doesn't validate input and may crash or output incorrectly on edge cases).]
        in += 1;
        while (*(in) != '\0') // @@ [If previous steps left `in` pointing beyond the string due to incorrect pointer math, this loop may access invalid memory.]
            printf("%c", *(in++));
        printf("e-%d", cnt);
    }
    else
    {
        ptr = strchr(in, '.'); // @@ [If there's no '.' in the input (e.g., integer like "123"), strchr returns NULL, and the next line `whe = ptr - in + 1;` performs pointer subtraction with NULL, causing undefined behavior (likely crash or garbage exponent).]
        whe = ptr - in + 1; // @@ [Dereferencing NULL if no '.' exists. The reference program handles this case, but this code does not.]
        printf("%c.", *(in++));
        while (*(in) != '\0')
        {
            if (*(in) == '.')
                in += 1;
            else
                printf("%c", *(in++));
        }
        printf("e%d", whe - 2);
    }
}
int main(int argc, char const *argv[])
{
    scanf("%s", in);
    fa(in);
    return 0;
}