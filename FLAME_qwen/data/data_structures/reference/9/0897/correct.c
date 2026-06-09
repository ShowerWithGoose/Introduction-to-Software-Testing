#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct node {
	int x1;
	int y1;
	int x2;
	int y2;
	int n;
	int flag;
};
int cmp(const void *a, const void*b)          //Ð¡µ½´ó 
{
    struct node * c = (struct node *)a;
    struct node * d = (struct node *)b;
    return c->x1 - d->x1;
}

int main(){
	int sum;
	scanf("%d",&sum);
	struct node ff[sum];
	int a,b,c,d;
	int i=0;
	for( i=0;i<sum;i++){
		scanf("%d%d%d%d",&ff[i].x1,&ff[i].y1,&ff[i].x2,&ff[i].y2);
		ff[i].n=1;
		ff[i].flag=0;
		/*int flag=0;
		for(int j=0;j<i;j++){
			if(ff[j].x2==a&&ff[j].y2==b){
				ff[j].x2=c;
				ff[j].y2=d;
				ff[j].n++;
				flag=1;
			}
			if(ff[j].x1==c&&ff[j].y1==d){
				ff[j].x1=a;
				ff[j].y1=b;
				ff[j].n++;
				flag=1;
			}
		}
		if(flag==0){
			ff[i].x1=a;
			ff[i].y1=b;
			ff[i].x2=c;
			ff[i].y2=d;
			ff[i].n=1;
			i++;
		}*/
		
	}
	qsort(ff,i,sizeof(struct node),cmp);
	for(int j=0;j<i;j++){
		if(ff[j].flag==0){
		for(int k=j+1;k<i;k++){
			if(ff[k].flag==0&&ff[k].x1==ff[j].x2&&ff[k].y1==ff[j].y2){
				ff[k].flag=1;
				ff[j].x2=ff[k].x2;
				ff[j].y2=ff[k].y2;
				ff[j].n++;
				
			}
		}
	}
	}
	int max=1,maxn=1;
	for(int j=0;j<i;j++){
		if(ff[j].n>max){
			max=ff[j].n;
			maxn=j;
		}
	}
	printf("%d %d %d ",max,ff[maxn].x1,ff[maxn].y1);
	
	return 0;
}

