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
                else // @@ [When the character after '-' is not greater than the one before, the '-' should be output unchanged, but here it is not printed, causing the '-' to be omitted. For input "B-e", 'e' is not greater than 'B', so the '-' should be output, but it is skipped.]
                {
                    putchar(Cen[i]); // @@ [Missing this line: the '-' character should be printed when expansion conditions are not met (e.g., different types or not greater), but the code only prints it in the else branch of the outer if, not here.]
                }
            }
            else // @@ [When the characters around '-' are not of the same type, the '-' should be output unchanged, but here it is not printed, causing the '-' to be omitted. For input "B-e", 'B' and 'e' are different types (uppercase vs lowercase), so the '-' should be output.]
            {
                putchar(Cen[i]); // @@ [Missing this line: the '-' character should be printed when the types don't match, but the code only prints it in the else branch of the outer if, not here.]
            }
        }
        else
            putchar(Cen[i]);
    }
    return 0;
}