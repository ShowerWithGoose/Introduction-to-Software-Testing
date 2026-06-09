#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<cstdlib> // @@ [Non-standard header <cstdlib> should be <stdlib.h> in C; itoa is not a standard C function]
char n[105],m[105],p[105];
int main()
{
    int i = 0, j, e = -1;
    gets(n); // @@ [gets is unsafe and removed in C11; use fgets instead]
    if (n[i] == '0')
    {
        i += 2;
        for (; n[i] == '0'; i++);
        e = i - 1;
        m[0] = n[i++];
        m[1] = '.';
        for (j = 2; n[i] != NULL; i++,j++) // @@ [n[i] != NULL is incorrect; NULL is a pointer, should compare to '\0']
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
        for (j = 2,i=1; n[i] != NULL; i++) // @@ [n[i] != NULL is incorrect; should compare to '\0']
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
            itoa(e, p, 10); // @@ [itoa is not a standard C function; use sprintf instead]
        else
        {
            itoa(e - 1, p, 10); // @@ [itoa is not a standard C function; use sprintf instead]
            for (; m[e] == '0' || m[e] == '.'; e--);
            m[e + 1] = 'e';
            m[e + 2] = '\0';
        }
    }
    else
        itoa(e, p, 10); // @@ [itoa is not a standard C function; use sprintf instead]
    strcat(m, p);
    puts(m);
    return 0;
}