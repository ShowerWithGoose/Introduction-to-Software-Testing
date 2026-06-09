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
            if(((isnum(Cen[i-1]))&&(isnum(Cen[i+1]))) || ((isa_z(Cen[i-1]))&&(isa_z(Cen[i+1]))) || ((isA_Z(Cen[i-1]))&&(isA_Z(Cen[i+1])))) @@ // Accessing Cen[i-1] and Cen[i+1] without bounds check may cause out-of-bounds when i=0 or i=n-1. Also missing else clause: if this condition fails, the '-' should be printed, but it is not.
            {
                if(Cen[i+1]>Cen[i-1]) @@ // Missing else clause: if order condition fails, the '-' should be printed, but it is not.
                {
                    int j=Cen[i-1]+1;
                    for(;j<Cen[i+1];j++)
                        putchar(j);
                }
            }
        }
        else
            putchar(Cen[i]);
    }
    return 0;
}