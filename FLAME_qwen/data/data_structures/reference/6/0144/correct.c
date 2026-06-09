#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define datatype int
#define max 100
int main()
{
	//栈多为顺序存储 利用一维数组
	 datatype stack[max];
	 int dat[2*max];
	 int top=-1;
	 int i,j;
	 
	 //读取所有数据 
	 /*
	 while(scanf("%d",&dat[i])!=EOF)
	 {
	 	i++;
	 }
	 */
	 scanf("%d",&dat[0]);
	 for(i=1;dat[i-1]!=-1;i++)
	 {
	 	scanf("%d",&dat[i]);
	 }

	 
	 //操作
	 for(j=0;j<i;j++)
	 {
	 	//入栈 
	 	if(dat[j]==1 && top!=max-1)
	 	{
		    top++;
	 		stack[top]=dat[j+1];
	 		j++;
		}
		
		else if(dat[j]==1 && top==max-1)
		{
			printf("error ");
		}
		
		//出栈 
		else if(dat[j]==0 && top!=-1)
		{
			printf("%d ",stack[top]);
			top--;
		}
		
		else if(dat[j]==0 && top==-1)
		{
			printf("error ");
		}
		
		//结束
		else if(dat[j]==-1)
		{
		   break;	
		} 
	 } 
	 return 0;
}

