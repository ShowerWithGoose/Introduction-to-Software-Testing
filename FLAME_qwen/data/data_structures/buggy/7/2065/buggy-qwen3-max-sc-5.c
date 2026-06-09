#include <stdio.h>  
int main(){
    int n;
    while(scanf("%d",&n)!=EOF)
    printf("%d\n",n); // @@ [The program does not implement BST construction or leaf node height calculation; it merely echoes input integers, which completely ignores the problem requirements. Additionally, the loop reads only one integer 'n' and then prints it, but never reads the subsequent 'n' integers needed to build the BST. This leads to incorrect behavior for all test cases beyond trivial input.]
}