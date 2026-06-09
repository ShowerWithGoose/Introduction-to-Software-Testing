#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
int x; // @@ [The program reads only a single integer and ignores the rest of the expression, completely failing to parse or evaluate arithmetic expressions as required.]
scanf("%d",&x); // @@ [This only reads the first number and does not handle operators, subsequent numbers, spaces, or the '=' terminator.]
if(x>0) // @@ [The logic incorrectly outputs the first number if positive, or 0 otherwise, which has nothing to do with evaluating the full arithmetic expression.]
printf("%d",x); // @@ [Output is based solely on the first integer, not the result of the entire expression.]
else
printf("0"); // @@ [This branch outputs 0 for non-positive first numbers, which is unrelated to the actual expression evaluation.]
 return 0;
}