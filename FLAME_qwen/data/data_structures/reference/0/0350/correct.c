#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int main() {
	int i,j,k,x,y,z,n,m;
	char s[1000000];
	gets(s);
	for(i=0; i<strlen(s); i++) {
//		if((s>=48&&s<=57)||(s>=65&&s<=90)||(s>=97&&s<=122))
		if(s[i]!='-')
			printf("%c",s[i]);
		else {
			if((s[i-1]>=48&&s[i-1]<=57)&&(s[i+1]>=48&&s[i+1]<=57))
				for(j=s[i-1]+1; j<=s[i+1]-1; j++) {
					printf("%c",j);
				}
			else if((s[i-1]>=65&&s[i-1]<=90)&&(s[i+1]>=65&&s[i+1]<=90))
				for(j=s[i-1]+1; j<=s[i+1]-1; j++) {
					printf("%c",j);
				}
			else if((s[i-1]>=97&&s[i-1]<=122)&&(s[i+1]>=97&&s[i+1]<=122))
				for(j=s[i-1]+1; j<=s[i+1]-1; j++) {
					printf("%c",j);
				}
			else printf("-");
		}
	}







	return 0;
}




