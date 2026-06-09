#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char Pformula[514]= {},formula[114]= {};
char *ptr = formula;
int ReadANumber();
int main()
{
    #ifdef ACU
    freopen("in.txt", "r", stdin);
    #endif
    long long int nums[1926] = {};
    char op = 0;
    int counter = 0,temp = 0;
    gets(Pformula);
    for (size_t i = 0; i < strlen(Pformula); i++)//去空格
    {
        if (Pformula[i] != ' ')
        {
            formula[temp++] = Pformula[i];
        }
    }
    nums[0] = ReadANumber();
    while ((op = *(ptr++)) != '=')
    {
        if (op == '+' || op == '-')
        {
            counter ++;
            nums[counter] = (op == '+') ? ReadANumber(): (-ReadANumber());
        }
        else
        {
            if(op == '*')
            {
                nums[counter] *= ReadANumber();
            }
            else
            {
                nums[counter] /= ReadANumber();
            }
        }
    }
    for (size_t i = 1; i <= counter; i++)
    {
        nums[0] += nums[i];
    }
    printf("%d",nums[0]);
    return 0;
}


int ReadANumber()
{
    int x = 0;
    char a = 0;
    a = *ptr;
    
    while (a<='9' && a>='0')
    {
        ptr++;
        x *= 10, x += a - '0';
        a = *ptr;
    }
    return x;
}
