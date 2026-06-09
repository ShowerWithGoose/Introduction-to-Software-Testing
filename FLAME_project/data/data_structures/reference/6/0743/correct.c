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
int Top;
int st[114514];
int main()
{
	int x,op;
	while(1){
		scanf("%d",&op);
		switch(op){
			case 0:{
				if(Top==0) {printf("error ");break;}
				printf("%d ",st[--Top]);break;
			}
			case 1:{
				scanf("%d",&x);
				st[Top++]=x;
				break;
			}
			case -1:{
				return 0;
			}
		}
	}
	return 0;
}


