#include<stdio.h>
int main()
    {
    int a;
    int stack[101];
    int j=0;
    for(j=0;;)
	  {
	  scanf("%d",&a);
	  if(a==1)
		{
		scanf("%d",&a);
		stack[j++]=a;
		}
	  if(a==0)
		{
		if(j==0)printf("error ");
		else
		    {
		    printf("%d ",stack[j-1]);
		    j--;
		    }
		}
	  if(a==-1)break;
	  }
    return 0;
    }

