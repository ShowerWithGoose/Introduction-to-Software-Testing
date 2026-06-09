#include<stdio.h>

struct segment{
	int start[2];
	int end[2];
	int len;
};

void sort(struct segment line[],int n){//按照起点x坐标排序 
	int i,j;
	struct segment b;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(line[j].start[0]>line[j+1].start[0]){
				b=line[j];
				line[j]=line[j+1];
				line[j+1]=b;
			}
		}
	}
	for(i=0;i<n;i++){
//		printf("%d,%d %d,%d\n",line[i].start[0], line[i].start[1], line[i].end[0], line[i].end[1]);
	}
}

int maxline(struct segment line[],int n){
	int i,j,k,m,max=0;
	for (i=0;i<n;i++){
		m=1;
		k=i;
		while(1){
			for(j=1;k+j<n;j++){
				if(line[k].end[0]==line[k+j].start[0]&&line[k].end[1]==line[k+j].start[1]){
//					printf("%d %d %d\n",i,line[k].end[0],line[k].end[1]) ;
					m++;
					k=k+j;
					j=0;
					break;
				}
			}
			if(k+j==n)
				break;
		}
		line[i].len=m;
		if(line[i].len>line[max].len)
			max=i;
	}
	return max;
}
int main(){
	int n;
	scanf("%d",&n);
	struct segment line[n];
	int i;
	for(i=0;i<n;i++)
		scanf("%d %d %d %d",&line[i].start[0],&line[i].start[1],&line[i].end[0],&line[i].end[1]);
	sort(line,n);
	int max;
	max=maxline(line,n);
	printf("%d %d %d",line[max].len,line[max].start[0],line[max].start[1]);
	return 0;
}

