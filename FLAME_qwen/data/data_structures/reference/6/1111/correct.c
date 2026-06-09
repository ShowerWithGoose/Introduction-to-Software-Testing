#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int top;
int MAXLINE=100;int s[100];
void  PushLine(int x)
{

  if(top<MAXLINE-1)
  {top++;s[top]=x;}
  else printf("error ");
}
void  PopLine()
{

  if(top>0)
{ printf("%d ",s[top]);top--;}
  else printf("error ");
}
int main()
{
int ord,x;
while(1)
{
  int i;
  scanf("%d",&ord);
  if(ord==-1)break;
  switch(ord)
  {
    case 0:
    PopLine();break;
    case 1:
    scanf("%d",&x);
    PushLine(x);break;
  }

  //printf("\n");
 //for(i=top;i>0;i--)printf(" %d",s[i]);
 //printf("\n");
}
return 0;
}

