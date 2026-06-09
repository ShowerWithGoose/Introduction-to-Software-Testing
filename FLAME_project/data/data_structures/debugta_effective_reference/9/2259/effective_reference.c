#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct l{
	int a1;
	int b1;
	int a2;
	int b2;
	int len;
} line; 

line l[105];
int n;
int cmp(const void*,const void*);
int bisearch(int,int);
int dp(int);
int main()
{
	int i,a,b,c,d,max=0,t=0,low;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		l[i].a1 = a;
		l[i].b1 = b;
		l[i].a2 = c;
		l[i].b2 = d;
	}
	qsort(&l[1],n,sizeof(line),cmp);
	for(i=1;i<=n;i++){
		low = dp(i);
		if(low>max){
			max = low;
			t = i;
		}
	}
	printf("%d %d %d",max,l[t].a1,l[t].b1);
	return 0;
}
int bisearch(int x,int y)
{
	int low=1,high=n,t,judge=0;
	while(low<=high){
		t = (low+high)/2;
		if(l[t].a1==x){
			if(l[t].b1==y){
				judge = t;
				return judge;
			}
			else if(l[t].b1<y){
				low = t+1;
				continue;
			}
			else if(l[t].b1>y){
				high = t-1;
				continue;
			}
		}
		else if(l[t].a1<x){
				low = t+1;
				continue;
			}
			else if(l[t].a1>x){
				high = t-1;
				continue;
			}
	}
	return judge;
}
int dp(int a)
{
	int next;
	if(l[a].len>0){
		return l[a].len;
	}
	
	next = bisearch(l[a].a2,l[a].b2);
	if(next==0){
		l[a].len = 1;
		return l[a].len;
	}
	else{
		l[a].len = dp(next)+1;
		return l[a].len;
	}
	
}


int cmp(const void* p1,const void* p2)
{
	line *a1,*a2;
	a1 = (line*)p1;
	a2 = (line*)p2;
	if((a1->a1)<(a2->a1)){
		return -1;
	}
	else if((a1->a1)==(a2->a1)){
		if((a1->b1)<(a2->b1)){
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

















