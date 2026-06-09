#include<stdio.h>
int main()
{
    char c[105],d[105];
    int n;
    gets(c);
    if(c[0]=='0')
    {
        for(int i=0;c[i]=='0'||c[i]=='.';i++) // @@ [This loop condition is flawed: it stops only when encountering a non-zero and non-dot character, but starts at i=0 where c[0] is '0', so it will immediately check c[0]=='0' -> true, then increment i to 1, check c[1]=='.' (likely true), then i=2, and so on. However, the loop does not break correctly when a non-zero digit is found—it actually continues until the condition fails, meaning `n` ends up being the index *after* the last zero or dot, not the first significant digit. Also, if the input has no non-zero digits after zeros (which shouldn't happen per problem, but logic is still wrong), it may go out of bounds.]
        {
            n=i;
        }
        n=n+1; // @@ [This incorrectly shifts `n` further right. If the loop exits with `n` already pointing to the first non-zero digit (which it doesn't due to prior error), adding 1 would skip it. In reality, due to the loop logic, `n` is the last index where c[i] was '0' or '.', so n+1 might be correct—but the loop itself doesn't track the first non-zero properly.]
        if(c[n+1]=='\0') // @@ [This checks if there's only one significant digit left, but uses `n+1`, which may be beyond the string length. Also, should check `c[n]` is last, not `c[n+1]`.]
            printf("%ce-%d",c[n],n-1);
        else
        {
            printf("%c.",c[n]);
            for(int i=n+1;c[i]!='\0';i++)
                printf("%c",c[i]);
            printf("e-%d",n-1);
        }
    }
    else
    {
        for(int i=0;c[i]!='.';i++) // @@ [This loop finds the position of the decimal point by scanning until '.', but stores `n = i` each time. When loop exits, `i` is the index of '.', but `n` is `i-1` because the last assignment happens at i-1 before condition fails. So `n` becomes index of last digit before decimal, which is correct for count, but logic is indirect and error-prone.]
        {
            n=i;
        }
        n=n+1; // @@ [Now `n` becomes the index of the decimal point. But then...]
        printf("%c",c[n-1]); // @@ [This prints the first digit (c[0]), which is correct, but then...]
        for(int i=1;c[i]!='\0';i++) // @@ [This prints from c[1] to end, including the decimal point and all digits. So for "87899.999...", it prints "8" then "7899.999..." → "87899.999...", which is wrong. It should print only one digit before decimal, then a dot, then the rest of the significant digits without the original decimal point. This line causes the entire mantissa to be printed as-is after the first digit, leading to output like "87899.999...e4" instead of "8.7899...e4".]
            printf("%c",c[i]);
        printf("e%d",n-1);
    }
    return 0;
}