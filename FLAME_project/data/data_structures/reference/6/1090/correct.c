#include<stdio.h>
int stack[110];
int main()
{
  int i=0;
  int op,count=0,data;
  scanf("%d",&op);
  while(op!=-1)//不是-1就继续读
  {
    //count++;//看看这个可能在哪里
    if(op==1)//入栈操作
    {
      if(count==100)//如果栈满
      {printf("error ");}
      else
      {
        scanf("%d",&data);
        stack[i]=data;
        i++;
        count++;
      }
    }
    else if(op==0)
    {
      if(count==0)
      {printf("error ");}
      else
      {
        i--;
        printf("%d ",stack[i]);
        count--;
      }
    }

    scanf("%d",&op);
  }
  return 0;
}
