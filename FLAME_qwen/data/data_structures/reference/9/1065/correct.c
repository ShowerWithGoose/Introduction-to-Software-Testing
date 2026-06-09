#include<stdio.h>
struct segment{
	int x1,x2;
	int y1,y2;
};
int n;
struct segment list[100];
void qsort(){
	int i,j;
	int tmp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(list[j].x1>list[j+1].x1){
				tmp=list[j].x1;
				list[j].x1=list[j+1].x1;
				list[j+1].x1=tmp;
				
				tmp=list[j].y1;
				list[j].y1=list[j+1].y1;
				list[j+1].y1=tmp;
				
				tmp=list[j].x2;
				list[j].x2=list[j+1].x2;
				list[j+1].x2=tmp;
				
				tmp=list[j].y2;
				list[j].y2=list[j+1].y2;
				list[j+1].y2=tmp;
			}
		}
	}
}
int main(){
	int i,j,l;
	int sum,max=0;
	int startx,starty;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&list[i].x1,&list[i].y1,&list[i].x2,&list[i].y2);
	}
	qsort();
	
	for(i=0;i<n;i++){
		sum=0;
		l=i;
		for(j=i+1;j<n;j++){
			if((list[l].x2==list[j].x1) &&(list[l].y2==list[j].y1)){
				sum++;
				l=j;
			}
		}
		if(sum>max){
			max=sum;
			startx=list[i].x1;
			starty=list[i].y1;
		}
	}
	printf("%d %d %d",max+1,startx,starty);
	return 0;
}

