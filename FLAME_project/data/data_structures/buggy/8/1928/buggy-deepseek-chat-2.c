#include<stdio.h>

int main()
{
    int x;
    while(scanf("%d",&x)!=EOF) // @@ This loop reads all input but does not store or process it correctly; it only reads and discards values, then prints the last value once after the loop ends.
    
    printf("%d\n",x); // @@ This line is outside the while loop due to missing braces, so it prints only the last read value once, instead of processing the graph and outputting traversal sequences.
    return 0;
}