#include <stdio.h>
#include <stdlib.h>
struct shu{
	int num;
	int deep;
	struct shu *lchild,*rchild;
}tree;
struct shu *ptr=NULL,*p=NULL,*stack[1000],*p1=NULL;
int max(int a,int b){
	return (a>=b?a:b);
}
int height(struct shu *p)
{
	if(p==NULL)return 0;
	else return 1+max(height(p->lchild),height(p->rchild));
}
void creat(int *a,struct shu *p,int n)
{
	int i=0,t=1,h=1,top=-1;
	if(p==NULL)
	{
		p=(struct shu*)malloc(sizeof(struct shu));
		ptr=p;
		ptr->num=a[0];
		ptr->lchild=NULL;
		ptr->rchild=NULL;
		ptr->deep=1;
    }
    p1=p;
     for(;t<n;t++)
	 {   
	      ptr=p;
	     top=-1;
	     while(ptr!=NULL)
	     {   
		     stack[++top]=ptr;
	 	    if(ptr->num<=a[t])
	 	    	ptr=ptr->rchild; 
			 else
			 	ptr=ptr->lchild;
		}
	     
	     ptr=stack[top];
	 	if(a[t]>=ptr->num)
	 	  {
	 		ptr->rchild=(struct shu*)malloc(sizeof(struct shu));
	 		ptr=ptr->rchild;
	
		  }
		else
		{
			ptr->lchild=(struct shu*)malloc(sizeof(struct shu));
	 		ptr=ptr->lchild;
		}
			ptr->num=a[t];
			ptr->deep=top+2;
			ptr->lchild=NULL;
			ptr->rchild=NULL;
	 
	   }  
    	
}
int main()
{   
	int a[1000]={0},n,top=-1,h,j;
	scanf("%d",&n);
	for(j=0;j<n;j++)scanf("%d",&a[j]);
	creat(a,p,n);
	h=height(p1);
    do
	{   
		for(;p1!=NULL;p1=p1->lchild)
		{   
			stack[++top]=p1;

		}
		p1=stack[top--];
		if(p1->lchild==NULL&&p1->rchild==NULL)
		{
			printf("%d %d\n",p1->num,p1->deep);
		}
		p1=p1->rchild;
		
	}
	while(p1!=NULL||top!=-1);
}

