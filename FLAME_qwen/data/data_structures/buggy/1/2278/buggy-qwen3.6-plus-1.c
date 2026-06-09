#include<stdio.h>
#include<string.h>
char a[85];
char b[85];
int main()
{
    scanf("%s",&a); // @@ Incorrect argument type for %s format specifier; should pass 'a' instead of '&a'
    scanf("%s",&b); // @@ Incorrect argument type for %s format specifier; should pass 'b' instead of '&b'
    int l1=strlen(a); // @@ Variable declaration after executable statement causes compilation error in C89/C90 standards
    int l2=strlen(b); // @@ Variable declaration after executable statement causes compilation error in C89/C90 standards
    {
        
    }
}