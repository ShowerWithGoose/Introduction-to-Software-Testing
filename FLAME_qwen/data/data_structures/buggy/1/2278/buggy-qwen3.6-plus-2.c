#include<stdio.h>
#include<string.h>
char a[85];
char b[85];
int main()
{
    scanf("%s",&a); // @@ The problem requires reading an integer N, not a string. Also, &a is incorrect type for %s.
    scanf("%s",&b); // @@ The problem only requires one integer input N. This line is unnecessary and incorrect.
    int l1=strlen(a); // @@ Irrelevant to the problem. Should declare and initialize variables for permutation generation.
    int l2=strlen(b); // @@ Irrelevant to the problem.
    { // @@ Missing core logic to generate and output permutations of 1 to N in lexicographical order.
        
    }
}