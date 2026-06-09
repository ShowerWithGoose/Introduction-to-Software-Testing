#include <stdio.h>  
int main(){
    int n;
    while(scanf("%d",&n)!=EOF) // @@ This loop reads and prints numbers, but does not construct a BST or output leaf nodes as required.
    printf("%d\n",n); // @@ This prints the raw integer value, not the leaf node value and height in left-to-right order.
}