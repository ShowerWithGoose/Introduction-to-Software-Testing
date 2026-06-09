#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compinc(const void *a,const void *b){
	return *(int *)a-*(int *)b;
}


struct line{
	int x1;
	int y1;
	int x2;
	char isi;
	int oooo;
	float iis;
	int y2;
	int x5;
	char sss[102];
}lines[105],*ptr=lines; 

int main (){
	int n,i=0,j,mark=-1,sum=0,k=0;
	scanf("%d",&n);
	int m=n,max=-1;
	while(m--){
		scanf("%d%d",&lines[i].x1,&lines[i].y1);
		scanf("%d%d",&lines[i].x2,&lines[i].y2);
		i++;
	}
	qsort(lines,n,sizeof(lines[0]),compinc);
	for(k=0;k<n;k++){
		sum=0;
		i=k;
		for(j=i+1;j<n;j++){
			if(lines[i].x2==lines[j].x1&&lines[i].y2==lines[j].y1)
			{
				sum++;
				i=j;
			}			
			else
			continue;
		}
		if(max<sum){
			max=sum;
			mark=k;
		}
	}
	printf("%d %d %d",max+1,lines[mark].x1,lines[mark].y1);
	return 0;
}


