#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
	char s[100]={'\0'};
	char z[100]={'\0'};
	char x[100]={'\0'};
	int xf=0;
	int zf=-1;
	int flag=0;
	int i=0;
	scanf("%s",s);
	if(s[i]=='0'){
		xf++;
		i=i+2;
		while(s[i]=='0'){
			i++;
			xf++;
		}
		if(s[i+1]!='\0')
			flag=1; 
		printf("%c",s[i]);
		if(flag==1)
			printf(".");
		printf("%se-%d",&s[i+1],xf);
	}
	else{
		while(s[i]!='.'){
			zf++;
			i++;
		}
		i=1;
		printf("%c.",s[0]);
		while(s[i]!='.'){
			printf("%c",s[i]);
			i++;
		}
		printf("%se%d",&s[i+1],zf);
	}
	return 0;
}

