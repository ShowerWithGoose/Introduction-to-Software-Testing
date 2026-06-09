#include <stdio.h>
#include <string.h>

#define isnum(a) ((a>='0')&&(a<='9'))
#define isa_z(a) ((a>='a')&&(a<='z'))
#define isA_Z(a) ((a>='A')&&(a<='Z'))

char Cen[25000]={0};

int main()
{
    gets(Cen); // @@ [Using 'gets' is unsafe and deprecated; it may cause buffer overflow and is removed in C11. Also, some compilers (like GCC) may not link properly if strict standards are enforced, possibly contributing to compilation issues depending on environment.]
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
                else
                    putchar(Cen[i]); // @@ [Missing 'else' branch to output '-' when expansion condition fails (e.g., same type but Cen[i+1] <= Cen[i-1]). This causes '-' to be omitted in such cases, violating the requirement to output input unchanged when expansion isn't performed.]
            }
            else
                putchar(Cen[i]); // @@ [This 'else' only handles case where types differ, but the missing 'else' above means when types match but Cen[i+1] <= Cen[i-1], the '-' is not printed. The logic structure omits printing '-' in that scenario.]
        }
        else
            putchar(Cen[i]);
    }
    return 0;
}