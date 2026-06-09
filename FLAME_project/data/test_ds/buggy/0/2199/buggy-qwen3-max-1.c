#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include<windows.h> // @@ [The program includes windows.h which is not available in standard C environments and causes a compilation error. This header is unnecessary for the problem requirements.]
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
    gets(src); // @@ [The function 'gets' is unsafe and has been removed from modern C standards. It should be replaced with 'fgets' to prevent buffer overflow. However, this is a runtime safety issue, not the cause of the current compilation error.]
    expand(src, dest);
    puts(dest);
    system("pause"); // @@ [The function 'system' requires including <stdlib.h>, and 'system("pause")' is platform-specific (Windows). While this may cause a warning or linker error on non-Windows systems, the primary compilation error is due to the missing windows.h.]
    return 0;
}