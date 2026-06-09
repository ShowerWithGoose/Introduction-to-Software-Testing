#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include<windows.h> // @@ [Including <windows.h> is unnecessary and non-portable; more critically, the program uses gets() which is unsafe and may be unavailable in modern compilers, leading to compilation errors or warnings treated as errors. Additionally, system("pause") is platform-specific and not standard C.]
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
    gets(src); // @@ [The function 'gets' has been removed from the C standard library since C11 due to security vulnerabilities (buffer overflow risk). Modern compilers either don't support it or require special flags to enable it, causing a compilation error.]
    expand(src, dest);
    puts(dest);
    system("pause"); // @@ [system("pause") is platform-dependent (Windows-only) and not part of standard C; while this may not cause a compilation error on Windows with certain compilers, combined with the use of gets(), it contributes to non-portability and potential build failures in strict environments.]
    return 0;
}