#include<stdio.h>
#include<string.h>
char s[1010],s[1010];
int main()
{
	int i,j=0,k;
	int m,n;
	int count=0;
	int mark=0;
	gets(s);
	if(strlen(s)==1){
		printf("%ce0",s[0]);
		return 0;
	}
	if(s[0]=='0'){
		for(i=1;s[i]!='\0';i++){
			if(s[i]!='.'&&s[i]!='0'&&mark==0){
				s[j++]=s[i];
				s[j++]='.';
				mark=1;
				count=i;
				continue;
			}
			if(mark==1){
				s[j++]=s[i];	
			}
		}
		s[j]='\0';
		if(s[strlen(s)-1]==s[0])printf("%c",s[0]);
		else 
		{
			for(i=0;s[i]!='\0';i++){
				printf("%c",s[i]);
			}
		}
		printf("e-%d",count-1);
		return 0;
	}
	else{
		s[j++]=s[0];
		s[j++]='.';
		for(i=1;s[i]!='\0';i++){
			if(s[i]=='.'){
				mark=1;
			}
			else {
				if(mark==0){
				count++;
				s[j++]=s[i];
			}
			else {
				s[j++]=s[i];
			}
			}	
		}
		s[j]='\0';
		for(i=0;s[i]!='\0';i++){
			printf("%c",s[i]);
		}
		printf("%c%d",'e',count);
	}
	return 0;
}

