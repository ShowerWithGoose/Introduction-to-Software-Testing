#include <stdio.h>
#include <string.h>

char ch[100001];
int len[128],next[100001];
long long x[100001];

int main(){
	int n=0,j,i;
	while(n==0||ch[n-1]^'=')
		next[n]=n+1,scanf(n?" %lld %c":"%lld %c",&x[n],&ch[n]),++len[ch[n++]];
	next[n]=0;
	while(len['+']|len['-']|len['*']|len['/']){
		if(len['*']|len['/']){
			for(i=0;i<n;i=next[i])
				if(ch[i]=='*'||ch[i]=='/')break;
			j=next[i];
			if(ch[i]=='*')
				x[i]*=x[j],ch[i]=ch[j],next[i]=next[j],--len['*'];
			else x[i]/=x[j],ch[i]=ch[j],next[i]=next[j],--len['/'];
		}
		else{
			for(i=0;i<n;i=next[i])
				if(ch[i]=='+'||ch[i]=='-')break;
			j=next[i];
			if(ch[i]=='+')
				x[i]+=x[j],ch[i]=ch[j],next[i]=next[j],--len['+'];
			else x[i]-=x[j],ch[i]=ch[j],next[i]=next[j],--len['-'];
		}
	}
	printf("%lld",x[0]);
	return 0;
}
