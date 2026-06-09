//line
#include<stdio.h>

typedef struct line_1{
	int x1,y1;
	int x2,y2;
	int temp;
	struct line_1 *next;
}line;
int main()
{
	line lin[101]={};
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d%d%d",&lin[i].x1,&lin[i].y1,&lin[i].x2,&lin[i].y2);
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(lin[j].x1>lin[j+1].x1){
				line op;
				op=lin[j];
				lin[j]=lin[j+1];
				lin[j+1]=op;
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				continue;
			}
			if(lin[i].x2==lin[j].x1&&lin[i].y2==lin[j].y1){
				lin[i].next=&lin[j];
			}
		}
	}
	int a[101][3]={};
	line *op;
	int pm=0;
	for(int i=0;i<n;i++){
		if(lin[i].temp==1){
			continue;
		}
		op=&lin[i];
		while(op->next!=0){
			op->temp=1;
			op=op->next;
			a[pm][0]++;
		}
		if(op!=&lin[i]){
			a[pm][0]++;
			a[pm][1]=lin[i].x1;
			a[pm][2]=lin[i].y1;
			pm++;
		}
	}
	int max=0;
	for(int i=1;i<pm;i++){
		if(a[max][0]<a[i][0]){
			max=i;
		}
	}
	printf("%d %d %d",a[max][0],a[max][1],a[max][2]);
	return 0;
} 

