#include <stdio.h>  
int main(){
    int n;
    while(scanf("%d",&n)!=EOF) // @@ [The loop incorrectly reads all integers; should read n first and then read exactly n integers and construct BST]
    printf("%d\n",n); // @@ [The program prints each integer but should output leaf node values and heights]
}