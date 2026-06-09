#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
struct node{
	int x1,y1;
	int x2,y2;
	struct node *link;
}list[1000];

int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d%d%d",&list[i].x1,&list[i].y1,&list[i].x2,&list[i].y2);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(list[i].x2==list[j].x1&&list[i].y2==list[j].y1){
				list[i].link=&list[j];
				break;
			}
		}
	}
	int x0,y0;
	int num,count;
	num=count=0;
	for(i=1;i<=n;i++){
		struct node *p;
		p=&list[i];
		while(p!=NULL){
			p=p->link;
			count++;
		}
		if(count>num){
			num=count;
			x0=list[i].x1;
			y0=list[i].y1;
		}
		count=0;
	}
	printf("%d %d %d",num,x0,y0);
	return 0;
}








