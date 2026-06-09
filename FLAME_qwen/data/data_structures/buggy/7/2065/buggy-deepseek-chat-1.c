#include <stdio.h>  
int main(){
    int n;
    while(scanf("%d",&n)!=EOF) // @@ This program reads input but does not implement the BST construction or leaf node output as required by the problem description. It simply echoes the input numbers, which is incorrect for the given problem.
    printf("%d\n",n); // @@ This line outputs each integer read, but the problem requires constructing a BST and outputting leaf node values and heights, not just printing the input.
}