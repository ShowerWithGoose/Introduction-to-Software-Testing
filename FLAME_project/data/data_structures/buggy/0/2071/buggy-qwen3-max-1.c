#include <stdio.h>
#include <string.h>

#define isnum(a) ((a>='0')&&(a<='9'))
#define isa_z(a) ((a>='a')&&(a<='z'))
#define isA_Z(a) ((a>='A')&&(a<='Z'))

char Cen[25000]={0};

int main()
{
    gets(Cen); // @@ [Using gets() is unsafe and may cause buffer overflow; however, the main logical error is not here. The critical issue is that when expansion conditions are not met (e.g., mixed case like 'B-e'), the '-' should be printed, but the current code skips printing '-' entirely in such cases.]
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
                {
                    putchar(Cen[i]); // @@ [Missing else clause: when the characters are of the same type but Cen[i+1] <= Cen[i-1], the '-' should be printed as-is, but currently it's skipped. However, even more critically, when the types differ (like 'B' and 'e'), the code does not print '-', which violates the requirement.]
                }
            }
            else
            {
                putchar(Cen[i]); // @@ [This else block is missing in the original code! Without it, when the '-' is between different types (e.g., 'B' and 'e'), the '-' is never printed, leading to output "Be" instead of "B-e".]
            }
        }
        else
            putchar(Cen[i]);
    }
    return 0;
}