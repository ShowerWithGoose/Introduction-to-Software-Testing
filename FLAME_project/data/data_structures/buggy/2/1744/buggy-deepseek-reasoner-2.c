#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
int x;
scanf("%d",&x); // @@ [Error: This reads only one integer, but the problem requires reading an entire arithmetic expression ending with '='.]
if(x>0) // @@ [Error: The logic does not process the expression; it just checks the sign of the first number.]
printf("%d",x); // @@ [Error: Outputs only the first number, not the computed result of the expression.]
else // @@ [Error: Incorrect handling; should not print 0 for non-positive input.]
printf("0"); // @@ [Error: Completely unrelated to the required output.]
 return 0;
}