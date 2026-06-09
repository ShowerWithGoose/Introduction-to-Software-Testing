#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
int x;
scanf("%d",&x); // @@ [The program reads only a single integer, but the problem requires reading and evaluating a full arithmetic expression ending with '='. This causes incorrect parsing of input like "5 - 1 * 2 * 3 + 12 / 2 / 2 =".]
if(x>0)
printf("%d",x); // @@ [Only outputs the first number if positive; completely ignores operators and rest of expression.]
else
printf("0"); // @@ [Outputs 0 for non-positive first number, which is incorrect for expressions starting with negative or zero values, and fails to evaluate the actual expression.]
 return 0;
}