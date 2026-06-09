#include<stdio.h>
#include<string.h>
char kz(char s[])
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
        else if(('a'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<='z')||('A'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<='Z')||('0'<=s[i-1]&&s[i-1]<s[i+1]&&s[i+1]<='9')) // @@ [The condition uses '<' instead of '<=' for upper bounds (e.g., s[i+1]<'z'), which excludes valid end characters like 'z', 'Z', and '9'. Also, the digit range check uses '1' instead of '9'.]
        {
            c[j]=s[i-1]+1;
            printf("%c",c[j]);
            while(c[j]<s[i+1]-1) // @@ [The loop condition should be c[j] < s[i+1], not c[j] < s[i+1]-1, otherwise it stops one character too early.]
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
} // @@ [Function kz is declared to return char but returns nothing, causing undefined behavior. It should be void.]
int main()
{
    char s[100];
    gets(s); // @@ [gets() is unsafe and deprecated; it may cause buffer overflow. Use fgets() instead. Also, in some environments, gets() may not be available, leading to compilation errors.]
    kz(s);
    return 0;
}