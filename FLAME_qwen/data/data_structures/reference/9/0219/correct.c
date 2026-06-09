#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
struct line{
	int x1,y1,x2,y2;
	struct line* link;
};
typedef struct line line;
typedef struct line* lineptr;

int getlen(lineptr list){
	lineptr p;
	int n=0;
	for (p=list;p!=NULL;p=p->link) n++;
	return n;
}
lineptr a[55];
int main(){
	int n,i,j,max=0,record;
	scanf("%d",&n);
	for (i=1;i<=n;i++){
		a[i]=(lineptr)malloc(sizeof(line));
		scanf("%d%d%d%d",&(a[i]->x1),&(a[i]->y1),&(a[i]->x2),&(a[i]->y2));
		a[i]->link=NULL;
	}
	for (i=1;i<=n-1;i++){
		for (j=i+1;j<=n;j++){
			if (a[i]->x2==a[j]->x1&&a[i]->y2==a[j]->y1){
				a[i]->link=a[j];
			}
			else if(a[j]->x2==a[i]->x1&&a[j]->y2==a[i]->y1){
				a[j]->link=a[i];
			}
		}
	}
	for(i=1;i<=n;i++){
		if (getlen(a[i])>max){
			max=getlen(a[i]);
			record=i;
		}
	}
	printf("%d %d %d",max,a[record]->x1,a[record]->y1);
	for (i=1;i<=n;i++){
		free(a[i]);
	}
	return 0;
}

