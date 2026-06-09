#include <stdio.h>
#include <string.h>

#define isnum(a) ((a>='0')&&(a<='9'))
#define isa_z(a) ((a>='a')&&(a<='z'))
#define isA_Z(a) ((a>='A')&&(a<='Z'))

char Cen[25000]={0};

int main()
{
    gets(Cen); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and may cause compilation errors with modern compilers. Use 'fgets' instead.]
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
                    putchar(Cen[i]); // @@ [When the condition Cen[i+1] > Cen[i-1] is false, the '-' should be printed, but this else block is missing in the original logic, causing '-' to be skipped entirely in such cases.]
            }
            else
                putchar(Cen[i]); // @@ [This handles cases where types differ, but without the above else, overlapping conditions may skip printing '-'. However, the main issue is the missing else for the Cen[i+1] > Cen[i-1] check.]
        }
        else
            putchar(Cen[i]);
    }
    return 0;
}