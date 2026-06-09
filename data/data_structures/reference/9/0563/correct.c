#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
struct node{
	int x1;int y1;
	int x2;int y2;
	int link;
}a[1024];
int compare (const void *a,const void *b){
	struct node *c=(struct node*)a;
	struct node *d=(struct node*)b;
	if(c->x1!=d->x1)return c->x1-d->x1;
	else return (c->y1-d->y1); 
}
int search(struct node *a,int i,int n){
	int j=i+1;int flag=0;
	for(j=i+1;j<n&&flag==0;j++){
		if((a[i].x2==a[j].x1)&&(a[i].y2==a[j].y1)){
			flag=1;
		}
	}
	if(flag==1){
		return 1+search(a,j-1,n);
	}
	else return 0;
	
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
	qsort(a,n,sizeof(a[0]),compare);
	for(int i=0;i<n;i++){
		a[i].link=search(a,i,n);
	}
	int max=0;int maxnum=0;
	for(int i=0;i<n;i++){
		if(a[i].link>max){
			max=a[i].link;
			maxnum=i;
		}
	}
	printf("%d %d %d",a[maxnum].link+1,a[maxnum].x1,a[maxnum].y1);
	return 0;
 } 

