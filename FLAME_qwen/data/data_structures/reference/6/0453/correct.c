#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int in[101],leave[101];

int main()
{
  int n,a,top=-1,TOP=-1;
  scanf("%d",&n);
  while(n!=-1)
    {
  switch(n)
  {
  case 1:
    scanf("%d",&a);
        if(top!=99)
        {
    top++;
    in[top]=a;
        }
    else
        printf("error ");
    break;
  case 0:
      if(top!=-1)
      {
      TOP++;
      leave[TOP]=in[top];
      top--;
      printf("%d ",leave[TOP]);
      }
      else
        printf("error ");
    break;
  }
  scanf("%d",&n);
    }
  return 0;
}


