#include<stdio.h>
#include<string.h>
char kz(char s[]) // @@ [Function return type is char but no value is returned; should be void]
{
    char c[100];
    int j=0; 
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]!='-')
        {
            c[j]=s[i];
            printf("%c",c[j]);
            j++;
        }
        else if(('a'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<'z')||('A'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<'Z')||('0'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<'1')) // @@ [Boundary conditions are incorrect: should use <= 'z', <= 'Z', <= '9'; also '1' is wrong, should be '9']
        {
            c[j]=s[i-1]+1;
            printf("%c",c[j]);
            while(c[j]<s[i+1]-1) // @@ [Loop condition is off by one; should be c[j] < s[i+1]]
            {
                j++;
                c[j]=c[j-1]+1;
                printf("%c",c[j]);
            }
            j++;
        }
        else
        {
            c[j]=s[i];
            printf("%c",c[j]);
            j++;
        }
    }
} // @@ [Missing return statement for non-void function]
int main()
{
    char s[100];
    gets(s); // @@ [gets() is unsafe and deprecated; may cause buffer overflow, but more critically, in many environments it's removed causing compilation error]
    kz(s);
    return 0;
}