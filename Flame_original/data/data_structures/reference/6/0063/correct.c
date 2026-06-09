#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAXSIZE 100
char num[5000];
int a[1000],STACK[MAXSIZE],Top=-1;

int  isEmpty( )
{
    return Top==-1;
} 

int isFull(  )
{
    return Top==MAXSIZE-1;
}

void  push( int item )
{
    if( isFull() )
        printf("error ");
    else
    	STACK[++Top]=item;      
}

void pop()
{
    if(isEmpty())
        printf("error ");
    else
    {
    	printf("%d ",STACK[Top--]);
    }
}

/*struct stack
{
	char data;
	struct stack *next;
}*top=NULL;

int isEmpty()
{
	return top==NULL;
}

void push(int a)
{
	struct stack *p;
	if( (p=(struct stack*)malloc(sizeof(struct stack)))==NULL )
    	{
    		return 0;
		}
    else
	{
        p->data=a;  
        p->next=top;    
        top=p;       
    }
}

void pop()
{
	struct stack *p;
    int item;
    if ( isEmpty() ) 
        printf("error ");                     
    else
	{
        p=top;                               /* 暂时保存栈顶结点的地址  
        item=top->data;                      /*保存被删栈顶的数据信息
        top=top->next;                       /* 删除栈顶结点 
        free(p);                             /* 释放被删除结点
        printf("%d ",item);                         /* 返回出栈元素
    }
}*/

int main()
{
//	char num[500];
	int i=0,j,n=0,x=0,m=0,nn=0;
/*	gets(num);
	for(i=4999;i>=0;i--)
	{
		num[i+1]=num[i];
	}
	num[0]=' ';
	for(i=0;i<5000;i++)
	{
		if(num[i]==' ')
		{
			if(num[i+1]=='-'&&num[i+2]=='1'&&num[i+3]=='\0')
			{
				{
					a[m]=-1;
					break;
				}
			}
			else if(num[i+1]=='-'&&(num[i+2]!='1'||num[i+3]!='\0'))	
			{
			
				for(j=i+2;num[j]!=' ';j++)
				{
					n++;
				}
				for(j=i+2;j<=i+n+2;j++)
				{
					n--;
					x+=(int)(num[j]-48)*pow(10,n);                   
				}
				n=0;
				a[m]=-x;
				x=0;											
				m++;
			}
			else if(num[i+1]!='-')
			{
				for(j=i+1;num[j]!=' ';j++)
				{
					n++;                                     //n记数字长度 
				}
				for(j=i+1;j<=i+n+1;j++)   
				{
					n--;
					x+=(int)(num[j]-48)*pow(10,n);               //x记每个int数大小 
				}
				n=0;
				a[m]=x;												 
				x=0;
				m++;										//m记int数个数
			}
			else if(num[i+1]=='\0')
				break;
			
		}
		else
			continue;
	}*/
//	int n;
	do
	{
		scanf("%d",&n);
		if(n==1)
		{
			scanf("%d",&nn);
			push(nn);
		}
		else if(n==0)
		{
			pop();
		}
		else if(n==-1)
		{
			return 0;
		}
	}while(1);
	
/*	for(i=0;i<1000;i++)
	{
//		printf("%d ",a[i]);
		if(a[i]==1)
		{
			i++;
			push(a[i]);
		}
		else if(a[i]==0)
			pop();
		else if(a[i]==-1)
			return 0;
		else
			continue;
	}*/
	return 0;
} 




/*
do
{
	scanf("%d",&n);
		
}while(1);

*/

