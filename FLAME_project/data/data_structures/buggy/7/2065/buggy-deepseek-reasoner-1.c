#include <stdio.h>  
int main(){
    int n;
    while(scanf("%d",&n)!=EOF) // @@ Error: This loop reads all integers without distinguishing the first integer as count. Should first read the count 'n', then loop to read exactly 'n' integers into the BST.
    printf("%d\n",n); // @@ Error: This prints each integer read, but the problem requires building a BST and outputting leaf nodes with height.
}