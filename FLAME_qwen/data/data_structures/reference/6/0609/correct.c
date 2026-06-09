#include<stdio.h>


typedef long long ll;
const int maxn = 105;
ll max(ll a,ll b){
   return a>b?a:b;
}
ll min(ll a,ll b){
   return a<b?a:b;
}
int pos=0;
int a[105];
int main(){
	int tmp;
	scanf ("%d",&tmp);
	while (tmp!=-1){
		int tp;
		
		if (tmp==1){
			scanf ("%d",&tp);
			if (pos == 100){
				printf("error ");
			}else{
				a[++pos]=tp;
			}
		}else{
			if (pos==0) printf("error ");
			else printf("%d ",a[pos--]);
		}
		
		scanf ("%d",&tmp);
	}
	return 0;
}

