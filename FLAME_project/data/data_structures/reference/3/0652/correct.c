#include <stdio.h>
#include <string.h>
int main ()
{
	char a[1024]="\0";
	gets(a);
	int i=0,k=0;
	for(i=0;i<strlen(a);i++){
		if(a[i]=='.')
			k=i;
	}
	if(a[0]-'0'>0){
		printf("%c.",a[0]);
		for(i=1;i<strlen(a);i++){
			if(a[i]!='.')
			 printf("%c",a[i]);
		}
		printf("e%d\n",k-1);
	}
	int j=0;
	if(a[0]=='0'){
		for(i=0;i<strlen(a);i++){
			if(a[i]!='0'&&a[i]!='.'){
			j=i;
			break;
			}
		}
		
		if(j==strlen(a)-1) 
		printf("%ce-%d\n",a[j],j-1);
		else {
			printf("%c.",a[j]);
			for(i=j+1;i<strlen(a);i++){
				if(a[i]!='.')
				printf("%c",a[i]);
	}
	printf("e-%d\n",j-1);
		}
	}
}

