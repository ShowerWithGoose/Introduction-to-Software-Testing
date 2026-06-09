#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *pa,const void *pb);
struct point{
	int x;
	int y;
};
struct line{
	struct point v1;
	struct point v2;
};	
int search(int);
int c,n;
struct line l[105];
int index[105];
int count[105];
int i=0,j;
int main(){
scanf("%d",&n);
for(i=0;i<n;i++){
scanf("%d%d%d%d",&l[i].v1.x,&l[i].v1.y,&l[i].v2.x,&l[i].v2.y);	
index[i]=i;
}
	qsort(index,n,sizeof(int),cmp);
for(i=0;i<n;i++){
	c=1;
search(i);
count[i]=c;
//printf("%d ",count[i]);
}
int r=count[0];
int s;
for(s=0;s<n;s++){
	if(count[s]>r) r=count[s];
}
for(s=0;s<n;s++){
	if(count[s]==r){
	printf("%d %d %d",r,l[index[s]].v1.x,l[index[s]].v1.y);	
	}
}
}
int cmp(const void *pa,const void *pb){
	int qa=*((int *)pa);
	int qb=*((int *)pb);
	return l[qa].v1.x-l[qb].v1.x;
}
int search(i){
	int k;
	for(k=i;k<n;k++){
		if(l[index[i]].v2.x==l[index[k]].v1.x && l[index[i]].v2.y==l[index[k]].v1.y){
			c++;
			j=k;
			search(j);
		}
	}
	return c;
}

