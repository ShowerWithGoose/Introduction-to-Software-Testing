#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	int x1,x2;
	int y1,y2;
	struct node* link;
}Lnode,*LinkList;
int compare(Lnode a,Lnode b);
int cmp(const void *a,const void *b);
int main(){
	int n;
	int i,j;
	Lnode arr[100];
	int max=0,cnt=1;
	int maxx=0,maxy=0;
	LinkList lista,p,q;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&arr[i].x1);
		scanf("%d",&arr[i].y1);
		scanf("%d",&arr[i].x2);
		scanf("%d",&arr[i].y2);
	}
	//按x1从小到大快速排序
	qsort(arr,n,sizeof(arr[0]),cmp);
	
	for(i=0;i<n-1;i++,cnt=1){
		lista=&arr[i];//lista指向第一组数据的地址
		p=lista;
		p->link=NULL;//指向 空
		for(j=i+1;j<n;j++){
			q=&arr[j];
			if(compare(*p,*q)==0)
			continue;
			if(compare(*p,*q)==2)//接后端
			{
				p->link=q;
				q->link=NULL;
				p=q;
				cnt++;
			}
		}
		if(cnt>max)
		{
			max=cnt;
			maxx=lista->x1;
			maxy=lista->y1;
		}
	}
	printf("%d %d %d",max,maxx,maxy);
	return 0;
	
}
int cmp(const void *a,const void *b)
{
	if((*(struct node*)a).x1<(*(struct node*)b).x1)
	return -1;
	else if((*(struct node*)a).x1>(*(struct node*)b).x1)
	return 1;
}
int compare(Lnode a,Lnode b){
//	if(a.x1==b.x2&&a.y1==b.y2)//接前端
//	return 1;
	if(a.x2==b.x1&&a.y2==b.y1)//接后端
	return 2;
	else
	return 0;
}

