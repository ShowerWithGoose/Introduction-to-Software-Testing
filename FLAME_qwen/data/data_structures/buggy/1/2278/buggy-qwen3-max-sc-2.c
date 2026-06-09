#include<stdio.h>
#include<string.h>
char a[85];
char b[85];
int main()
{
    scanf("%s",&a); // @@ [Using &a is incorrect because 'a' is already an array (decays to pointer). Should be scanf("%s", a);]
    scanf("%s",&b); // @@ [Same error: &b should be b. Passing address of array instead of array itself leads to type mismatch and undefined behavior.]
    int l1=strlen(a);
    int l2=strlen(b);
    {
        
    }
}