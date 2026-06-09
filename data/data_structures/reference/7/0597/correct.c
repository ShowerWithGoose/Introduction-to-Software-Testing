#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
typedef struct tree *tre;
typedef struct tree{
	int num;
	int h;
	tre lt;
	tre rg;
}tr;
tre insert(tre p,int n,int hight);
void print(tre p);
int main()
{
	
	int i,k,ht=0,data;
	scanf("%d",&k);
	tre root=NULL;
	for(i=1;i<=k;i++)
	{
		scanf("%d",&data);
		ht=0;
		root=insert(root,data,ht);
	}
	print(root);
	return 0;
}
tre insert(tre p,int n,int hight)
{
	hight++;
    if(p == NULL){
        p = (tre)malloc(sizeof(tr));
        p->num = n;
        p->h=hight;
        p->lt = p->rg = NULL;
    } 
    else if( n< p->num)
       p->lt = insert(p->lt,n,hight);
    else 
       p->rg = insert(p->rg,n,hight);
    return p;
} 
void print(tre p)
{
	if(p!=NULL)
	{
		if(p->lt==NULL&&p->rg==NULL)
		{
			printf("%d %d\n",p->num,p->h);
		}
		else
		{
		    print(p->lt);
	     	print(p->rg);
		}
	
	}
}

