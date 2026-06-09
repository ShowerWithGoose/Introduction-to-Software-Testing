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
#define MAXN 120
//define mst(s) memset(s,0,sizeof(s))
typedef struct node{
	int p1x;
	int p1y;
	int p2x;
	int p2y;
	struct node *next;
} linklist;
int cmp(const void *p1,const void *p2){
	linklist a=*(linklist *)p1,b=*(linklist *)p2;
	return a.p1x-b.p1x;
}
linklist line[MAXN],line_[MAXN];
int main(void)
{
//	freopen("in.line.txt","r",stdin);
	int i,j,k,n,m,cnt=0,max=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&line[i].p1x,&line[i].p1y,&line[i].p2x,&line[i].p2y);
	}
	qsort(line,n,sizeof(linklist),cmp);
	
	linklist *head=(linklist*)malloc(sizeof(linklist)),*current=head,*last,lastData,*pmax=line,*p=line_;
	head->next=NULL;
	for(i=1;i<=n;i++){
		current->next=(linklist*)malloc(sizeof(linklist));
		current=current->next;
		*current=line[i-1];
		current->next=NULL;
	}
	current=head;
	head=head->next;
	free(current);
	memset(line,0,sizeof(line));
	while(head!=NULL){
		p[cnt++]=*head;
		last=head;
		for(current=head->next;current!=NULL&&current->p1x<=p[cnt-1].p2x;){
			if(current->p1x==p[cnt-1].p2x&&current->p1y==p[cnt-1].p2y){
				last->next=current->next;
				p[cnt++]=*current;
				free(current);
				current=last->next;
			}else{
				current=current->next;
				last=last->next;
			}
		}
		if(cnt>max){
			linklist *temp=pmax;
			pmax=p;
			p=temp;
			max=cnt;
		}else;
		memset(p,0,sizeof(p));
		cnt=0;
		current=head;
		head=head->next;
		free(current);
	}
	printf("%d %d %d",max,pmax[0].p1x,pmax[0].p1y);

	return 0;
}



