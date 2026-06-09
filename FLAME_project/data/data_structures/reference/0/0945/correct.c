#include<stdio.h>
#include<string.h>
#include<math.h>
char s[2100000];
int main(){
	
	gets(s);
	int i,j,flag;
	for(i=0;i<strlen(s);i++){
		flag=0;
		if(s[i]=='-'&&s[i+1]>s[i-1])
		{
			if(s[i+1]<='z'&&s[i+1]>='a'&&s[i-1]<='z'&&s[i-1]>='a'){
				flag=1;
				for(j=1;s[i-1]+j<s[i+1];j++)
				printf("%c",s[i-1]+j);
			}
			if(s[i+1]<='Z'&&s[i+1]>='A'&&s[i-1]<='Z'&&s[i-1]>='A'){
				flag=1;
				for(j=1;s[i-1]+j<s[i+1];j++)
				printf("%c",s[i-1]+j);
			}
			if(s[i+1]<='9'&&s[i+1]>='0'&&s[i-1]<='9'&&s[i-1]>='0'){
				flag=1;
				for(j=1;s[i-1]+j<s[i+1];j++)
				printf("%c",s[i-1]+j);
			}
		}
		if(flag==0)
		printf("%c",s[i]);
	}

	
	
	return 0;
} 

