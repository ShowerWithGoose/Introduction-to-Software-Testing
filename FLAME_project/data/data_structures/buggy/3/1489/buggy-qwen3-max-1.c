#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<cstdlib> // @@ [The compiler does not recognize <cstdlib> in C; this header is from C++. In C, use <stdlib.h> instead. Also, the function itoa() used later is non-standard and may not be available even with <stdlib.h>.]
char n[105],m[105],p[105];
int main()
{
    int i = 0, j, e = -1;
    gets(n); // @@ [gets() is unsafe and deprecated; however, the primary compilation error stems from <cstdlib> and itoa()]
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
            itoa(e, p, 10); // @@ [itoa() is a non-standard function not declared in standard C headers; even if <stdlib.h> were included, it may not be available, causing a compilation error.]
        else
        {
            itoa(e - 1, p, 10); // @@ [Same issue: itoa() is non-standard and undeclared.]
            for (; m[e] == '0' || m[e] == '.'; e--);
            m[e + 1] = 'e';
            m[e + 2] = '\0';
        }
    }
    else
        itoa(e, p, 10); // @@ [Again, itoa() is not a standard C function and will cause a compilation error due to implicit declaration or missing definition.]
    strcat(m, p);
    puts(m);
    return 0;
}