#include<stdio.h>
#include<string.h>

int main(){
	char s[105];
	gets(s);
	int i,j,k,zhishu,n=strlen(s);
	if(s[0]=='0'){
		for(i=0;s[i]!='.';i++);
		for(k=1;s[i+k]=='0';k++);
		zhishu=k;
		printf("%d",s[i+k]-'0');
		if(i+k+1<n) printf(".");
		for(j=i+k+1;j<n;j++) printf("%d",s[j]-'0');
		printf("e-%d",zhishu);
	}
	else{
		for(i=0;s[i]!='.'&&i<n;i++);
		zhishu=i-1;
		printf("%d",s[0]-'0');
		if(n>=2) printf(".");
		for(i=1;i<n;i++)
			if(s[i]!='.') printf("%d",s[i]-'0');
		printf("e%d",zhishu);
	}
	
	return 0;
} 

