#include <stdio.h>
#include <string.h>

#define isnum(a) ((a>='0')&&(a<='9'))
#define isa_z(a) ((a>='a')&&(a<='z'))
#define isA_Z(a) ((a>='A')&&(a<='Z'))

char Cen[25000]={0};

int main()
{
    gets(Cen);
    int i;
    int n=strlen(Cen);
    for(i=0;i<strlen(Cen);i++)
    {
        if(Cen[i]=='-')
        {
            if(((isnum(Cen[i-1]))&&(isnum(Cen[i+1]))) || ((isa_z(Cen[i-1]))&&(isa_z(Cen[i+1]))) || ((isA_Z(Cen[i-1]))&&(isA_Z(Cen[i+1]))))
            {
                if(Cen[i+1]>Cen[i-1])
                {
                    int j=Cen[i-1]+1;
                    for(;j<Cen[i+1];j++)
                        putchar(j);
                }
                else // @@ Missing handling for case when characters are same type but not in ascending order (e.g., 'B-e' where 'B' is uppercase and 'e' is lowercase, but the type check fails earlier; however, for same type like 'e-B', the condition Cen[i+1]>Cen[i-1] is false, and the code should output the '-' unchanged, but it currently does nothing, causing the '-' to be omitted)
                {
                    putchar(Cen[i]); // @@ This line is missing; the original code does not output the '-' when the expansion condition is not met (e.g., when characters are same type but not in ascending order), leading to the '-' being dropped.
                }
            }
            else // @@ Missing handling for case when characters around '-' are of different types (e.g., 'B-e' where 'B' is uppercase and 'e' is lowercase), the code should output the '-' unchanged, but it currently does nothing, causing the '-' to be omitted.
            {
                putchar(Cen[i]); // @@ This line is missing; the original code does not output the '-' when the characters are of different types, leading to the '-' being dropped.
            }
        }
        else
            putchar(Cen[i]);
    }
    return 0;
}