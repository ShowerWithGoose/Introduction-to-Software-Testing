#include <stdio.h>
#include <stdlib.h>
struct line{
	int x1;
	int x2;
	int y1;
	int y2;
}line[105],s;
/*int cmp(const void* a,const void* b){
	struct line *x=(struct line*)a;
	struct line *y=(struct line*)b;
	if(x->x1!=y->x1)
	return x->x1>y->x1;
	else
	return x->y1>y->y1;
}*/
int cnt=0;
int search(int n,int m){
	int i;
	for(i=n+1;i<m;i++){
		if(line[n].x2==line[i].x1&&line[n].y2==line[i].y1){
			cnt++;
			return search(i,m);
		}
	}
	
}
int main(){
	int n;
	scanf("%d",&n);
	int i,j,k,m;
	int max=0;
	int flag=10000;
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	}
	//qsort(line,n,sizeof(struct line),cmp);
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(line[i].x1>line[j].x1){
				s=line[i];
				line[i]=line[j];
				line[j]=s;
			}
		}
	}
	for(i=0;i<n;i++){
	search(i,n);	
		 if(cnt>max){
		 	max=cnt;
		 	flag=i;
		 }
		 cnt=0;
}
    printf("%d %d %d",max+1,line[flag].x1,line[flag].y1);
	return 0;
}

