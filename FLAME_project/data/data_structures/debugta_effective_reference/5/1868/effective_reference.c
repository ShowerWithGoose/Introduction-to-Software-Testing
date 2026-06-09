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
	int coef;
	int exp;
	struct node *next;
} linklist;
int main(void)
{
	//freopen("in.multi.txt","r",stdin);
	int i,j,k,n,m;
	linklist *poly1=(linklist *)malloc(sizeof(linklist)),*poly2=(linklist *)malloc(sizeof(linklist)),*current,*prev,*newnode,*p1,*p2,*result=(linklist *)malloc(sizeof(linklist));
	result->next=NULL;
	current=poly1;
	current->next=NULL;
	while(1) {
		scanf("%d%d",&current->coef,&current->exp);
		current->next=NULL;
		if(getchar()=='\n') {
			break;
		}
		current->next=(linklist *)malloc(sizeof(linklist));
		current=current->next;
	}
	current=poly2;
	current->next=NULL;
	while(1) {
		scanf("%d%d",&current->coef,&current->exp);
		current->next=NULL;
		if(getchar()=='\n') {
			break;
		}
		current->next=(linklist *)malloc(sizeof(linklist));
		current=current->next;
	}
	current=result;
	for(p1=poly1; p1!=NULL; p1=p1->next) {
		for(p2=poly2; p2!=NULL; p2=p2->next) {
			newnode=(linklist *)malloc(sizeof(linklist));
			newnode->coef=p1->coef*p2->coef;
			newnode->exp=p1->exp+p2->exp;
			newnode->next=NULL;
			for(current=result->next,prev=result; current!=NULL&&current->exp>newnode->exp; current=current->next,prev=prev->next);
			if(current!=NULL&&current->exp==newnode->exp) {
				current->coef+=newnode->coef;
				free(newnode);
			} else {
				newnode->next=current;
				prev->next=newnode;
			}
		}
	}
	for(current=result->next;current!=NULL;current=current->next){
		printf("%d %d ",current->coef,current->exp);
	}

	return 0;
}



