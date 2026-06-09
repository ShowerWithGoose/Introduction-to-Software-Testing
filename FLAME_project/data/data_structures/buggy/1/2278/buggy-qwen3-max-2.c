#include<stdio.h>
#include<string.h>
char a[85];
char b[85];
int main()
{
    scanf("%s",&a); // @@ [The problem expects an integer N as input, but this reads a string into 'a'. Also, using %s with &a is incorrect; it should be just 'a' since arrays decay to pointers.]
    scanf("%s",&b); // @@ [The problem only requires one integer input, but this reads a second string into 'b', which is unnecessary and causes incorrect behavior.]
    int l1=strlen(a);
    int l2=strlen(b);
    {
        
    }
}