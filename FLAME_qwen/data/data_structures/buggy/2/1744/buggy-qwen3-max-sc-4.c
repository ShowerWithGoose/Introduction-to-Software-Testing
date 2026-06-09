#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
int x;
scanf("%d",&x); // @@ [The program reads only a single integer, but the problem requires reading and evaluating a full arithmetic expression ending with '='. This approach cannot handle operators or multiple numbers.]
if(x>0)
printf("%d",x); // @@ [Only outputs the input number if positive; does not compute any arithmetic expression as required.]
else
printf("0"); // @@ [Outputs 0 for non-positive input, which is unrelated to evaluating an arithmetic expression.]
 return 0;
}