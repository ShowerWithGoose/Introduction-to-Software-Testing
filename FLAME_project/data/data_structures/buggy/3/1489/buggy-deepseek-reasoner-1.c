#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<cstdlib> // @@ [In C, the correct header is <stdlib.h>. <cstdlib> is a C++ header and is not found, causing compilation error.]
char n[105],m[105],p[105];
int main()
{
    int i = 0, j, e = -1;
    gets(n);
    if (n[i] == '0')
    {
        i += 2;
        for (; n[i] == '0'; i++);
        e = i - 1;
        m[0] = n[i++];
        m[1] = '.';
        for (j = 2; n[i] != NULL; i++,j++) // @@ [NULL is a pointer constant; should compare with '\0' for end-of-string.]
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
        for (j = 2,i=1; n[i] != NULL; i++) // @@ [NULL is a pointer constant; should compare with '\0'.]
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
            itoa(e, p, 10); // @@ [itoa is a non-standard function; use sprintf or snprintf instead.]
        else
        {
            itoa(e - 1, p, 10); // @@ [itoa is non-standard; same issue.]
            for (; m[e] == '0' || m[e] == '.'; e--);
            m[e + 1] = 'e';
            m[e + 2] = '\0';
        }
    }
    else
        itoa(e, p, 10); // @@ [itoa is non-standard; same issue.]
    strcat(m, p);
    puts(m);
    return 0;
}