#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
int x;
scanf("%d",&x); // @@ Error: should read an arithmetic expression (as a string) ending with '=', not a single integer.
if(x>0)
printf("%d",x);
else
printf("0");
 return 0;
}