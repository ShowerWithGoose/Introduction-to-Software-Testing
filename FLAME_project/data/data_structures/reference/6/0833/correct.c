#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<math.h>
#define mod 100007


int main()
{
int c,m,top=-1,a[100];
while(scanf("%d",&c)!=EOF)
{
    switch(c)
    {
    	case 1:
		  top++;
		  if(top==100)
		    printf("error "),top--;
		else
		  scanf("%d",&a[top]);
		  break;
		case 0:
			if(top==-1)
			 printf("error ");
			 else
			 printf("%d ",a[top]),top--;	
			 break;
		case -1:return 0;		
	}
}
	return 0;
}




