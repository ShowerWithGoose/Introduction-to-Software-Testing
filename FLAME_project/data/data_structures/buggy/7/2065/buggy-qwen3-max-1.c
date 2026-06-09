#include <stdio.h>  
int main(){
    int n;
    while(scanf("%d",&n)!=EOF)
    printf("%d\n",n); // @@ [The program only reads and prints the first integer `n`, but it should read `n` integers afterward and build a BST. It completely ignores the problem requirements, leading to wrong output format and logic.]
}