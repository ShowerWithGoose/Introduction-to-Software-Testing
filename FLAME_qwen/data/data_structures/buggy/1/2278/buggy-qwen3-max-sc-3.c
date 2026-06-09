#include<stdio.h>
#include<string.h>
char a[85];
char b[85];
int main()
{
    scanf("%s",&a); // @@ Using &a is incorrect because 'a' is already an array (decays to pointer). Should be scanf("%s", a);
    scanf("%s",&b); // @@ Using &b is incorrect because 'b' is already an array (decays to pointer). Should be scanf("%s", b);
    int l1=strlen(a);
    int l2=strlen(b);
    {
        
    }
}