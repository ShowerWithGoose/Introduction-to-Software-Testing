#include<stdio.h>


int main() // @@ The program completely lacks the implementation of stack logic (array, index, push/pop conditions). It merely echoes the input.
{
    int a; // @@ Missing stack array declaration (e.g., int zhan[100]) and stack top index variable (e.g., int i=0).
    while(~scanf("%d",&a)) // @@ The loop body only prints the input value 'a', ignoring whether it is an operation code (1, 0, -1) or data.
    printf("%d ",a); // @@ Should implement logic: if a==1 push, if a==0 pop and print popped value, if a==-1 break, plus error handling for overflow/underflow.
    return 0;
}