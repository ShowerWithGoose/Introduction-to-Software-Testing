#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<time.h>
#define REP(i,a,b) for(register int i=a;i<=b;i++)
#define PER(i,a,b) for(register int i=a;i>=b;i--)
typedef long long LL;
char s[100001],ans[100001];
int l,top;
int chk(char a,char b){
	if(a<='9'&&a>='0'&&b<='9'&&b>='0')return 1;
	if(a<='z'&&a>='a'&&b<='z'&&b>='a')return 1;
	if(a<='Z'&&a>='A'&&b<='Z'&&b>='A')return 1;
	return 0;
}
int main(){
	scanf("%s",&s);
	l=strlen(s);
	REP(i,0,l-1){
		if(s[i]!='-'){ans[top++]=s[i];continue;}
		if(chk(ans[top-1],s[i+1])&&ans[top-1]<s[i+1]){
			REP(j,ans[top-1]+1,s[i+1])ans[top++]=j;
			i++;
		}
		else
		 ans[top++]=s[i];
	}
	printf("%s",ans);
}


