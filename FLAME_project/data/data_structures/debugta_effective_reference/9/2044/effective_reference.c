#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#define FOR(A,b,c) for(int A=b;A<c;A++)
#define MaxTo(A,b) (A)=(A)>(b)?(A):(b)
#define max(A,b) ((A)>(b)?(A):(b))
#define min(A,b) ((A)<(b)?(A):(b))
#define ll long long
#define ull unsigned long long
#define FO2(n,M) for(int i=0;i<n;i++)for(int j=0;j<M;j++)
#define swap(type,A,b) {type t=A;A=b;b=t;}
int n;
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
line A[122];
int main()
{
	scanf("%d",&n);
	FOR(i,0,n){
		A[i].Length=1;
		scanf("%d%d%d%d",&A[i].p[0].x,&A[i].p[0].y,&A[i].p[1].x,&A[i].p[1].y);
	}
	FOR(i,0,n)
	FOR(j,0,i)
	Connect(A+i,A+j);
	int mx=0,pos;
	for(int i=0;i<n;i++)
	if(mx<A[i].Length){
		mx=A[i].Length;
		pos=i;
	}
	printf("%d %d %d\n",mx,A[pos].p[0].x,A[pos].p[0].y);
	return 0;
}


