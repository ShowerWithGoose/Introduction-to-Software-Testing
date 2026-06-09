#include <stdio.h>  
int main(){
    int n;
    while(scanf("%d",&n)!=EOF) // @@ The problem requires reading n integers and building a BST, but this code simply reads and prints integers. It completely ignores the BST construction and leaf node output logic described in the problem.
    printf("%d\n",n); // @@ This prints the input value directly, whereas the expected output is the value and height of leaf nodes from a BST.
}