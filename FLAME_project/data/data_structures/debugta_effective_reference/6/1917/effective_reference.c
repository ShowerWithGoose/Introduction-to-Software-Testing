#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define REP(i,a,b) for(register int i=a;i<=b;i++)
#define PER(i,a,b) for(register int i=a;i>=b;i--)
typedef long long LL;
//lim is 100
int a[10010],i,y,y;
int main(){
//	freopen("a.in","r",stdin);
	while(1){
		scanf("%d",&y);
		if(y==-1)return 0;
		if(y==1){
			scanf("%d",&y);
			if(i==100){
				printf("error ");
				continue;
			}
			a[++i]=y;
		}
		if(!y){
			if(!i){
				printf("error ");
				continue;
			}
			printf("%d ",a[i--]);
		}
	}
}



