#include <stdio.h>
#include <string.h>

#define isnum(a) ((a>='0')&&(a<='9'))
#define isa_z(a) ((a>='a')&&(a<='z'))
#define isA_Z(a) ((a>='A')&&(a<='Z'))

char Cen[25000]={0};

int main()
{
    gets(Cen); // @@ [Using gets() is unsafe and may cause buffer overflow; more importantly, the problem requires reading from stdin but the bigger issue is handling edge cases like '-' at start/end]
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
                    putchar(Cen[i]); // @@ [Missing else clause: when the condition Cen[i+1] > Cen[i-1] fails, the '-' should be printed as-is, but currently it's skipped entirely]
            }
            else
                putchar(Cen[i]); // @@ [This handles mixed-type cases correctly, but without the above else, cases like 'd-a' (same type but decreasing) incorrectly output nothing for the '-']
        }
        else
            putchar(Cen[i]);
    }
    return 0;
}