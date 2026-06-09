#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
//#define MAXN 120
//define mst(s) memset(s,0,sizeof(s))
typedef struct node {
	int coe;
	int idx;
	struct node *next;
} linklist;
int main(void)
{
	//freopen("in.multi.txt","r",stdin);
	int i,j,k,n,m;
	linklist *a=(linklist *)malloc(sizeof(linklist)),*b=(linklist *)malloc(sizeof(linklist)),*current,*last,*newnode,*currenta,*currentb,*head=(linklist *)malloc(sizeof(linklist));
	head->next=NULL;
	current=a;
	current->next=NULL;
	while(1) {
		scanf("%d%d",&current->coe,&current->idx);
		current->next=NULL;
		if(getchar()=='\n') {
			break;
		}
		current->next=(linklist *)malloc(sizeof(linklist));
		current=current->next;
	}
	current=b;
	current->next=NULL;
	while(1) {
		scanf("%d%d",&current->coe,&current->idx);
		current->next=NULL;
		if(getchar()=='\n') {
			break;
		}
		current->next=(linklist *)malloc(sizeof(linklist));
		current=current->next;
	}
	current=head;
	for(currenta=a; currenta!=NULL; currenta=currenta->next) {
		for(currentb=b; currentb!=NULL; currentb=currentb->next) {
			newnode=(linklist *)malloc(sizeof(linklist));
			newnode->coe=currenta->coe*currentb->coe;
			newnode->idx=currenta->idx+currentb->idx;
			newnode->next=NULL;
			for(current=head->next,last=head; current!=NULL&&current->idx>newnode->idx; current=current->next,last=last->next);
			if(current!=NULL&&current->idx==newnode->idx) {
				current->coe+=newnode->coe;
				free(newnode);
			} else {
				newnode->next=current;
				last->next=newnode;
			}
		}
	}
	for(current=head->next;current!=NULL;current=current->next){
		printf("%d %d ",current->coe,current->idx);
	}

	return 0;
}



