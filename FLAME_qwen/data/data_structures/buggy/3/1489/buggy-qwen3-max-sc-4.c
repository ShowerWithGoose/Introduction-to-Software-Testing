#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<cstdlib>
char n[105],m[105],p[105];
int main()
{
    int i = 0, j, e = -1;
    gets(n); @@ [The function 'gets' is unsafe and deprecated; many compilers no longer support it, leading to compilation errors. Use 'fgets' instead.]
    if (n[i] == '0')
    {
        i += 2; @@ [Incorrectly skips two characters after '0'; should skip only the '0' and the decimal point (i.e., i = 1), not i += 2. This causes wrong parsing when input starts with "0."]
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
            itoa(e, p, 10); @@ ['itoa' is not part of the standard C library and may not be available in all compilers (e.g., GCC), causing a compilation error. Use 'sprintf' instead.]
        else
        {
            itoa(e - 1, p, 10); @@ [Same issue: 'itoa' is non-standard and may cause compilation failure.]
            for (; m[e] == '0' || m[e] == '.'; e--);
            m[e + 1] = 'e';
            m[e + 2] = '\0';
        }
    }
    else
        itoa(e, p, 10); @@ [Again, 'itoa' is non-standard and leads to compilation error on many systems.]
    strcat(m, p);
    puts(m);
    return 0;
}