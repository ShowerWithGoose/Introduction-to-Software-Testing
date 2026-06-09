#include<stdio.h>
#include<string.h>
int main()
{
	char s[1000],ex[2000];
	int i,j=0;
	scanf("%s",s);
	for(i=0;i<strlen(s);i++){
		if(s[i]!=45) ex[j++]=s[i];
		else if(s[i-1]>=48&&s[i+1]<=57&&s[i-1]<s[i+1]){
			while(ex[j-1]!=s[i+1]-1){
				ex[j]=ex[j-1]+1;
				j++;
			}
		}
		else if(s[i-1]>=65&&s[i+1]<=90&&s[i-1]<s[i+1]){
			while(ex[j-1]!=s[i+1]-1){
				ex[j]=ex[j-1]+1;
				j++;
			}
		}
		else if(s[i-1]>=97&&s[i+1]<=122&&s[i-1]<s[i+1]){
			while(ex[j-1]!=s[i+1]-1){
				ex[j]=ex[j-1]+1;
				j++;
			}
		}
		else ex[j++]=45;
	}
	ex[j]='\0';
	printf("%s",ex);
	return 0;
}



