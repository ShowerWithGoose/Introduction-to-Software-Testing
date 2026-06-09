#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000];
	int i,j,dis;
	gets(s);
	printf("%c",s[0]);
	for(i=1;s[i]!='\0';i++){
		if(s[i]!='-')
		printf("%c",s[i]);
		else{
			if((s[i-1]>='a'&&s[i+1]<='z'&&s[i-1]<s[i+1])||(s[i-1]>='A'&&s[i+1]<='Z'&&s[i-1]<s[i+1])||(s[i-1]>='0'&&s[i+1]<='9'&&s[i-1]<s[i+1])){
				dis=s[i+1]-s[i-1];
				for(j=1;j<dis;j++){
					printf("%c",s[i-1]+j);
				}
			}
			else
			printf("-");
		}
	}
	
	return 0;
}

