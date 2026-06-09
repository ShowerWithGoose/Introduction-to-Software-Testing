#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define REP(i,a,b) for(register int i=a;i<=b;i++)
#define PER(i,a,b) for(register int i=a;i>=b;i--)
typedef long long LL;
typedef struct{
	int a;
	int p;
	//ax^p
}mul;
mul m1[100010],m2[100010],ans[100010],mtp[100010],oumtp[100010];
int x,y,l1,l2,top,cnt,tot;
int cmp(const void *na,const void *nb){
	mul a=*(mul *)na,b=*(mul *)nb;
	return a.p>b.p?-1:1;
}
int main(){
	while(1){
		scanf("%d%d",&x,&y);
		char c=getchar();
		m1[++l1]=(mul){x,y};
		if(c=='\n')break;
	}
	while(scanf("%d%d",&x,&y)!=EOF)m2[++l2]=(mul){x,y};
	REP(i,1,l1)
		REP(j,1,l2)
			ans[++top]=(mul){m1[i].a*m2[j].a,m1[i].p+m2[j].p};
	qsort(ans+1,top,sizeof(ans[1]),cmp);
	REP(i,1,top)
		if(mtp[cnt].p==ans[i].p)
			mtp[cnt].a+=ans[i].a;
		else
			mtp[++cnt]=ans[i];
	REP(i,1,cnt)
		if(mtp[i].a)
			oumtp[++tot]=mtp[i];
	REP(i,1,tot)
		printf("%d %d ",oumtp[i].a,oumtp[i].p);
}


