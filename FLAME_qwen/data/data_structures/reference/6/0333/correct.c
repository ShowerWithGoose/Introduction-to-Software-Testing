#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[100];
int stackout[100];
int flag[1000];

int main()
{
	int ope;
	int top = -1;
	int mark;
	int i=0,j=0,k=-1;
	scanf("%d",&ope);
	while(ope!=-1)
	{
		k++;
		if(ope == 1)
		{
			if(top == 99)
			{
				flag[k] = 2;
			}
			else
			{
				top++;
				flag[k] = 1;
			}
		}
		if(ope == 0)
		{
			if(top == -1)
			{
				flag[k] = 2;
			}
			else
			{
				stackout[j] = stack[top];
				top--;
				j++;
				flag[k] = 0;
			}
		}
		if(ope != 1 && ope != 0)
		{
			stack[top] = ope;
			flag[k] = 1;
		}
		scanf("%d",&ope);
	}
	j=0;
	for(i=0;i<k+1;i++)
	{
		if(flag[i]==1)
			continue;
		if(flag[i]==2)
		{
			printf("error ");
		}
		if(flag[i]==0)
		{
			printf("%d ",stackout[j++]);
		}
	}
	return 0;
}
