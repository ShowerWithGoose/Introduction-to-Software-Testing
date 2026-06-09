#include<stdio.h>
#include<string.h>
int main()
{
	char n[105];
	int i,j;
	gets(n);
	if(n[1]=='\0')
		printf("%ce0",n[0]);
	else if(n[0]=='0'){
		for(i=2;n[i]=='0';i++)
			continue;
		printf("%c",n[i]);
		if(strlen(n)>i+1)
			printf(".%s",n+i+1);
		printf("e-%d",i-1);
	}
	else if(n[0]!='0'){
		for(i=0;n[i]!='\0'&&n[i]!='.';i++)
			continue;
		if(n[i]=='\0'){
			j=i;
			while(n[j-1]=='0'){
				j--;
			}
			n[j]='\0';
			printf("%c.%se%d",n[0],n+1,i-1);
		}	
		else if(n[i]=='.'){
			n[i]='\0';
			printf("%c.%s%se%d",n[0],n+1,n+i+1,i-1);
		}
	}
	return 0;
}

