#include <stdio.h>
struct node{
	int coeff;//系数 
	int index;//指数 
	struct node *next;
};
typedef struct node item;
typedef struct node *itemptr; 
struct node answer[15000];
struct node *list1,*list2,*p,*q;
int checkbox[15000];
int check(int n,int m);
void bubblesort(struct node a[],int n);
int main()
{
	int x,y,i,j,m=0;
	int flag=0;	
	while(flag==0)
	{   
	    scanf(" %d %d",&x,&y);
	    if(getchar()=='\n') flag=1;
		p=(itemptr)malloc(sizeof(item));			
		p->next=NULL;
		p->coeff=x;
		p->index=y;
		if(list1==NULL)
		{
			list1=q=p;
		}
		else
		{
			q->next=p;
			q=p;
		}
		p=p->next;
	}
	flag=0;
	while(flag==0)
	{
		scanf(" %d %d",&x,&y);
		if(getchar()=='\n') flag=1;
		p=(itemptr)malloc(sizeof(item));			
		p->next=NULL;
		p->coeff=x;
		p->index=y;
		if(list2==NULL)
		{
			list2=q=p;
		}
		else
		{
			q->next=p;
			q=p;
		}
		p=p->next;
	}
	p=list1;
	q=list2;
	for(i=1;p!=NULL;i++,p=p->next)
	{
		q=list2;
		for(j=1;q!=NULL;j++,q=q->next)
		{
			if(check(p->index+q->index,m)==0)
			{
				m++;
				answer[m].coeff=p->coeff*q->coeff;
				answer[m].index=p->index+q->index;
				checkbox[m]=answer[m].index;
			}
			else
			{
				answer[check(p->index+q->index,m)].coeff+=p->coeff*q->coeff;
			}
		}
	}
	bubblesort(answer,m);
	for(i=1;i<=m;i++)
	{
		printf("%d %d ",answer[i].coeff,answer[i].index);
	}
	return 0;
 } 
void bubblesort(struct node a[],int n)
{
    int i,j;
    struct node hold;
    for(i=1;i<n;i++){
        for(j=1;j<n-i;j++){
            if(a[j].index<a[j+1].index){
                hold=a[j];
                a[j]=a[j+1];
                a[j+1]=hold;
            }

       }
       }
}
int check(int n,int m)
{
	int temp;
	for(temp=1;temp<=m;temp++)
	{
		if(checkbox[temp]==n) return temp;
	}
	return 0;
}



