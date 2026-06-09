#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct node{
		int X1;
		int Y1;
		int X2;
		int Y2;
		int N;
		int f;
	};
int compar(const void *p1, const void *p2){
	struct node *a=(struct node *)p1;
	struct node *b=(struct node *)p2;
	return (a->X1 -b->X1 );
}

int main(){
	int n,i,j,x1,x2,y1,y2,num,p;
	struct node node[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		node[i].N =1;
		node[i].f =0;
	}
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		node[i].X1 =x1;
		node[i].X2 =x2;
		node[i].Y1 =y1;
		node[i].Y2 =y2;
	}
	qsort(node,n,sizeof(struct node),compar);
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(node[i].X2 ==node[j].X1 &&node[i].Y2 ==node[j].Y1 &&node[i].f ==0){
				node[i].X2 =node[j].X2 ;
				node[i].Y2 =node[j].Y2 ;
				node[i].N ++;
				node[j].f =1;
			}
		}
	}
	num=node[0].N ;
	p=0;
	for(i=1;i<n;i++){
		if(node[i].N >num){
			num=node[i].N ;
			p=i;
		}
	}
	printf("%d %d %d",num,node[p].X1 ,node[p].Y1 );
}

/**/

