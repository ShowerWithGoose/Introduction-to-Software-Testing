#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int i,n,j,max=0;
int count[3000];
struct xian{
	int x;
	int y;
};

	int cmp(const void*a,const void*b) {
	struct xian* c,*d;
	c=(struct xian *)a;
	d=(struct xian*)b;
	return (d[0].x-c[0].x);}

int main(){
	scanf("%d",&n);
struct xian line[3000][2];
for(i=0;i<n;i++)count[i]++;
for(i=0; i<n; i++) {
		scanf("%d%d%d%d",&line[i][0].x,&line[i][0].y,&line[i][1].x,&line[i][1].y);
	}
qsort(line,n,sizeof(line[0]),cmp);
for(i=0;i<n;i++){
	for(j=i+1;j<n;j++){
		if(line[i][0].x==line[j][1].x &&line[i][0].y==line[j][1].y)count[j]+=count[i];
		}
	}
    for(i=0; i<n; i++) {
		if(count[i]>max) max=count[i];
	}
 	for(i=0; i<n; i++) {
		if(count[i]==max) printf("%d %d %d",count[i],line[i][0].x,line[i][0].y);
	}
	return 0;
}




