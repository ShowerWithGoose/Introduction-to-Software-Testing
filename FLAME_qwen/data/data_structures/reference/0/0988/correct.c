//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define eps 1e-6

int main(){
	char s[1005],a,b;
	gets(s);
	int i,l=strlen(s);
	for(i=0;i<l;i++){
		if(s[i]=='-'){
			a=s[i-1]; b=s[i+1];
			if(a<b&&('0'<=a&&a<='9'&&'0'<=b&&b<='9')||('a'<=a&&a<='z'&&'a'<=b&&b<='z')||('A'<=a&&a<='Z'&&'A'<=b&&b<='Z')){
				int j;
				for(j=1;j<=b-a;j++) printf("%c",a+j);
				i++;
			}else printf("%c",s[i]);
			
		}else printf("%c",s[i]);
	}

	return 0;
}



