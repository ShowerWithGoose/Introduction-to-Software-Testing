#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
int x; // @@ [Error: The program should read an arithmetic expression as a string, not a single integer]
scanf("%d",&x); // @@ [Error: Should use a method like gets() or fgets() to read the entire line ending with '=']
if(x>0) // @@ [Error: No logic to evaluate the expression; this condition is unrelated]
printf("%d",x); // @@ [Error: Outputs the input integer, not the evaluated result of the expression]
else
printf("0"); // @@ [Error: Incorrect fallback; does not compute anything]
 return 0;
}