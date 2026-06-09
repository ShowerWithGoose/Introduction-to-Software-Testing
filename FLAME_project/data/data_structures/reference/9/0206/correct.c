#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

struct line{
	int x1;
	int y1;
	int x2;
	int y2;
}l[200];

int cmp(const void *a,const void *b){
	struct line *aa=(struct line*)a;
	struct line *bb=(struct line*)b;
	return ((aa->x1)-(bb->x1));
}

int main(){
	int count;
	int max=0;
	int n;
	int i;
	int j;
	int k;
	int p=0;
	int q=0;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
	}
	qsort(l,n,sizeof(struct line),cmp);
	
	//for(i=0;i<n;i++){
	//	printf("%d %d %d %d\n",l[i].x1,l[i].y1,l[i].x2,l[i].y2);
	//}
	
	for(i=0;i<n;i++){
		k=i;
		count=0;
		for(j=i+1;j<n;j++){
			if((l[j].x1==l[k].x2)&&(l[j].y1==l[k].y2)){
				count++;
				k=j;
			}
		}
		if(count>max){
			max=count;
			p=l[i].x1;
			q=l[i].y1;
		}
	}
	printf("%d %d %d",max+1,p,q);
}

