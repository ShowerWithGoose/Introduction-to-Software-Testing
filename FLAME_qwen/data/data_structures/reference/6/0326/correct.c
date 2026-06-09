#include<stdio.h>
int a[100];
int main()
{ int x,y;
int top=-1;
while(1)
	{ scanf("%d",&x);
	if(x==1)
		{ scanf("%d",&y);
		a[++top]=y;
		
		}
	else if(x==0)
		{ if(top!=-1)
			{
			printf("%d ",a[top]);
			a[top]=0;
			top--;}
			else
			{ printf("error ");
			}
		}
		else if(x==-1)
			break;
	}




return 0;
}

