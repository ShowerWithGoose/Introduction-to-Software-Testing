#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int zhai[101];
int top=-1;
int maxsize=100;

int main()
{
  int op;
  while (scanf("%d",&op)!=EOF)
  {
    if(op==1)
    {
      if(top==99)
        printf("error ");
      else
        scanf("%d",&zhai[++top]);
    }
    else if(op==0)
    {
      if(top!=-1)
        printf("%d ",zhai[top--]);
      else
        printf("error ");
    }
    else
       break;

  }
  


    return 0;
}
