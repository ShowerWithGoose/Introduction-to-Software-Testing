#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main() // @@ [The entire program logic is incorrect. It reads a single integer and prints it or 0, instead of parsing and evaluating an arithmetic expression with operator precedence as required by the problem description.]
{
int x; // @@ [Variable 'x' is declared as an integer, but the problem requires parsing a complex expression involving multiple numbers and operators.]
scanf("%d",&x); // @@ [Only reads a single integer. It fails to read the rest of the arithmetic expression, including operators and subsequent operands.]
if(x>0) // @@ [This condition checks if the single input number is positive, which is irrelevant to calculating the result of an arithmetic expression.]
printf("%d",x); // @@ [Prints the single input number instead of the calculated result of the expression.]
else // @@ [This branch handles negative inputs for the single number, which is not part of the expression evaluation logic.]
printf("0"); // @@ [Prints 0 for non-positive inputs, which is incorrect behavior for an expression calculator.]
 return 0;
}