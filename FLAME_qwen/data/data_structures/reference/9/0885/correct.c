#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define Div 1000000007
#define E 2.71828
#define Pi 3.1415926
#define eps 1e-7
#define ElementType int
#define WeightType int
#define MAXSIZE 10000
typedef struct line *link;
struct line {
	int x1,y1,x2,y2;
}line[MAXSIZE];
struct point{
	int x,y,next;
}a[MAXSIZE];
int dfs(int x)
{
	if(a[x].next)
	return dfs(a[x].next)+1;
	else return 1;
}
int main() {
	//FILE *IN,*OUT;
	//IN=fopen("","r");
	//OUT=fopen("","w");
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int x1,x2,y1,y2,t,i,j,n,flag1,flag2,size=0,g=0,h;
	scanf("%d",&n);
	for(i=1; i<=n; i++) {
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		flag1=flag2=0;
		for(j=1; j<=size; j++) {
			if(x1==a[j].x&&y1==a[j].y)
				flag1=j;
		}
		for(j=1; j<=size; j++) {
			if(x2==a[j].x&&y2==a[j].y)
				flag2=j;
		}
		if(flag1&&flag2){
			a[flag1].next=flag2;
		}
		else if(flag1){
			a[++size].x=x2;
			a[size].y=y2;
			a[flag1].next=size;
		}
		else if(flag2){
			a[++size].x=x1;
			a[size].y=y1;
			a[size].next=flag2;
		}
		else {
			a[++size].x=x1;
			a[size].y=y1;
			a[size].next=size+1;
			a[++size].x=x2;
			a[size].y=y2;
		}
	}for(i=1;i<=size;i++){
		t=dfs(i);
		if(t>g){
			g=t;
			h=i;
		}
	}
	printf("%d %d %d\n",g-1,a[h].x,a[h].y);
	//fclose(IN);
	//fclose(OUT);
	return 0;
}


