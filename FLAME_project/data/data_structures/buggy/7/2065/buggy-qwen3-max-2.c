#include <stdio.h>  
int main(){
    int n;
    while(scanf("%d",&n)!=EOF)
    printf("%d\n",n); // @@ [The program completely ignores the problem requirements: it does not build a BST, does not track node heights, and does not output leaf nodes in left-to-right order. Instead, it merely reads integers and prints each on a new line. For input "1\n5678", it outputs "1" (from reading n) and then "5678", but the expected output is only "5678 1". The logic is entirely missing.]
}