#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define MaxTo(a,b) (a)=(a)>(b)?(a):(b)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define ll long long
#define ull unsigned long long
#define FO2(N,M) for(int i=0;i<N;i++)for(int j=0;j<M;j++)
#define swap(type,a,b) {type t=a;a=b;b=t;}
int N;
typedef struct _line{
	int Length;
	struct Point{
		int x,y;
	}p[2];
}line;
int Connect(line *A,line *B){//B接在A左边返回-1，接在A右边返回1，不接返回0
	if(A->Length==0||B->Length==0) return 0;//不存在的线段
	if(A->p[0].x==B->p[1].x&&A->p[0].y==B->p[1].y){
		A->p[0]=B->p[0];
		A->Length+=B->Length;
		B->Length=0;
	}
	if(A->p[1].x==B->p[0].x&&A->p[1].y==B->p[0].y){
		A->p[1]=B->p[1];
		A->Length+=B->Length;
		B->Length=0;
	}
	return 0;
}
line a[122];
int main()
{
	scanf("%d",&N);
	FOR(i,0,N){
		a[i].Length=1;
		scanf("%d%d%d%d",&a[i].p[0].x,&a[i].p[0].y,&a[i].p[1].x,&a[i].p[1].y);
	}
	FOR(i,0,N)
	FOR(j,0,i)
	Connect(a+i,a+j);
	int MaxLen=0,MaxID;
	for(int i=0;i<N;i++)
	if(MaxLen<a[i].Length){
		MaxLen=a[i].Length;
		MaxID=i;
	}
	printf("%d %d %d\n",MaxLen,a[MaxID].p[0].x,a[MaxID].p[0].y);
	return 0;
}


