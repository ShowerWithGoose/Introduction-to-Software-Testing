#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NUMBER
{
	int front;
	int up;
	struct NUMBER *link;
}*Numberptr,Number;

char s1[1000],s2[1000],tmp[1000];
int N1,N2;//用于保存链表的长度

Numberptr Create_Simple(char *s,int i);
Numberptr Create_Middle(int *a,int *b);
Numberptr Insert_Middle(Numberptr list,int front,int up);

int main()
{
	/*
	**读入字符串
	**然后建立链表
	*/
	gets(s1);
	gets(s2);	
	strcat(s1,"\n");
	strcat(s2,"\n");
	
	Numberptr list1,list2,list3;
	list1=Create_Simple(s1,1);
	list2=Create_Simple(s2,2);
	Numberptr p1=list1,p2=list2;
	
/*
**测试N1N2
**没问题
*
	printf("%d %d\n",N1,N2);
*/

	/*
	**得知链表长度后申请数组
	**在乘法时把结果放入两个数组中
	*/
	int AfterMulti_Front[N1],AfterMulti_Up[N1];
	
	for(int j=0;j<N2;j++)
	{
		/*
		**填入数组
		**并在最后将p1重新指向list1
		*/
		for(int i=0;i<N1;i++)
		{
			AfterMulti_Front[i]=(p2->front)*(p1->front);
			AfterMulti_Up[i]=(p2->up)+(p1->up);
			p1=p1->link;
		}
		p1=list1;
		
	/*
	**测试AfterMulti_Front/Up里的数据
	**只输出了两组
	*
		for(int i=0;i<N1;i++)
		{
			printf("%d %d\n",AfterMulti_Front[i],AfterMulti_Up[i]);
		}
		printf("\n");
	*/
	
		/*
		**当p2指向第一个时,创建一个链表
		*/
		if(p2==list2)
		{
			list3=Create_Middle(AfterMulti_Front,AfterMulti_Up);	
		}
			
		/*
		**当p2不指向第一个时,在顺序链表中插入
		*/
		else 
		{
			for(int i=0;i<N1;i++)
			{
				list3=Insert_Middle(list3,AfterMulti_Front[i],AfterMulti_Up[i]);
			}
		}
		
	/*
	**测试list3链表
	**只输出了一组
	*
		Numberptr p3=list3;
		while(p3!=NULL)
		{
			printf("%d %d ",p3->front,p3->up);
			p3=p3->link;
		}
		printf("\n");
	*/
		p2=p2->link;
	}
	
	
	/*
	**输出
	*/
	Numberptr p3=list3;
	while(p3!=NULL)
	{
		printf("%d %d ",p3->front,p3->up);
		p3=p3->link;
	}
	
	return 0;
}

Numberptr Create_Simple(char *s,int i)
{
	Numberptr list=NULL,p,q;
	int front,up;
	
	while(strlen(s)>=4)
	{
		if(sscanf(s,"%d%d%[^\n]",&front,&up,tmp)==2)tmp[0]=0;
		memcpy(s,tmp,sizeof(tmp));
		
		strcat(s,"\n");
		//printf("%d %d %s",front,up,s);
		if(i==1) N1++;
		else N2++;
		
		q=(Numberptr)malloc(sizeof(Number));
		q->front=front; q->up=up; q->link=NULL;
		
		if(list==NULL)
		{
			list=p=q;
		}
		else
		{
			p->link=q;
		}
		p=q;
	}
	return list;
}

Numberptr Create_Middle(int *a,int *b)
{
	Numberptr list=NULL,p,q;
	int i;
	
	for(i=0;i<N1;i++)
	{
		q=(Numberptr)malloc(sizeof(Number));
		q->front=a[i]; q->up=b[i]; q->link=NULL;
		
		if(list==NULL)
		{
			list=p=q;
		}
		else
		{
			p->link=q;
		}
		p=q;
	}
	return list;
}

/*
**并不是说在中间插入
**Middle指中阶
*/
Numberptr Insert_Middle(Numberptr list,int front,int up)
{
	Numberptr p=list,q,r;
	r=(Numberptr)malloc(sizeof(Number));
	r->front=front; r->up=up; r->link=NULL;
		
	while((p!=NULL)&&((p->up)>up))
	{
		q=p;
		p=p->link;
	}
	
	if(p==NULL)
	{
		q->link=r;
		return list;
	}
	else
	{
		/*
		**判断指数是相等还是小于
		*/
		if((p->up)<up)
		{
			/*
			**判断一下是不是在最前头
			*/
			if(p==list)
			{
				r->link=list;
				list=r;
			}
			else
			{
				r->link=q->link;
				q->link=r;
			}
			
			return list;
		}
		else
		{
			free(r);
			p->front+=front;
			return list;
		}
	}
}


