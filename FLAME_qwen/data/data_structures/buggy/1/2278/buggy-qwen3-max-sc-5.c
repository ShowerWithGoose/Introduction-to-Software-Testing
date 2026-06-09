#include<stdio.h>
#include<string.h>
char a[85];
char b[85];
int main()
{
    scanf("%s",&a); // @@ Taking address of array 'a' is redundant and incorrect; should be 'scanf("%s", a);' because 'a' already decays to a pointer.
    scanf("%s",&b); // @@ Same issue: taking address of array 'b'; should be 'scanf("%s", b);'
    int l1=strlen(a);
    int l2=strlen(b);
    {
        
    }
}