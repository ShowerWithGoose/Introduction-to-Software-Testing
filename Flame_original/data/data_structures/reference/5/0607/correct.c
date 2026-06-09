#include<stdio.h>
#include<string.h>
struct node{
	int a;
	int n;
}x[500],y[500];
struct node1{
	long long a;
	long long n;
}ans[2500];
int cnt1,cnt2,cnt=0;

void read(){
	char st[1100];
	int i;
	for(i=1; i<=2; i++){
		gets(st);
		int l=strlen(st);
		int j,tmp=0,c1=0,c2=0,f=1;
		for(j=0; j<l; j++){
		//	printf("%c:",st[j]);
			if(st[j]=='-') {
				f=-f; continue;
			}
			if(st[j]>'9'||st[j]<'0') {
				if(i==1){
					if(c1==c2) {
						c1++;
						x[c1].a = tmp*f;
					}
					else if(c1==c2+1){
						c2++;
						x[c2].n=tmp;
					}
				//	printf("tmp:%d f=%d\n",tmp,f);
					tmp=0; f=1;continue;
				}
				else if(i==2){
					if(c1==c2) {
						c1++;
						y[c1].a = tmp*f;
					}
					else if(c1==c2+1){
						c2++;
						y[c2].n=tmp;
					}
				//	printf("tmp:%d f=%d\n",tmp,f);
					tmp=0; f=1;continue;
				}
			}
			tmp*=10; tmp+=st[j]-'0';
			//printf("tmp=%d\n",tmp);
			if(j==l-1){
				c2++;
				if(i==1) x[c2].n=tmp;
				else if(i==2) y[c2].n=tmp;
			}
		}
		if(i==1) cnt1=c1;
		else cnt2=c1;
	}
	/*printf("c1=%d c2=%d\n",cnt1,cnt2);
	for(i=1; i<=cnt1; i++)
		printf("%d %d,",x[i].a,x[i].n);
	puts("");
	for(i=1; i<=cnt2; i++)
		printf("%d %d,",y[i].a,y[i].n);
	puts("");*/
}
int cmp(const void*a,const void*b){
	struct node1 m=*(struct node1*)(a);
	struct node1 p=*(struct node1*)(b);
	if(m.n==p.n) return m.a<p.n?1:-1;
	return m.n<p.n?1:-1; 
}

void deal(){
	int i,j;
	for(i=1; i<=cnt1; i++){
		for(j=1; j<=cnt2; j++){
			cnt++;
			ans[cnt].a=(long long)(x[i].a)*(long long)(y[j].a);
			ans[cnt].n=(long long)(x[i].n)+(long long)(y[j].n);
			//printf("i=%d,j=%d,%lld %lld\n",i,j,ans[cnt].a,ans[cnt].n);
		}
	}
	qsort(ans+1,cnt,sizeof(ans[1]),cmp);
//	for(i=1; i<=cnt; i++)
//		printf("%lld %lld,",ans[i].a,ans[i].n);
	for(i=1; i<=cnt; i++){
		if(i>=2&&ans[i].n==ans[i-1].n) continue;
		long long ans_a=ans[i].a,ans_n=ans[i].n;
		for(j=i+1; j<=cnt; j++){ //判断有没有可以合并； 
			if(ans[j].n!=ans_n) break;
			ans_a+=ans[j].a;
		}
		if(ans_a!=0) //判断系数是否为零； 
			printf("%lld %lld ",ans_a,ans_n);
	}		
}

int main(){
	read();
	deal();
	return 0;
}


