#include<stdio.h>
#include<string.h>
typedef struct line{
	int x[100];
	int y[100];
}line,*pline;
int main(){
    line start;
    line end;
	int n,m;
	int i,j=0;
	int max,maxx;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&start.x[i],&start.y[i],&end.x[i],&end.y[i]);
	}
	maxx,max=1;
	for(i=0;i<n;i++){
		max=1;
		xx:
		for(j=0;j<n;j++){
			if((start.x[j]==end.x[i]&&start.y[j]==end.y[i])){
				max++;
				end.x[i]=end.x[j];
				end.y[i]=end.y[j];
				goto xx;
			}
			else if((start.x[i]==end.x[j]&&start.y[i]==end.y[j])){
				max++;
				start.x[i]=start.x[j];
				start.y[i]=start.y[j];
				goto xx;
			}
		}
		if(max>=maxx){
			maxx=max;
			m=i;
		}
	}
	printf("%d %d %d",maxx,start.x[m],start.y[m]);
	return 0;
}

