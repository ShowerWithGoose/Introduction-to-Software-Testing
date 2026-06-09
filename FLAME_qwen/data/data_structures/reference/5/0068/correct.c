#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>//快排 
#define eps 1e-8
#define pi 3.14
#define eof EOF
struct A
{
	int coe;//系数 
	int index;//指数 
};
struct B
{
	int coe;
	int index;
};
struct result
{
	int coe;
	int index;
	struct result *next;
}; 
struct h
{
	int coe;
	int index;
	int flag;
};
struct A xa[100];
struct B xb[100];
struct h over[10000];
int lena,lenb;

struct result* creatlist(void); 
deliver_and_destory_list(struct result *h);
void manage(void);
void sort(void);

int main()
{
	int i=0,j;char ch;//录入数据到类数组中 
	do{
		scanf("%d %d",&xa[i].coe,&xa[i].index);
		i++;
	}while((ch=getchar())!='\n');
	lena=i;//长度是i，从0存到i-；
	
	i=0;
	do{
		scanf("%d %d",&xb[i].coe,&xb[i].index);
		i++;
	}while((ch=getchar())!='\n');
	lenb=i;
	//建立一个链表，存储两个相乘的结果，连边长度为lena*lenb
	struct result*head=creatlist();
	deliver_and_destory_list(head);
	manage();
	sort();
	for(i=0;i<lena*lenb;i++)
	{
		if(over[i].flag ==1)
		printf("%d %d ",over[i].coe ,over[i].index );
	}
	/*for(i=0;i<lena*lenb;i++)
	printf("%d %d %d\n",over[i].coe ,over[i].index ,over[i].flag );*/
	
	
}

struct result* creatlist(void)
{
	struct result* h;//h指向头节点，保存头节点的地址。
	struct result*p,*q;//p指向现在的结点，q指向上一个结点。
	int j,k;
	
	/*首先开辟头节点的空间，头节点不需要保存内容，但需要next域，next域稍后设置*/
	q=(struct result*)malloc(sizeof(struct result));//开辟 
	h=q;//赋值给h，让h保存；h就不会变了 
	
	/*建立链表中的结点，现在的上一结点是头节点（q,h指向的结点）*/ 	
		for(j=0;j<lena;j++)
		{
			for(k=0;k<lenb;k++)
			{
				p=(struct result*)malloc(sizeof(struct result));/*开一个结点空间*/
				p->coe=xa[j].coe*xb[k].coe;
				p->index=xa[j].index+xb[k].index;
				q->next=p;
				q=p;
			}
		}
	q->next=0;//设置最后一个结点的指针域为0
	return h;//返回头结点的地址 ,头节点中只有第一个的地址。 
}
deliver_and_destory_list(struct result *h)
{
	struct result *q,*p=h->next;
	int i;
	for(i=0;i<lena*lenb;i++)
	{
		q=p->next;
		over[i].coe =p->coe ;
		over[i].index=p->index;
		over[i].flag =1;
		free(p);
		p=q;	
	}
	free(h);
}
void manage(void)
{
	int i,j;
	for(i=0;i<lena*lenb;i++)
	{
		for(j=0;j<i;j++)
		{
			if(over[j].flag==1)
			{
				if(over[i].index ==over[j].index )
				{
					over[i].flag =0;
					over[j].coe =over[j].coe +over[i].coe;
				}
				
			}
			
				
		}
	}
	
}
void sort(void)
{
	int i,j,t;
	for(i=0;i<lena*lenb;i++)
	{
		for(j=0;j<lena*lenb-1;j++)
		{
			if(over[j].index <over[j+1].index )
			{
				t=over[j].index;over[j].index=over[j+1].index;over[j+1].index=t;
				t=over[j].flag ;over[j].flag=over[j+1].flag;over[j+1].flag=t;
				t=over[j].coe;over[j].coe=over[j+1].coe;over[j+1].coe=t;
			}
		}
	}
}
	

