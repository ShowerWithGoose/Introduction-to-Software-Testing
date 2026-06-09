#include<stdio.h>
#include<string.h>
char s[5000000];
int main(){
	gets(s+1),s[0]='+';
	int n=strlen(s+1),m=0;
	for(int i=0;i<=n;i++)if(s[i]!=' ')s[m++]=s[i];
	int ans=0,res=0,x=0,flag=0;
	char ch=' ';
	for(int i=0;i<m;){
		ch=s[i],i++,x=0;
		if(ch=='='){
			ans+=flag*res;
			break;
		}
		while(s[i]>='0'&&s[i]<='9')x=x*10+s[i]-'0',i++;
		if(ch=='*')res*=x;
		if(ch=='/')res/=x;
		if(ch=='+')ans+=flag*res,res=x,flag=1;
		if(ch=='-')ans+=flag*res,res=x,flag=-1;
	}printf("%d",ans);
}



