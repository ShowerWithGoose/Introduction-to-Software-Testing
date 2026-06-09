#include<stdio.h>
int a[100], ch, sh;
int main()
{
	int top;
	top=0;
	while(1)
	{
		scanf("%d", &ch);
		if(ch==1)
		{
			scanf("%d", &sh);
			if(top==100)
			{
				printf("error ");
			}
			else
			{
				a[++top]=sh;
			}
		}
		if(ch==0)
		{
			if(top==0)
			{
				printf("error ");
			}
			else
			{
				printf("%d ", a[top--]);
			}
		}
		if(ch==-1)
		{
			break;
		}
	}
	return 0;
}

