#include<stdio.h>
int main()
{
    int a; // @@ [The variable 'a' is reused for both reading 'n' and the sequence values, but the program ignores 'n' and reads until EOF, causing incorrect behavior when only one value is expected.]
    while(scanf("%d",&a)!=EOF) // @@ [This loop reads all integers until EOF, but according to the input format, it should read exactly 'n' integers after reading 'n'. The original reference program also has this bug, but the provided source code here is even more simplified and wrong.]
    {
        printf("%d ",a); // @@ [The output format is incorrect: it prints only the value followed by a space, without the height, and not in separate lines as required. Also, it doesn't build or traverse a BST at all.]
    }
    return 0;
}