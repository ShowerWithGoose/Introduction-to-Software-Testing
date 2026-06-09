#include <stdio.h>
#include <string.h>

#define isnum(a) ((a>='0')&&(a<='9'))
#define isa_z(a) ((a>='a')&&(a<='z'))
#define isA_Z(a) ((a>='A')&&(a<='Z'))

char Cen[25000]={0};

int main()
{
    gets(Cen); // @@ [gets is deprecated and removed in C11 standard, causing compilation error in modern compilers; should use fgets]
    int i;
    int n=strlen(Cen);
    for(i=0;i<strlen(Cen);i++)
    {
        if(Cen[i]=='-')
        {
            if(((isnum(Cen[i-1]))&&(isnum(Cen[i+1]))) || ((isa_z(Cen[i-1]))&&(isa_z(Cen[i+1]))) || ((isA_Z(Cen[i-1]))&&(isA_Z(Cen[i+1])))) // @@ [Array index out of bounds when i=0 (accessing Cen[-1]) or when i is the last index (accessing Cen[i+1]), causing undefined behavior]
            {
                if(Cen[i+1]>Cen[i-1])
                {
                    int j=Cen[i-1]+1;
                    for(;j<Cen[i+1];j++)
                        putchar(j);
                }
            }
        }
        else // @@ [Logical error: when Cen[i]=='-' but expansion conditions fail, the '-' character is skipped and not printed; should print Cen[i] in this case]
            putchar(Cen[i]);
    }
    return 0;
}