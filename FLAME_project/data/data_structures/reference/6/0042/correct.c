#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define maxsize 1000
int stack[maxsize];
int top;

int main()
{
	int i=0,j=0,flag=9;
	int out[1001];
	while (1)
	{
		scanf("%d",&flag);
		if(flag==1)
		{
			i++;
			//printf("(");
			scanf("%d",&stack[i]);//3(0)5(1)7(2)8(0)
		//	printf("%d)",stack[i]);
			//i++;//1232
		}
		else if(flag==0)
		{
			/*if(i<0)
			{
				printf("error ");
			}
			else
			{*/
			
				//printf("-");
				out[j]=stack[i];//(0)=(2)7;(1)=(1)5;(2)=(0)8;
			    j++;//0-1;1-2;3
			    i--;//2-1;1-0;
		    //}
			
				
			
		}
		else if(flag==-1)
		{
			break;
		}
		
		
		
	}
	int k; 
	//printf("\n");
	for(k=0;k<j;k++)
	{
		if(out[k]==0)
			{
				printf("error ");
			}
			else
			{
		printf("%d ",out[k]);}
	}
	
	return 0;
}

