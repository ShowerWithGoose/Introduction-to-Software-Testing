#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<cstdlib>
char n[105],m[105],p[105];
int main()
{
    int i = 0, j, e = -1;
    gets(n); // @@ [Using 'gets' is unsafe and deprecated; may cause compilation error in modern compilers due to removal from standard library]
    if (n[i] == '0')
    {
        i += 2; // @@ [Incorrectly skips two characters after leading '0'; should skip only the '0' and the decimal point, but assumes input always starts with "0."]
        for (; n[i] == '0'; i++);
        e = i - 1;
        m[0] = n[i++];
        m[1] = '.';
        for (j = 2; n[i] != NULL; i++,j++)
            m[j] = n[i];
        if (j == 2)
        {
            m[1] = 'e';
            m[2] = '-'; // @@ [Missing exponent digits after '-', leads to malformed output like "5e-"]
        }
        else
        {
            m[j] = 'e';
            m[j + 1] = '-'; // @@ [Same issue: appends '-' without actual exponent value]
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
            m[1] = 'e'; // @@ [Overwrites '.' with 'e', producing output like "5e" instead of "5e0" or similar]
        else
            m[j] = 'e';
    }
    if (e == -1)
    {
        e = strlen(m)-2; // @@ [Incorrect exponent calculation when no decimal point was found in non-zero-leading case]
        if (e ==0 )
            itoa(e, p, 10); // @@ ['itoa' is non-standard and may not be available, causing compilation error]
        else
        {
            itoa(e - 1, p, 10); // @@ ['itoa' is non-standard and may not be available, causing compilation error]
            for (; m[e] == '0' || m[e] == '.'; e--); // @@ [This loop modifies 'e' used as index but logic is flawed and may access invalid memory]
            m[e + 1] = 'e';
            m[e + 2] = '\0';
        }
    }
    else
        itoa(e, p, 10); // @@ ['itoa' is non-standard and may not be available, causing compilation error]
    strcat(m, p);
    puts(m);
    return 0;
}