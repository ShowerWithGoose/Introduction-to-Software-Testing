#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h> 
#include<ctype.h>
struct point{
	int x;
	int y;
};
struct line{
	struct point l;
	struct point r;
	int count;
	int flag;
	struct point start;
	struct point finish;
};
typedef struct line Line;
Line list[105];
int n;
void getlen(int m);
int rightfind(int m);
int leftfind(int m);
int main(){
	int i=0;
	scanf("%d",&n);
	while(i<n){
		scanf("%d%d%d%d",&list[i].l.x,&list[i].l.y,&list[i].r.x,&list[i].r.y);
		list[i].flag=0,list[i].count=1;
		i++;
	}
	i=0;
	while(i<n){
		if(list[i].flag==0){
			getlen(i);
		}
		i++;
	}	
	i=0;
	int max=0;
	while(i<n){
		if(list[i].count>list[max].count) max=i;
		i++;
	}
	printf("%d %d %d",list[max].count,list[max].start.x,list[max].start.y);
	return 0;
}
void getlen(int m){
	list[m].flag=1;
	list[m].finish=	list[m].r;
	list[m].start=list[m].l;
	int k=m;
	while((k=rightfind(k))!=EOF){
		list[k].flag=1;
		list[m].count++;
		list[m].finish=list[k].r;
	}
	k=m;
	while((k=leftfind(k))!=EOF){
		list[k].flag=1;
		list[m].count++;
		list[m].start=list[k].l;
	}
}
int rightfind(int m){
	int i=0;
	while(i<n){
		if(list[i].flag==0&&list[m].r.x==list[i].l.x&&list[m].r.y==list[i].l.y) return i;
		i++;
	}
	return -1;
}
int leftfind(int m){
	int i=0;
	while(i<n){
		if(list[m].l.x==list[i].r.x&&list[m].l.y==list[i].r.y&&list[i].flag==0) return i;
		i++;
	}
	return -1;
}

