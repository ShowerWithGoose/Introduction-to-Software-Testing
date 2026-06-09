#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main(){
	char s[10000];
	int i,j,k;
	gets(s);
	printf("%c",s[0]);
	j=strlen(s)-1;
	for(i=1;i<j;i++){
		if(s[i]!='-'){
			printf("%c",s[i]);
			continue;
		}
		if(s[i]=='-'){
			if(s[i-1]>='a'&&s[i+1]>s[i-1]&&s[i+1]<='z'){
				for(k=0;k<s[i+1]-s[i-1]-1;k++)
				printf("%c",s[i-1]+k+1);
			}
			else if(s[i-1]>='A'&&s[i+1]>s[i-1]&&s[i+1]<='Z'){
				for(k=0;k<s[i+1]-s[i-1]-1;k++)
				printf("%c",s[i-1]+k+1);
			}
			else if(s[i-1]>='0'&&s[i+1]>s[i-1]&&s[i+1]<='9'){
				for(k=0;k<s[i+1]-s[i-1]-1;k++)
				printf("%c",s[i-1]+k+1);
			}
			else
			printf("-");
		}
		
	}
    printf("%c",s[j]);
    return 0;

}




