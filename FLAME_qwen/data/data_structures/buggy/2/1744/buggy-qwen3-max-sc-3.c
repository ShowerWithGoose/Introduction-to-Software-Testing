#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
int x;
scanf("%d",&x); // @@ [The program reads only a single integer, but the problem requires reading and evaluating a full arithmetic expression ending with '='. This causes incorrect parsing of input like "5 - 1 * 2 * 3 + 12 / 2 / 2 =".]
if(x>0)
printf("%d",x); // @@ [Only outputs the first number if positive; does not compute the entire expression according to operator precedence and integer division rules.]
else
printf("0"); // @@ [Incorrectly outputs 0 for non-positive first numbers, ignoring the rest of the expression entirely.]
 return 0;
}