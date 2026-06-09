#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
	int data,mov;
	int top=-1;
	int zhan[100];
	scanf("%d",&mov);
	while(mov!=-1)
	{
		if(mov==1)
		{
			if(top==99)
			{
				printf("error ");
			}
			else
			{
			scanf("%d",&data);
			zhan[++top]=data;
		}
		}
		else if(mov==0)
		{
			if(top==-1)
			{
				printf("error ");
			}
			else{
				printf("%d ",zhan[top--]);
			}
		}
		scanf("%d",&mov);
	}
	return 0;
 } 

