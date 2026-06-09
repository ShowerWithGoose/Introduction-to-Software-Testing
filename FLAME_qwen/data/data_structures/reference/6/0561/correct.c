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
int s[10010],top,x,y;
int main(){
//	freopen("a.in","r",stdin);
	while(1){
		scanf("%d",&x);
		if(x==-1)return 0;
		if(x==1){
			scanf("%d",&y);
			if(top==100){
				printf("error ");
				continue;
			}
			s[++top]=y;
		}
		if(!x){
			if(!top){
				printf("error ");
				continue;
			}
			printf("%d ",s[top--]);
		}
	}
}



