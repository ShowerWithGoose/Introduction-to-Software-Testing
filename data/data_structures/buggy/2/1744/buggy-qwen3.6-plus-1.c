#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
int x; // @@ [The program should read an arithmetic expression as a string, not a single integer.]
scanf("%d",&x); // @@ [Incorrect input method; fails to read the full expression containing operators and spaces.]
if(x>0) // @@ [Incorrect logic; does not parse the expression or handle operator precedence.]
printf("%d",x); // @@ [Outputs the raw input instead of the evaluated result of the expression.]
else
printf("0"); // @@ [Incorrect output; should compute and print the result of the arithmetic expression.]
 return 0;
}