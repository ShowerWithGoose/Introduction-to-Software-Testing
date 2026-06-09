#include<stdio.h>
#include<stdlib.h>
struct data{
	int x1;
	int y1;
	int x2;
	int y2;
	int value;
}spot[1024];
int cmp(const void *p1,const void *p2);
int main(){
	int n;
	scanf("%d",&n);
	int ans=1;
	int ansx=0,ansy=0;
	int pos=0; 
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d",&spot[i].x1,&spot[i].y1,&spot[i].x2,&spot[i].y2);
		spot[i].value=1;
	}
	qsort(spot,n,sizeof(struct data),cmp);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;j++){
			if(j!=i){
				if((spot[j].x1==spot[i].x2)&&(spot[j].y1==spot[i].y2)){
											spot[i].x2=spot[j].x2;
											spot[i].y2=spot[j].y2;
											spot[i].value+=spot[j].value;
											if(ans<=spot[i].value){
											ans=spot[i].value;
											pos=i;
											}
											spot[j].x1=0;
											spot[j].y1=0;
											spot[j].x2=0;
											spot[j].y2=0;
											spot[j].value=0;
										}
			}
		}
	}
	printf("%d %d %d",ans,spot[pos].x1,spot[pos].y1);
	return 0;
}
int cmp(const void *p1,const void *p2){
	struct data *a=(struct data*)p1;
	struct data *b=(struct data*)p2;
	if(a->x1!=b->x1) return a->x1-b->x1;
	else return a->y1-b->y1;
}

