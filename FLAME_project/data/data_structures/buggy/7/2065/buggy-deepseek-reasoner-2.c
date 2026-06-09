#include <stdio.h>  
int main(){
    int n;
    while(scanf("%d",&n)!=EOF) // @@ This loop incorrectly reads all integers without handling the first integer as the count of subsequent numbers, and does not construct the BST.
    printf("%d\n",n); // @@ This prints the integer value, but the problem requires outputting each leaf node's value and height (with root height 1).
}