#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
int x; // @@ [Error: Should declare a character array to store the input arithmetic expression, not an integer.]
scanf("%d",&x); // @@ [Error: Should read the entire expression as a string (e.g., using fgets), not a single integer.]
if(x>0) // @@ [Error: The code completely lacks logic to parse operators (+, -, *, /) and handle operator precedence.]
printf("%d",x); // @@ [Error: Should output the calculated result of the expression, not the raw input value.]
else // @@ [Error: Incorrect conditional logic; the program must evaluate the expression regardless of input value.]
printf("0"); // @@ [Error: Should output the actual computed integer result, not a hardcoded 0.]
 return 0;
}