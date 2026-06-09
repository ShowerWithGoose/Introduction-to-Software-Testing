#include<stdio.h>

typedef long long ll;

ll max(ll a,ll b){
   return a>b?a:b;
}
ll min(ll a,ll b){
   return a<b?a:b;
}

char a[100010];
int main(){
	scanf ("%s",a+1);
	int n=strlen(a+1);
	int p,l,f=0;
	for (int i=1;i<=n;i++){
		if (a[i]=='.'){
			p=i;
			continue;
		}
		if (a[i]=='0') continue;
		if (!f) f=i;
		l=i;
	}
	int ans = p-f-1;
	for (int i=f;i<=l;i++){
		if (a[i]=='.') continue;
		
		printf("%c",a[i]);
		if (i==f&&f!=l) printf(".");
	}
	if (ans<0) ans ++;
	printf("e%d",ans);
	return 0;
}

