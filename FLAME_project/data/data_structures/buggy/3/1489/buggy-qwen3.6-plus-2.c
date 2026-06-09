#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<cstdlib> // @@ [Compilation Error: <cstdlib> is a C++ header. In C, standard library functions like itoa (non-standard) or string operations should use <stdlib.h> or be implemented manually. However, the primary issue causing the specific error message "fatal error: cstdlib: No such file or directory" is using a C++ header in a C compiler context. Additionally, itoa is not a standard C function, which will cause linker/compiler errors later, but the immediate fatal error is this include.]
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
            itoa(e, p, 10); // @@ [Logical/Compilation Error: itoa is not a standard C library function and may not be available or declared properly without <stdlib.h> (and even then it's non-standard). This will likely cause an implicit declaration warning or error. More importantly, the logic for calculating exponent and formatting scientific notation is flawed compared to the reference.]
        else
        {
            itoa(e - 1, p, 10); // @@ [Logical/Compilation Error: Same issue with itoa. The logic here attempts to adjust exponent and trim zeros but is complex and error-prone compared to the reference implementation.]
            for (; m[e] == '0' || m[e] == '.'; e--);
            m[e + 1] = 'e';
            m[e + 2] = '\0';
        }
    }
    else
        itoa(e, p, 10); // @@ [Logical/Compilation Error: Same issue with itoa.]
    strcat(m, p);
    puts(m);
    return 0;
}