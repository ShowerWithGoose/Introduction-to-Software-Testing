#include<stdio.h>
#include<string.h>
char a[85]; // @@ Not used properly; should be an integer variable.
char b[85]; // @@ Unnecessary array.
int main()
{
    scanf("%s",&a); // @@ Error: should read an integer N, not a string. Also, using %s with &a is valid but not appropriate.
    scanf("%s",&b); // @@ Error: no second input provided; causes undefined behavior or blocking.
    int l1=strlen(a); // @@ Computes length of string, but N is needed as integer; not used.
    int l2=strlen(b); // @@ Not used.
    { // @@ Error: missing permutation generation logic and output; this block does nothing.
        
    } // @@ Error: empty block, no output produced.
}