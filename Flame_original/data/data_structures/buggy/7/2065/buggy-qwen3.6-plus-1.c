#include <stdio.h>  
int main(){
    int n;
    while(scanf("%d",&n)!=EOF) // @@ Logical error: The program should read the integer n representing the number of elements, then read exactly n integers to construct a BST, instead of looping until EOF.
    printf("%d\n",n); // @@ Logical error: The program should construct a BST, traverse it to identify leaf nodes, calculate their heights (root height = 1), and output them in left-to-right order, rather than simply echoing the input.
}