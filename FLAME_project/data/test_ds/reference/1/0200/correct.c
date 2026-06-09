#include <stdio.h>
int main(){
	char s[100000];
	char b[100000];
	gets(s);
	int i,j,cnt,k;
	int x=0;
	int t=0;
	for(i=0;s[i]!='\0';i++){
		if(s[i]!='-')
		b[k++]=s[i];
		else if(s[i]=='-'&&s[i-1]<s[i+1]){
			if(('0'<=s[i-1]&&s[i-1]<='9'&&'0'<=s[i+1]&&s[i+1]<='9')||('a'<=s[i-1]&&s[i-1]<='z'&&'a'<=s[i+1]&&s[i+1]<='z')||('A'<=s[i-1]&&s[i-1]<='Z'&&'A'<=s[i+1]&&s[i+1]<='Z')){
			cnt=s[i+1]-s[i-1];
			for(j=1;j<cnt;j++){
				b[k++]=s[i-1]+j;
			}
			}
			else
				b[k++]=s[i];
		}
		else
			b[k++]=s[i];		
	}
	puts(b);
	return 0;
}



