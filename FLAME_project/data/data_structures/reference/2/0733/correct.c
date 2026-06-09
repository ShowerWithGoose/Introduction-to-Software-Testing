#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
int main() {
	char s[1005];
	gets(s);
	int i,j=0,k=0,f=0,sum=0,res=0,ans=0;
	for(i=0;s[i]!='=';i++){
		if(isdigit(s[i])){
			if(f==0) res=res*10+s[i]-'0';
			else ans=ans*10+s[i]-'0';
		}
		else if(s[i]=='*'){
			if(f==1){
				res*=ans;
				ans=0;
			}
			if(f==2){
				res/=ans;
				ans=0;
			}
			f=1;
		}
		else if(s[i]=='/'){
			if(f==1){
				res*=ans;
				ans=0;
			}
			if(f==2){
				res/=ans;
				ans=0;
			}
			f=2;
		}
		else if(s[i]=='-'||s[i]=='+'){
			if(f==1){
				res*=ans;
				ans=0;
				f=0;
			}
			if(f==2){
				res/=ans;
				ans=0;
				f=0;
			}
			if(k==0||k==2){
				sum+=res;
				res=0;
			}
			if(k==1){
				sum-=res;
				res=0;
			}
		}
		if(s[i]=='-') k=1;
		if(s[i]=='+') k=2;
	}
	if(f==1) res*=ans;
	if(f==2) res/=ans;
	if(k==0||k==2){
		sum+=res;
	}
	if(k==1){
		sum-=res;
	}
	printf("%d",sum);
	return 0;
}




