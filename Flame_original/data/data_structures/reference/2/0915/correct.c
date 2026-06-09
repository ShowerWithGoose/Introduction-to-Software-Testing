#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<limits.h>
#define min(a,b) ((a<=b)?a:b)
#define max(a,b) ((a>=b)?a:b)
int main() {
	char c;
	int a=0,b=0,ans=0;
	int opt=1;
	int judge=0;
	scanf("%c",&c);
	while(c!='=') {
		if(c==32) {
			scanf("%c",&c);
			continue;
		}
		if(isdigit(c)) {
			a*=10;
			a+=c-'0';
		}
		if(c=='+'||c=='-') {
			ans+=opt*a;
			a=0;
			opt=(c=='+'?1:-1);
		}
		if(c=='*'||c=='/') {
			judge=(c=='*'?1:-1);
			scanf("%c",&c);
			while(c!='+'&&c!='-'&&c!='*'&&c!='/'&&c!='=') {
				if(c==32) {
					scanf("%c",&c);
					continue;
				}
				if(isdigit(c)) {
					b*=10;
					b+=c-'0';
				}
				scanf("%c",&c);
			}
			if(judge==1) {
				a*=b,b=0;
			}
			if(judge==-1) {
				a/=b,b=0;
			}
			if(c=='*') judge=1;
			else if(c=='/') judge=-1;
			else judge=0;
			continue;
		}
		scanf("%c",&c);
	}
	ans+=opt*a;
	printf("%d",ans);
	system("pause");
	return 0;
}



