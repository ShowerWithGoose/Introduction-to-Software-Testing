#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
int x;
scanf("%d",&x); // @@ [The program reads only a single integer, but the problem requires reading and evaluating a full arithmetic expression ending with '='. This fundamental misunderstanding of input format causes incorrect behavior.]
if(x>0)
printf("%d",x); // @@ [Only outputs the input number if positive; does not perform any arithmetic evaluation as required by the problem.]
else
printf("0"); // @@ [Outputs 0 for non-positive inputs, which is unrelated to evaluating an arithmetic expression.]
 return 0;
}