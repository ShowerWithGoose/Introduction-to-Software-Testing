#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
	int *aa=(int *)a;
	int *bb=(int *)b;
	aa=aa+1;
	bb=bb+1; 
	if(*aa<*bb) return 1;
	return -1;
}
struct node{
	int xishu;
	int zhishu;
	struct node* link;
};
typedef struct node *Nodeptr;
typedef struct node Node;
Nodeptr creatlist()
{
	Nodeptr p,q,list=NULL;
	int i;
	for(i=1;i<=100;i++)
	{
		q=(Nodeptr)malloc(sizeof(Node));
		char c;
		scanf("%d%d",&q->xishu,&q->zhishu);
		q->link=NULL;
		if(list==NULL)
		{list=q; 
		p=q;}   //q为新的结点，p为最后一个 
		else
		{p->link=q;
		p=q;}
		if((c=getchar())=='\n')  //判断是否一行已经读完 
		return list;
	}
}


int main()
{
	Nodeptr l1,l2;
	l1=creatlist();
	l2=creatlist();
	Nodeptr l3=NULL,l11,l22,l33,p,q;  //从这里开始看吧  上面完成了对两个多项式的读取，现在我准备用第三个链把他们的乘积的数据储存起来 
	//for(l22=l2;l22!=NULL;l22=l22->link)
	//printf("%d %d\n",l22->xishu,l22->zhishu);
	//	printf("4");int shu=0;
	for(l11=l1;l11!=NULL;l11=l11->link)
	{
		for(l22=l2;l22!=NULL;l22=l22->link)
		{	p=(Nodeptr)malloc(sizeof(Node));
			p->xishu=(l11->xishu)*(l22->xishu);
			p->zhishu=(l11->zhishu)+(l22->zhishu);
			p->link=NULL;
			if(l3==NULL)
			{
				l3=p;
				q=p;
			}
			else
			{
				q->link=p;
				q=p;
			}
		}
	}                                   //到这里结束 
//	printf("3 %d",shu);
//	for(l33=l3;l33!=NULL;l33=l33->link)
//	printf("%d %d\n",l33->xishu,l33->zhishu);
	int a[1000][2],i,j,k;
	for(l33=l3,i=0;l33!=NULL;l33=l33->link,i++)
	{
	//	printf("a %d",i);
		a[i][0]=l33->xishu;
		a[i][1]=l33->zhishu;
	}
//	printf("2 %d",i);
	qsort(a,i,sizeof(a[0]),cmp);
	int len=i;
	for(i=0;i<len-1;i++)
	{
		if(a[i][1]==a[i+1][1])
		{
			for(j=i+1;a[j][1]==a[i][1];j++)
			{
				a[i][0]+=a[j][0];
				a[j][1]=-1;
			}
			i=j-1;
		}
	}
	for(i=0;i<len;i++)
	{
		
		if(a[i][1]!=-1&&a[i][0]!=0)
		printf("%d %d ",a[i][0],a[i][1]);
	}
	
	
	
	return 0;
 } 

