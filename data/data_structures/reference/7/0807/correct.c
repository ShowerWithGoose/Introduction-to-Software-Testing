#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<math.h> 
#include<stdbool.h>
#include <ctype.h> 
typedef struct node{
	int d;
	int h;
	struct node *l,*r;
}B,*Bp;
void insert(Bp *p,int a,int d)
{
	if(*p==NULL) { 
	(*p) = (Bp)malloc(sizeof(Bp));
    (*p)->d = a;
    (*p)->h = d;
    (*p)->l =(*p)->r=NULL;
	}
	else if(a<(*p)->d)
	{
		(*p)->h++;
		insert(&((*p)->l),a,d+1);
	 }
	 else
	{
		(*p)->h++;
    insert(&((*p)->r),a,d+1);
    }
} 
void pre(Bp T)
{
	if(T!=NULL){
	pre(T->l); 
	if(T->l==NULL&&T->r==NULL)
	printf("%d %d\n",T->d,T->h);
	pre(T->r);
    } 
}
int main()
{
	int n,a;
	Bp root = NULL;
    scanf("%d\n",&n);
	while(n--)
	{
		scanf("%d",&a);
		insert(&root,a,1);
	}
	 pre(root);
return 0;		
}
//13
//50 38 30 64 58 40 10 73 70 50 60 100 35

