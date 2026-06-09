#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define REP(i,a,b) for(register int i=a;i<=b;i++)
#define PER(i,a,b) for(register int i=a;i>=b;i--)
typedef long long LL;
char s[100001],s1[100001];
int l,top,flg;
LL ans;
void solve(int st,int ed,char opt){
//	printf("%lld\n",ans);
	LL res=1,rem=1;LL tmp=0;//1 for *and 0 for /
	int flagopt=0;
	REP(i,st,ed)
		if(s[i]=='*'||s[i]=='/')
			flagopt=1;
	if(!flagopt){
		REP(i,st,ed){
			tmp=tmp*10+s[i]-'0';
		}
		if(opt=='+')ans+=tmp;
		else ans-=tmp;
		return ;
	}
	REP(i,st,ed){
		if(s[i]!='*'&&s[i]!='/')
			tmp=tmp*10+s[i]-'0';
		else{
			if(rem==1)
				res*=tmp;
			else
				res/=tmp;
			if(s[i]=='*')
				rem=1;
			else
				rem=0;
			tmp=0;
		}
	}
	if(rem==1)
		res*=tmp;
	else
		res/=tmp;
	if(opt=='+')ans+=res;
	else ans-=res;
}
void dfs(int pos){
	if(pos>=top)return ;
	if(s[pos]=='+'||s[pos]=='-'){
		REP(i,pos+1,top)
			if(s[i]=='+'||s[i]=='-'){
				solve(pos+1,i-1,s[pos]);
				dfs(i);
				break;
			}	
	}
}
int main(){
	gets(s1);
	l=strlen(s1);
	REP(i,0,l-1){
		if(s1[i]!=' '){
			if(s1[i]=='-')
				flg=1;
			break;
		}
	}
	if(!flg){
	REP(i,0,l-1)
		if(s1[i]!=' ')
			s[++top]=s1[i];
	s[0]='+';
	}
	else{
	REP(i,0,l-1)
		if(s1[i]!=' ')
			s[top++]=s1[i];
	top--;
	}
	s[top]='+';
//	printf("%s",s);
	dfs(0);
	printf("%lld",ans);
}


