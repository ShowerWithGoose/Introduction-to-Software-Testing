#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define ll long long
#define N 100005 
char s[N];
int dfs(int l,int r){
	//printf("%d   %d\n",l,r);
	for(int i=r;i>=l;i--){
		if(s[i]=='+'){
			return dfs(l,i-1)+dfs(i+1,r);
		}
		if(s[i]=='-'){
			return dfs(l,i-1)-dfs(i+1,r);
		}
	}
	for(int i=r;i>=l;i--){
		if(s[i]=='*'){
			return dfs(l,i-1)*dfs(i+1,r);
		}
		if(s[i]=='/'){
			return dfs(l,i-1)/dfs(i+1,r); 
		}
	}
	int ans=0;
	for(int i=l;i<=r;i++){
		if(isdigit(s[i]))ans=ans*10+s[i]-'0';
	}
//	printf("%d\n",ans);
	return ans;
}
int main(){
	gets(s);
	printf("%d\n",dfs(0,strlen(s)-1));
	return 0;
} 

