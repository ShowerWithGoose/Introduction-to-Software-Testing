#include<stdio.h>
#include<string.h>
struct points{
	int x1;
	int y1;
	int x2;
	int y2;
}; 
void sort(struct points array[],int n){
	int i,j;
	struct points tmp;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(array[i].x1>array[j].x1){
				tmp=array[i];
				array[i]=array[j];
				array[j]=tmp;
			}	
		}
	}
}
int main(){
	struct points info[150];
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d %d %d %d",&info[i].x1,&info[i].y1,&info[i].x2,&info[i].y2);
	sort(info,n);
	int cntmax=1,x1max=0,y1max=0;
	for(i=0;i<n;i++){
		int x2,y2,cnt=1;
		x2=info[i].x2;
		y2=info[i].y2;
		for(j=i+1;j<n;j++){
			if(x2==info[j].x1&&y2==info[j].y1){
				cnt++;
				x2=info[j].x2;
				y2=info[j].y2;
			}
		}
		if(cnt>cntmax){
			cntmax=cnt;
			x1max=info[i].x1;
			y1max=info[i].y1;
		}
	}
	printf("%d %d %d",cntmax,x1max,y1max);
	return 0;
}

