#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct l{
	int x1;
	int y1;
	int x2;
	int y2;
	int len;
} line; 

line que[105];
int n;
int cmp(const void*,const void*);
int bisearch(int,int);
int dp(int);
int main()
{
	int i,a,b,c,d,max=0,mp=0,tlen;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		que[i].x1 = a;
		que[i].y1 = b;
		que[i].x2 = c;
		que[i].y2 = d;
	}
	qsort(&que[1],n,sizeof(line),cmp);
	for(i=1;i<=n;i++){
		tlen = dp(i);
		if(tlen>max){
			max = tlen;
			mp = i;
		}
	}
	printf("%d %d %d",max,que[mp].x1,que[mp].y1);
	return 0;
}
int bisearch(int x,int y)
{
	int low=1,high=n,t,tar=0;
	while(low<=high){
		t = (low+high)/2;
		if(que[t].x1==x){
			if(que[t].y1==y){
				tar = t;
				return tar;
			}
			else if(que[t].y1<y){
				low = t+1;
				continue;
			}
			else if(que[t].y1>y){
				high = t-1;
				continue;
			}
		}
		else if(que[t].x1<x){
				low = t+1;
				continue;
			}
			else if(que[t].x1>x){
				high = t-1;
				continue;
			}
	}
	return tar;
}
int dp(int k)
{
	int next;
	if(que[k].len>0){
		return que[k].len;
	}
	
	next = bisearch(que[k].x2,que[k].y2);
	if(next==0){
		que[k].len = 1;
		return que[k].len;
	}
	else{
		que[k].len = dp(next)+1;
		return que[k].len;
	}
	
}


int cmp(const void* p1,const void* p2)
{
	line *a1,*a2;
	a1 = (line*)p1;
	a2 = (line*)p2;
	if((a1->x1)<(a2->x1)){
		return -1;
	}
	else if((a1->x1)==(a2->x1)){
		if((a1->y1)<(a2->y1)){
			return -1;
		}
		else{
			return 1;
		}
	}
	else{
		return 1;
	}
}

















