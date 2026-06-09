#include<stdio.h>
#include<string.h>
char a[85]; // @@ Should be int NUM[15] and char POS[15] for permutation generation.
char b[85]; // @@ Unused variable; not needed for the required algorithm.
int main()
{
    scanf("%s",&a); // @@ Input format is an integer N, not a string. Should read into an int variable.
    scanf("%s",&b); // @@ Second read not needed; will cause undefined behavior for single integer input.
    int l1=strlen(a); // @@ Should be N from input, not from string length.
    int l2=strlen(b); // @@ Unused variable; not needed.
    { // @@ Missing call to order function and output. This block does nothing.
        
    }
}