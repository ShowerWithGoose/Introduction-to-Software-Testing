#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define REP(i,a,b) for(register int i=a;i<=b;i++)
#define PER(i,a,b) for(register int i=a;i>=b;i--)
typedef long long LL;
#define x1 X1
#define y1 Y1
#define x2 X2
#define y2 Y2
int n;
typedef struct{
int X1,X2,Y1,Y2;
}line;
line a[200010];
int b[200010];
int cmp(const void *na,const void * nb){
	line a=*(line *)na,b=*(line *)nb;
	if(a.x1!=b.x1)return a.x1<b.x1?-1:1;
	return a.y1<b.y1?-1:1;
}
int main(){
	scanf("%d",&n);
	REP(i,1,n)scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);//先左下角在右上角
	qsort(a+1,n,sizeof(a[1]),cmp);
	REP(i,1,n){
		int tx=a[i].x2,ty=a[i].y2;
		int ans=1;
		REP(j,i+1,n){
			if(a[j].x1==tx&&a[j].y1==ty){
				ans++;
				tx=a[j].x2;ty=a[j].y2;
			}
		}
		b[i]=ans;
	}
	int pos=1;
	REP(i,1,n)
		if(b[i]>b[pos])pos=i;
	printf("%d %d %d",b[pos],a[pos].x1,a[pos].y1);
}


