#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
   int number[100];
   int way,num,top=-1;
   while(1)
   {
   scanf("%d",&way);
   if(way==-1)
    break;
   else if(way==0)
   {
   if(top==-1)
    printf("error ");
   else
   printf("%d ",number[top--]);
   }
   else if(way==1)
   {
   scanf("%d",&num);
   if(top==99)
    printf("error ");
   else
   number[++top]=num;
   }
   }
   printf("\n");
  return 0;
}

