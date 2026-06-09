/*#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct node{
		int co;
		int ex;
		struct node *link;
	}LNode,*LinkList;
	
int len(LinkList list)//链表长度 
{
	LinkList p=list;
	int n=0;
	while(p!=NULL)
	{
		n++;
		p=p->link;
	}
	return n;
}

LinkList attach(int co,int ex,LinkList r)//链表连接 
{
	LinkList w;
	w=(LinkList)malloc(sizeof(LNode));
	w->co=co;
	w->ex=ex;
	r->link=w;
	return w;
}
	
char multi1[10000],multi2[10000];
int multi11[10000],multi22[10000];
int fin[5000][2];

int main()
{
	gets(multi1);//输入数据 
	gets(multi2);
	int m,a=0,b=0;
	for(m=0;m<strlen(multi1);m++) 
	{
		if(multi1[m]!=' ')
			multi11[a]+=(multi1[m]-'0')*10;
		else a++;
	}
	for(m=0;m<strlen(multi2);m++) 
	{
		if(multi2[m]!=' ')
			multi22[b]+=(multi2[m]-'0')*10;
		else b++;
	}
	LinkList p,q,r,s,list1=NULL,list2=NULL;//构造链表 
	int i,j;
	for(i=1;i<=sizeof(multi11)/8;i++)
	{
		p=(LinkList)malloc(sizeof(LNode));
		p->co=multi11[2*i-2];
		p->ex=multi11[2*i-1];
		p->link=NULL;
		if(list1==NULL)
			list1=p;
		else
			r->link=p;
		r=p;
	}
	for(i=1;i<=sizeof(multi22)/8;i++)
	{
		q=(LinkList)malloc(sizeof(LNode));
		q->co=multi22[2*i-2];
		q->ex=multi22[2*i];
		q->link=NULL;
		if(list2==NULL)
			list2=q;
		else
			r->link=q;
		r=q;
	}
	LinkList ans;
	ans=(LinkList)malloc(sizeof(LNode));
	r=ans;
	p=list1;	
	q=list2;
	int len1=len(list1),len2=len(list2);
	int co_tmp,ex_tmp;
	while(p!=NULL)//全部算出来，不排序，不合并 
	{
		while(q!=NULL)
		{
			co_tmp=(p->co)*(q->co);
			ex_tmp=(p->ex)+(q->ex);
			r=attach(co_tmp,ex_tmp,r);
			q=q->link;
		}
		p=p->link;
	}
	r->link=NULL;
	LinkList num=ans;
	r=ans;
	s=r;
	p=list1;	
	q=list2;
	r=r->link;
	while(num!=NULL)//合并
	{
		while(r!=NULL) 
		{
			if(r->ex==num->ex)
			{
				ans->co+=r->co;
				s->link=r->link;
				free(r);
				r=s->link;
			}
			else
			{
				s=r;
				r=r->link;
			}
		}
		num=num->link;
		r=num;
		s=r;
	}
	for(i=0;i<=5000;i++)//排序 
	{
		if(ans!=NULL)
		{
			fin[i][0]=ans->co;
			fin[i][1]=ans->ex;
			ans=ans->link;
		}
		else break;
	}
	int aa,bb;
	for(aa=0;aa<i;a++)
		for(bb=0;bb<i;bb++)
		{
			int tmp;
			if(fin[bb][1]<fin[bb+1][1])
			{
				tmp=fin[bb+1][1];
				fin[bb+1][1]=fin[bb][1];
				fin[bb][1]=tmp;
			}
		}
	for(j=0;j<i;j++)
		printf("%d %d ",fin[j][0],fin[j][1]);
	return 0;
}
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct expression{			//多项式结构体 
	int coe;				//系数 
	int pow;				//指数 
};
typedef struct expression num;
num a[2000],b[2000],c[2000];//a是第一个多项式，b是第二个多项式 ,c是最后相乘的多项式 
int cmp(const void*p1,const void*p2)
{
	struct expression *a=(struct expression*)p1;
	struct expression *b=(struct expression*)p2;
	return b->pow-a->pow;
}
int main()
{	
	int i,j,k=0;
	int n=0,nn=0;//n是第一个多项式的项数 ，nn是第二个多项式的项数  
	char ch;
	do   //读入第一个多项式 
	{
		scanf("%d%d%c",&a[n].coe,&a[n].pow,&ch);
		n++;
	}while(ch!='\n');
	do	//读入第二个多项式
	{
		scanf("%d%d%c",&b[nn].coe,&b[nn].pow,&ch);
		nn++;
	}while(ch!='\n');
	qsort(a,n,sizeof(num),cmp); //按指数排序 
	qsort(b,nn,sizeof(num),cmp);	//按指数排序 
	for(i=0;i<n;i++)
	{
		for(j=0;j<nn;j++)
		{
			c[k].coe=a[i].coe*b[j].coe;//系数相乘 
			c[k].pow=a[i].pow+b[j].pow;//指数相加 
			k++;
		}
	}
	qsort(c,k,sizeof(num),cmp);//根据指数排序 
	for(i=0;i<k;i++)
	{
		if(c[i].pow == c[i+1].pow && c[i].pow!=0)//指数一样的进行去重操作 
		{
			c[i+1].coe+=c[i].coe;//指数一样的进行去重操作 
			c[i].coe=0;//去重项系数设为零 
		}
	}
	qsort(c,k,sizeof(num),cmp);//根据指数排序 
	for(i=0;i<k;i++)
	{
		if(c[i].coe==0)//去重项不输出 
		{
			continue;
		}
		else
		{
			printf("%d %d ",c[i].coe,c[i].pow);//输出 
		}
	}
	return 0;
}





