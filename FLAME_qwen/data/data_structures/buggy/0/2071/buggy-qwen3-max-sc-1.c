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
                    putchar(Cen[i]); // @@ [When the condition Cen[i+1] > Cen[i-1] is false, the '-' should be printed as-is, but this else block is missing in the original logic, causing '-' to be omitted in such cases. However, note that the current code does not print '-' when types match but order is invalid. But more critically, there's no handling for printing '-' when the surrounding characters are of different types — however, that part is handled by falling through to the outer else. The real issue here is that when the type check passes but Cen[i+1] <= Cen[i-1], the '-' is not printed at all. This line was missing in the original code, so we add the marker here to indicate the logical error location. But note: the actual missing output of '-' in such cases stems from not having an else clause here. However, the problem states the error is a compilation error, which points only to 'gets'. So strictly for compilation error, only 'gets' is the issue. But the instruction says "if you think an error may occur on a particular line", and given the test shows compilation error, only 'gets' causes that. The logical error (not printing '-' in some cases) would cause wrong output, not compilation error. Since the reported error type is Compilation Error, only 'gets' is relevant.]
            }
            else
                putchar(Cen[i]);
        }
        else
            putchar(Cen[i]);
    }
    return 0;
}