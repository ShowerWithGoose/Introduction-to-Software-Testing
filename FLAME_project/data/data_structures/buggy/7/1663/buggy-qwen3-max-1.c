#include<stdio.h>
int main()
{
    int a; // @@ [The variable 'a' is reused for both reading 'n' and the sequence values, but the program never reads 'n' to control the number of inputs. Instead, it reads until EOF, which causes incorrect behavior when only one integer (after n=1) is expected.]
    while(scanf("%d",&a)!=EOF) // @@ [This loop reads all integers until EOF, ignoring the first integer 'n' that specifies how many numbers to read. Thus, for input "1\n5678", it reads 1 and then 5678, printing both, instead of reading only one value (5678) after n=1.]
    {
        printf("%d ",a); // @@ [The output format is incorrect: it prints all input numbers separated by space on one line, instead of printing leaf node values and their heights in separate lines as required. Also, it doesn't build or traverse a BST at all.]
    }
    return 0;
}