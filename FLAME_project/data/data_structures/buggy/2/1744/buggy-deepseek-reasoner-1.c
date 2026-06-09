#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
int x;
scanf("%d",&x); // @@ This reads only a single integer, not the required arithmetic expression with operators and '='.
if(x>0) // @@ The program should parse and evaluate the expression with operator precedence; this simple condition does not perform any evaluation.
printf("%d",x); // @@ Outputs only the input number, not the computed result of the expression.
else // @@ Missing handling of subtraction, multiplication, and division operations.
printf("0"); // @@ Outputs zero incorrectly; should output the correct result (e.g., 602).
 return 0;
}