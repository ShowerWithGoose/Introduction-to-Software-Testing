#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include<windows.h> // @@ [Compilation Error: The header file 'windows.h' is not available in standard Linux/Unix environments where this code is likely being compiled, causing a fatal error. It is also unnecessary for the logic of the program.]
#define LEN 1024
int il(char a)
{
    if (a >= 'a' && a <= 'z')
        return 1;
    else
        return 0;
}
int iu(char a)
{
    if (a >= 'A' && a <= 'Z')
        return 1;
    else
        return 0;
}
int id(char a)
{
    if (a >= '0' && a <= '9')
        return 1;
    else
        return 0;
}
int isexpand(char start, char end)
{
    if (il(start) && il(end) && start < end)
        return 1;
    if (iu(start) && iu(end) && start < end)
        return 1;
    if (id(start) && id(end) && start < end)
        return 1;
    return 0;
}
char *expand(const char *src, char *dest)
{
    char ch;
    int i, j;
    for (i = 0, j = 0; src[i] != '\0'; i++)
    {
        dest[j++] = src[i];
        if (src[i + 1] == '-')
        {
            if (isexpand(src[i], src[i + 2]))
            {
                for (ch = src[i] + 1; ch < src[i + 2]; ch++)
                    dest[j++] = ch;
                i++;
            }
        }
    }
    dest[j] = '\0';
    return dest;
}
int main()
{
    char src[LEN], dest[LEN];
    gets(src);
    expand(src, dest);
    puts(dest);
    system("pause"); // @@ [Runtime/Compilation Error: 'system("pause")' is Windows-specific and will fail or cause issues on non-Windows systems. It should be removed for portability and correctness in standard judging environments.]
    return 0;
}