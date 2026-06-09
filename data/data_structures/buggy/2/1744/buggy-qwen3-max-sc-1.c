#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
int x;
scanf("%d",&x); // @@ [The program reads only a single integer, but the problem requires reading an entire arithmetic expression ending with '='. This causes incorrect parsing of the input.]
if(x>0)
printf("%d",x); // @@ [The logic only outputs the input number if positive or 0 otherwise, which does not evaluate arithmetic expressions as required.]
else
printf("0");
 return 0;
}