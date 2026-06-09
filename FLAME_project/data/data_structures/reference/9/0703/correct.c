#include<stdio.h>
struct node{
	int x;
	int y;
	int linked;
	struct node* next;
};
int lenth(struct node*);
int main(){
	int n,i,j,max[3]={0};
	struct node point[300]={{0,0,0,NULL}};
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d%d",&point[2*i-1].x,&point[2*i-1].y,&point[2*i].x,&point[2*i].y);
		point[2*i-1].next=point+2*i;
		point[2*i].linked=1;
	}
	for(i=2;i<=2*n;i+=2){
		for(j=1;j<=2*n;j+=2){
			if(point[i].x==point[j].x&&point[i].y==point[j].y){
				point[i].next=point+j;
				point[j].linked=1;
			}
		}
	}
	for(i=1;i<=2*n;i++){
		if(point[i].linked==0){
			if(max[0]<lenth(point+i)){
				max[0]=lenth(point+i);
				max[1]=i;
			}
		}
	}
	printf("%d %d %d",max[0]/2,point[max[1]].x,point[max[1]].y);
	return 0;
}
int lenth(struct node* first){
	if(first->next==NULL)return 1;
	else return lenth(first->next)+1;
}

