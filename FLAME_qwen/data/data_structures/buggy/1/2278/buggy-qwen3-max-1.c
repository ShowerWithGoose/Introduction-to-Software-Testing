#include<stdio.h>
#include<string.h>
char a[85];
char b[85];
int main()
{
    scanf("%s",&a); // @@ Taking address of array 'a' is redundant and may cause undefined behavior; should be 'scanf("%s", a);'
    scanf("%s",&b); // @@ Taking address of array 'b' is redundant and may cause undefined behavior; should be 'scanf("%s", b);'
    int l1=strlen(a);
    int l2=strlen(b);
    {
        
    }
}