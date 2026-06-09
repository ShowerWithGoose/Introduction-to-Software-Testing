#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node{
	int x1;
	int y1;
	int x2;
	int y2;
}str;
str line[100];
int cmp_struct(const void *_a ,const void *_b) {
	struct node *a=(struct node *)_a;
	struct node *b=(struct node *)_b;
	return a->x1 > b->x1?1:-1; 
}
int l[100][5];
int main()
{
	int n,m=0,f=0,max=0,ans;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	qsort(line,n,sizeof(line[0]),cmp_struct);
	for(int i=0;i<n;i++){
		for(int j=0;j<=m;j++){//头接头的情况 ！ 原点！ 
			if(l[j][3]==line[i].x1&&l[j][4]==line[i].y1){
				l[j][3]=line[i].x2;
				l[j][4]=line[i].y2;
				l[j][0]++;
				f=1;
				break;
			}
		}
		if(f==0){
			m++;
			l[m][0]++;
			l[m][1]=line[i].x1;
			l[m][2]=line[i].y1;
			l[m][3]=line[i].x2;
			l[m][4]=line[i].y2;
		}	
		f=0;
	}
	for(int i=0;i<=m;i++){
		if(l[i][0]>max){
			max=l[i][0];
			ans=i;
		}
	}
	printf("%d %d %d",max,l[ans][1],l[ans][2]);
	return 0;
}




