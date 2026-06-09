#include<stdio.h>
#include<stdlib.h>


struct node{
	int coe;
	int pow;
	struct node *link;
}; 
typedef struct node *ptr;
typedef struct node Node;
int rise(const void *p1,const void *p2)
{
	int *a=(int*)p1,*b=(int*)p2;
	if(*(a+1)>=*(b+1))
	return -1;
	if(*(a+1)<*(b+1))
	return 1;
}
ptr read()
{
	ptr list;
	ptr p,r;
	int a,b;char c;
	list=NULL;
	do
	{
		scanf("%d%d%c",&a,&b,&c);
		p=(ptr)malloc(sizeof(Node));
		p->coe=a;p->pow=b;p->link=NULL; 
		if(list==NULL)
		list=r=p;
		else
		{
			r->link=p;
			r=r->link;
			/*r=p;
			p=r->link;*/
		}
	}while(c!='\n');
	return list;
}
void multi(ptr lst1,ptr lst2)
{
	ptr p1,p2;
	int i=0;
	int a[1024][2]={0};
	for(p1=lst1;p1!=NULL;p1=p1->link)
	{
		for(p2=lst2;p2!=NULL;p2=p2->link)
		{
			a[i][0]=p1->coe*p2->coe;
			a[i][1]=p1->pow+p2->pow;
			i++;
		}
	}
	qsort(a,i-1,sizeof(a[0]),rise);
	int j=0;
	int putcoe,putpow;
	for(j=0;j<i;j++)
	{
		putcoe=a[j][0];
		putpow=a[j][1];
		while(a[j][1]==a[j+1][1]&&j<i)
		{
			j++;putcoe+=a[j][0];
		}
		printf("%d %d ",putcoe,putpow);
	}
} 
 
 
int main() 
{
 	ptr list1,list2;
 	list1=read();
 	list2=read();
 	multi(list1,list2);
 	return 0;
}

