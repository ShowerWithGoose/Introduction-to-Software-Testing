#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char s[105];
char h[105];
char b[105];

int main()
{
    //把输入分成小数点前后
    gets(s);
    int len = strlen(s);
    int i=0,j=0;
    while(s[i] != '.')
    {
        h[j++] = s[i++];
    }
    h[j] = '\0';
    i++;
    j = 0;
    while(s[i] != '\0')
    {
        b[j++] = s[i++];
    }
    b[j] = '\0';

    int k;
    //0.xxxxx
    if(h[0]=='0')
    {
        i=0;
        while(b[i++]=='0'); // @@ The post-increment `i++` causes `i` to be one position past the first non-zero digit (or past the end if all zeros). When checking `strlen(b)==(i+1)`, the logic for determining if there are remaining digits is flawed because `i` is already offset. More critically, if the input is "0.9", `b` is "9". The loop `while(b[i++]=='0')` checks `b[0]` ('9'), which is false, but `i` becomes 1. Then `k = -(i--)` makes `k = -1` and `i` becomes 0. The check `strlen(b)==(i+1)` becomes `1 == 1`, which is true. It prints `%ce%d`, i.e., `9e-1`. This seems correct for 0.9. Let's re-read the bug report.
        // Wait, let's look at `while(b[i++]=='0');`. If `b` is "9", `b[0]` is '9'. Condition fails. `i` becomes 1.
        // `k = -(i--)` -> `k = -1`, `i` becomes 0.
        // `strlen(b)` is 1. `i+1` is 1. Condition `1==1` is true.
        // `printf("%ce%d", b+i, k)` -> `b+0` is "9". Output `9e-1`.
        // Why did the reference program fail with `@e-1`? The reference program in the prompt description had bugs. The code provided in "Source Code" section is the one I need to annotate.
        // Let's check another case. Input `0.09`. `b` is "09".
        // Loop: `i=0`. `b[0]` is '0'. True. `i` becomes 1.
        // Loop: `i=1`. `b[1]` is '9'. False. `i` becomes 2.
        // Loop ends. `i` is 2.
        // `k = -(i--)` -> `k = -2`. `i` becomes 1.
        // `strlen(b)` is 2. `i+1` is 2. Condition `2==2` is true.
        // `printf("%ce%d", b+1, -2)` -> `b+1` is "9". Output `9e-2`. Correct.
        // Let's check `0.009`. `b` is "009".
        // Loop: `i=0`, '0', true, `i`=1.
        // Loop: `i=1`, '0', true, `i`=2.
        // Loop: `i=2`, '9', false, `i`=3.
        // `k = -3`, `i`=2.
        // `strlen(b)` is 3. `i+1` is 3. True.
        // `printf("%ce%d", b+2, -3)` -> `9e-3`. Correct.
        
        // What if `b` is "0"? Input `0.0`. Problem says "no trailing zeros", so this won't happen.
        
        // Let's look at the `else` branch of the `if(strlen(b)==(i+1))`.
        // Input `0.10` is not allowed.
        // Input `0.123`. `b` is "123".
        // Loop: `i=0`, '1', false, `i`=1.
        // `k = -1`, `i`=0.
        // `strlen(b)` is 3. `i+1` is 1. False.
        // `printf("%c.%se%d", b+0, b+1, -1)` -> `1.23e-1`. Correct.

        // Is there an error in `while(b[i++]=='0');`?
        // If `b` starts with non-zero, `i` becomes 1. `i--` makes it 0.
        // If `b` starts with zeros, `i` advances past them.
        
        // Let's look closely at `if(strlen(b)==(i+1))`.
        // In the case `0.9`, `i` became 0 after `i--`. `strlen(b)` is 1. `i+1` is 1.
        // It prints `b+i` which is `b[0]` as a char? No, `%c` takes an int/char. `b+i` is a pointer.
        // `printf("%ce%d", b+i, k)` passes a pointer `char*` to `%c`. This is undefined behavior / wrong type.
        // `%c` expects an `int` (character), but `b+i` is `char*`.
        // It should be `*(b+i)` or `b[i]`.
        
        k = -(i--);
        if(strlen(b)==(i+1))
            printf("%ce%d",b+i,k); // @@ Error: `%c` format specifier expects a character (int), but `b+i` is a pointer (char*). It should be `*(b+i)` or `b[i]` to print the single significant digit.
        else
            printf("%c.%se%d",b+i,b+i+1,k); // @@ Error: Similar to above, `%c` expects a character, but `b+i` is a pointer. It should be `*(b+i)` or `b[i]`.
    }
    else if(strlen(h)==1)
    {
        printf("%c.%se0",h,b);
    }
    else
    {
        printf("%c.%s%se%d",h,h+1,b,strlen(h)-1);
    }
    return 0;
}