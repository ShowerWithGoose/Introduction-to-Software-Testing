#include<stdio.h>
struct line{
	int headx;
	int heady;
	int tailx;
	int taily;
}lines[10000],temp;
int isadj(int x,int y) {
	if(lines[x].tailx == lines[y].headx && lines[x].taily==lines[y].heady)
	{
	 return 1;
	}
	else return 0; 
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&lines[i].headx,&lines[i].heady,&lines[i].tailx,&lines[i].taily);
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(lines[j].headx<=lines[i].headx){
				temp=lines[j];
				lines[j]=lines[i];
				lines[i]=temp;
			}
		}
	}
	int ans, maxw = 0;
	for(int i=0;i<n;i++) {
		int w = 1, last = i;
		for(int j=i+1;j<n;j++) {
			if(isadj(last, j)) {
				last = j;
				w++;
			}
		}
		if(w > maxw) {
			maxw = w;
			ans = i;
		}
	}
	printf("%d %d %d",maxw,lines[ans].headx,lines[ans].heady);	
}

