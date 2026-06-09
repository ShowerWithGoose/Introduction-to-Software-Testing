#include <stdio.h>
#include <string.h>

#define isnum(a) ((a>='0')&&(a<='9'))
#define isa_z(a) ((a>='a')&&(a<='z'))
#define isA_Z(a) ((a>='A')&&(a<='Z'))

char Cen[25000]={0};

int main()
{
    gets(Cen); // @@ gets() is removed in C11 standard and causes compilation error in modern environments; use fgets() instead.
    int i;
    int n=strlen(Cen);
    for(i=0;i<strlen(Cen);i++)
    {
        if(Cen[i]=='-')
        {
            if(((isnum(Cen[i-1]))&&(isnum(Cen[i+1]))) || ((isa_z(Cen[i-1]))&&(isa_z(Cen[i+1]))) || ((isA_Z(Cen[i-1]))&&(isA_Z(Cen[i+1])))) // @@ Accessing Cen[i-1] when i=0 causes out-of-bounds array access; also Cen[i+1] may be out-of-bounds if '-' is the last character.
            {
                if(Cen[i+1]>Cen[i-1]) // @@ If this condition is false, the '-' character is not printed, violating the requirement to output the input unchanged.
                {
                    int j=Cen[i-1]+1;
                    for(;j<Cen[i+1];j++)
                        putchar(j);
                }
            }
            else // @@ This else only handles type mismatch; missing logic to print '-' when types match but right <= left.
                putchar(Cen[i]);
        }
        else
            putchar(Cen[i]);
    }
    return 0;
}