#include<stdio.h>
#include<string.h>
typedef long long ll;

ll max(ll a,ll b){
   return a>b?a:b;
}
ll min(ll a,ll b){
   return a<b?a:b;
}
char a[1000000];

int main(){
	scanf ("%s",a+1);
	int n=strlen(a+1);
	for (int i=1;i<=n;i++){
		if (a[i]=='-'){
			if(i==1||i==n){
				printf("%c",a[i]);
				continue;
			}
			if ((a[i-1]>='a'&&a[i+1]>a[i-1]&&a[i+1]<='z')||(a[i-1]>='A'&&a[i+1]>a[i-1]&&a[i+1]<='Z')||(a[i-1]>='0'&&a[i+1]>a[i-1]&&a[i+1]<='9')){
				for (char j=a[i-1]+1;j<a[i+1];j++){
					printf("%c",j);
				}
				continue;
			}else {
				printf("%c",a[i]);
			}
		}else{
			printf("%c",a[i]);
		}
	}
	return 0;
}

