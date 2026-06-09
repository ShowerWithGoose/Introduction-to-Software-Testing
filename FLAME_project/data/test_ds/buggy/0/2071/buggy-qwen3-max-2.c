#include <stdio.h>
#include <string.h>

#define isnum(a) ((a>='0')&&(a<='9'))
#define isa_z(a) ((a>='a')&&(a<='z'))
#define isA_Z(a) ((a>='A')&&(a<='Z'))

char Cen[25000]={0};

int main()
{
    gets(Cen); // @@ [Using gets() is unsafe and may cause buffer overflow; more importantly, it's deprecated. However, the main logical error is not here.]
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
                    putchar(Cen[i]); // @@ [Missing else clause: when the condition Cen[i+1] > Cen[i-1] is false (e.g., B-e where 'B' > 'e' in ASCII), the '-' should be printed as-is, but currently nothing is printed for the '-' in such cases.]
            }
            else
                putchar(Cen[i]); // @@ [This handles mixed-type cases like B-e correctly by printing '-', but only if the outer if condition fails. However, in cases where types match but Cen[i+1] <= Cen[i-1], the code falls through without printing '-', which is wrong. The missing else after the Cen[i+1]>Cen[i-1] check causes this.]
        }
        else
            putchar(Cen[i]);
    }
    return 0;
}