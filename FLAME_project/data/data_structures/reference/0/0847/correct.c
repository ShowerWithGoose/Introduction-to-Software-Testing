#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
char s[205];
int main()
{
	int i,l;
	char c;
	scanf("%s",s);
	l=strlen(s);
	for(i=0;i<l;i++){
		if(s[i]!='-') printf("%c",s[i]);
		else{
			if((s[i-1]<=s[i+1]) && (((s[i-1]>='a') && (s[i+1]<='z')) || ((s[i-1]>='A') && (s[i+1]<='Z')) || ((s[i-1]>='0') && (s[i+1]<='9')))){
				for(c=s[i-1]+1;c<s[i+1];c++) printf("%c",c);
			}
			else printf("%c",s[i]);
		}
	}
	return 0;
}

