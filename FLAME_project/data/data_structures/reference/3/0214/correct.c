#include<stdio.h>
#include<string.h>
char s[1010],a[1010];
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
				a[j++]=s[i];
				a[j++]='.';
				mark=1;
				count=i;
				continue;
			}
			if(mark==1){
				a[j++]=s[i];	
			}
		}
		a[j]='\0';
		if(s[strlen(s)-1]==a[0])printf("%c",a[0]);
		else 
		{
			for(i=0;a[i]!='\0';i++){
				printf("%c",a[i]);
			}
		}
		printf("e-%d",count-1);
		return 0;
	}
	else{
		a[j++]=s[0];
		a[j++]='.';
		for(i=1;s[i]!='\0';i++){
			if(s[i]=='.'){
				mark=1;
			}
			else {
				if(mark==0){
				count++;
				a[j++]=s[i];
			}
			else {
				a[j++]=s[i];
			}
			}	
		}
		a[j]='\0';
		for(i=0;a[i]!='\0';i++){
			printf("%c",a[i]);
		}
		printf("%c%d",'e',count);
	}
	return 0;
}

