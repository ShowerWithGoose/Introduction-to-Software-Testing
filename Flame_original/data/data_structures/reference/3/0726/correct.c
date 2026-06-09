#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char s[150]; 
int main()
{
	int f,cnt=0,i=2;
	scanf("%s",s);
	f=strchr(s,'.')-s;
	if(f==1&&s[0]=='0'){
		cnt--;
		while(s[i]=='0'){
			cnt--;
			i++;
		}
		if(s[i+1]!='\0'){
			printf("%c.",s[i]);
			for(int k=i+1;s[k]!='\0';k++) printf("%c",s[k]);
		}
		else printf("%c",s[i]);
	}
	else if(f==1&&s[0]>'0') printf("%s",s);
	else{
		cnt=f-1;
		printf("%c.",s[0]);
		for(int k=1;k<f;k++) printf("%c",s[k]);
		for(int k=f+1;s[k]!='\0';k++) printf("%c",s[k]);
	}
	printf("e%d",cnt);
	return 0;
}


