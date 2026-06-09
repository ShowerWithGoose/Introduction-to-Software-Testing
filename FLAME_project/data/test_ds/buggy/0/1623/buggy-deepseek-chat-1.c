#include <stdio.h>
int f(char x)
{
    if(x>='0'&&x<='9')
    {
        return 1;
    }
    if(x>='a'&&x<='z')
    {
        return 2;
    }
    else
        return 3; // @@ [Error: This function incorrectly returns 3 for uppercase letters, but should return 3 only for uppercase letters. However, the else clause causes it to return 3 for any character that is not a digit or lowercase letter, including '-', spaces, etc. The reference program returns 0 for invalid characters, and 3 only for uppercase letters. This causes incorrect type checking in ff().]
}
int ff(char a,char b)
{
    if(f(a)==f(b))
    {
        return 1; // @@ [Error: This function does not return a value when f(a) != f(b), leading to undefined behavior. It should return 0 in that case.]
    }
}
int main()
{
    char a[10000];
    gets(a); // @@ [Error: gets() is unsafe and deprecated. It can cause buffer overflow. Use fgets() instead.]
    int i;
    for(i=0; a[i]!='\0'; i++)
    {
        if(a[i+1]!='-')
        {
            printf("%c",a[i]);
        }
        if(a[i+1]=='-')
        {
            if(ff(a[i],a[i+2])==1&&(int)a[i+2]>(int) a[i])
            {
                while(a[i]!=a[i+2])
                {
                    printf("%c",a[i]);
                    a[i]=a[i]+1; // @@ [Error: Modifying a[i] in the loop corrupts the original string and causes incorrect behavior. The loop should use a separate variable for the expansion character, not modify the array element.]
                }
                i=i+1; // @@ [Error: This increments i by 1, but the loop's for statement also increments i by 1, so i is incremented twice, skipping the character after '-'. It should be i=i+2 to skip both '-' and the next character, or restructure the logic.]
            }
            else
            {
                printf("%c",a[i]);
            }

        }
    }
    return 0;

}