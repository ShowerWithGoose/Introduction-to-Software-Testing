#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct node {
	int x1;
	int y1;
	int x2;
	int y2;
	int line_sum;
}line[102];
int cmp1(const void *a,const void *b){
	struct node c=*(struct node *)a;
	struct node d=*(struct node *)b;
	if(c.x1!=d.x1){
		if(c.x1<d.x1){
			return -1;
		}
		else{
			return 1;
		}
	}
	else{
		if(c.y1<d.y1){
			return -1;
		}
		else{
			return 1;
		}
	}
}
int cmp2(const void *a,const void *b){
	struct node c=*(struct node *)a;
	struct node d=*(struct node *)b;
	if(c.line_sum<d.line_sum){
		return 1;
	}
	else{
		return -1;
	}
}
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d %d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	}
	for(i=0;i<n;i++){
		line[i].line_sum=1;
	}
	qsort(line,n,sizeof(line[0]),cmp1);
	//for(i=0;i<n;i++){
	//	printf("%d %d %d %d %d\n",line[i].x1,line[i].y1,line[i].x2,line[i].y2,line[i].line_sum);
	//}
	for(i=0;i<n;i++){
		if(line[i].line_sum==0){
			continue;
		}
		for(j=0;j<n;j++){
			if(line[j].line_sum==0||j==i){
				continue;
			}
			else{
				if(line[j].x1==line[i].x2&&line[j].y1==line[i].y2){
					line[i].x2=line[j].x2,line[i].y2=line[j].y2;
					line[i].line_sum++;
					line[j].line_sum=0;
				}
			}
		}
	}
	qsort(line,n,sizeof(line[0]),cmp2);
	//for(i=0;i<n;i++){
	//	printf("%d %d %d %d %d\n",line[i].x1,line[i].y1,line[i].x2,line[i].y2,line[i].line_sum);
	//}
	printf("%d %d %d",line[0].line_sum,line[0].x1,line[0].y1);
	return 0;
}

