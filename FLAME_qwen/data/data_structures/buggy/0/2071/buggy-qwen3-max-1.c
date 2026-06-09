#include <stdio.h>
#include <string.h>

#define isnum(a) ((a>='0')&&(a<='9'))
#define isa_z(a) ((a>='a')&&(a<='z'))
#define isA_Z(a) ((a>='A')&&(a<='Z'))

char Cen[25000]={0};

int main()
{
    gets(Cen); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors with modern compilers that do not support it by default.]
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
                    putchar(Cen[i]); // @@ [When the condition Cen[i+1] > Cen[i-1] is false, the '-' should be printed as-is, but this else block is missing in the original code, causing '-' to be omitted in such cases. However, note that the current structure does not output '-' when expansion conditions are met but the order is invalid. But more critically, there's no handling for cases where '-' appears at the start or end of string (i.e., i-1 or i+1 out of bounds), which leads to undefined behavior. Yet the immediate compilation error is due to 'gets'.]
            }
            else
                putchar(Cen[i]);
        }
        else
            putchar(Cen[i]);
    }
    return 0;
}