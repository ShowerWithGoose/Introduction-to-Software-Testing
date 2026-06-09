#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct llist{
		int lx; int ly;
		int rx; int ry;
		struct llist *next;
}line;
int cmp(const void *,const void *);
int main()
{
	int n, i, len[102]={0}, ax, ay, bx, by, j, max=0,flag1=0,flag2=0;
	line lib[102], input[102];
	for(i=0;i<102;i++){
		lib[i].next = NULL;
		input[i].next = NULL;}
	line *p[102]={NULL}, *node;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&input[i].lx,&input[i].ly,&input[i].rx,&input[i].ry);
	qsort(input,n,sizeof(line),cmp);
	for(i=0;i<n;i++){
		for(j=0;len[j]!=0;j++){
			
			if(p[j]->rx==input[i].lx && p[j]->ry==input[i].ly){
				node = (line *)malloc(sizeof(line));
				*node = input[i]; node->next = NULL;
				p[j]->next = node;
				p[j] = p[j]->next;
				len[j]++;
				flag1 = j;
			}
			/*if(lib[j].lx==input.rx && lib[j].ly==input.ry){
				node = (line *)malloc(sizeof(line));
				*node = input; 
				node->next = &lib[j];
				lib[j] = input;
				len[j]++;
				flag2 = j;
			}
			if(flag1!=0 && flag2!=0){
				
			}*/
		}
		if(len[j]==0){
			lib[j] = input[i];
			p[j] = &lib[j];	
			p[j]->next = NULL;
			len[j]++;
		}
	}
	for(i=0;i<100&&len[i]!=0;i++){
		if(max < len[i]){
			max = len[i];
			j = i;}
	}
	printf("%d %d %d", max, lib[j].lx, lib[j].ly);
    return 0;
}

int cmp(const void *a,const void *b){
	line *p1 = (line *)a;
	line *p2 = (line *)b;
	if(p1->lx>p2->lx) return 1;
	if(p1->lx<p2->lx) return -1;
	return 0;
}

