#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct node{
	int x1;int y1;
	int x2;int y2;
	struct node * pNext; 
}Node;

typedef struct nOde{
	int xh;int yh;
	int xt;int yt;
	int count;
} List;

Node point[110];
int n;

List judge (Node point[],int w){
	int i,j,k;
	List L;
	L.xh =point[w].x1 ;
	L.yh =point[w].y1 ;
	L.xt =point[w].x2 ;
	L.yt =point[w].y2 ;
	L.count =0;
	for(i=0;i<n;i++){
		if(i==w) continue;
		if(L.xh  ==point[i].x2 &&L.yh ==point[i].y2 ){
			L.count ++;
			L.xh =point[i].x1 ;
			L.yh =point[i].y1 ;
			i=0;
		}
		else if(L.xt  ==point[i].x1 &&L.yt ==point[i].y1 ){
			L.count ++;
			L.xt =point[i].x2 ;
			L.yt =point[i].y2 ;
			i=0;
		}
	}
	return L;
}
int main()
{
	int i,j,k;
	int m;
	List Lmax;
	List L1[130];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&point[i].x1 ,&point[i].y1 ,&point[i].x2 ,&point[i].y2 );
	}
	L1[0]=judge(point,0);
	Lmax=L1[0];
	for(i=1;i<n;i++){
		L1[i]=judge(point,i);
		if(L1[i].count >Lmax.count ) Lmax=L1[i];
	}
	printf("%d %d %d",Lmax.count+1 ,Lmax.xh ,Lmax.yh );
	return 0;
}

