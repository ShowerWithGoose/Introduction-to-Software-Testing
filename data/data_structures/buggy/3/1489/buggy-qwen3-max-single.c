#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<cstdlib>
char n[105],m[105],p[105];
int main()
{
    int i = 0, j, e = -1;
    gets(n); // @@ [The function 'gets' is unsafe and deprecated; many compilers (especially in C11 and later) remove it entirely, causing a compilation error. Use 'fgets' instead.]
    if (n[i] == '0')
    {
        i += 2;
        for (; n[i] == '0'; i++);
        e = i - 1;
        m[0] = n[i++];
        m[1] = '.';
        for (j = 2; n[i] != NULL; i++,j++)
            m[j] = n[i];
        if (j == 2)
        {
            m[1] = 'e';
            m[2] = '-';
        }
        else
        {
            m[j] = 'e';
            m[j + 1] = '-';
        }
    }
    else 
    {
        m[0] = n[0];
        m[1] = '.';
        for (j = 2,i=1; n[i] != NULL; i++)
        {
            if(n[i]=='.')
                e = i-1;
            else
                m[j++] = n[i];            
        }
        if (j == 2)
            m[1] = 'e';
        else
            m[j] = 'e';
    }
    if (e == -1)
    {
        e = strlen(m)-2;
        if (e ==0 )
            itoa(e, p, 10); // @@ ['itoa' is not part of the standard C library and may not be available on all compilers (e.g., GCC on Linux), leading to a compilation error. Use 'sprintf' instead.]
        else
        {
            itoa(e - 1, p, 10); // @@ [Same issue: 'itoa' is non-standard and causes compilation failure on many systems.]
            for (; m[e] == '0' || m[e] == '.'; e--);
            m[e + 1] = 'e';
            m[e + 2] = '\0';
        }
    }
    else
        itoa(e, p, 10); // @@ [Again, 'itoa' is non-standard and will cause a compilation error on platforms that don't support it.]
    strcat(m, p);
    puts(m);
    return 0;
}