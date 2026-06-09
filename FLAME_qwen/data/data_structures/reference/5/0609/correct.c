#include<stdio.h>
#include<stdlib.h>

typedef long long ll;

ll max(ll a,ll b){
   return a>b?a:b;
}
ll min(ll a,ll b){
   return a<b?a:b;
}
struct node{
	ll ans,xi;
}e[1010];
int n;
int cmp (const void *a,const void *b){
	return (*(struct node *)a).xi<(*(struct node*)b).xi;
}
int main(){
	int st1=1,n=1,st2=0;
	while (scanf ("%lld%lld",&e[n].ans,&e[n].xi)!=EOF){
		if (n>1&&e[n].xi>=e[n-1].xi){
			st2=n;
		}
		n++;
	}
	n--;
	int len1=st2-1,len2=n;
	for (int i=1;i<=len1;i++){
		for (int j=st2;j<=len2;j++){
			ll a=e[i].ans*e[j].ans,x=e[i].xi+e[j].xi;
			e[++n].ans=a;
			e[n].xi=x;
		}
	}
	qsort(e+len2+1,n-len2,sizeof(e[1]),cmp);
	int p=len2;
	for (int i=len2+1;i<=n;i++){
		
		if (i<n&&e[i].xi==e[i+1].xi){
			e[i+1].ans +=e[i].ans;
		}else{
			e[++p].xi=e[i].xi;
			e[p].ans=e[i].ans;
		}
	}
	for (int i=len2+1;i<=p;i++){
		printf("%d %d ",e[i].ans,e[i].xi);
	}
	return 0;
}

