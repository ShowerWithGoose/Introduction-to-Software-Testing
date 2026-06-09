#include <stdio.h>
#include <string.h>
int main()
{
	char a[100];
	gets(a);
	int i,j,k;
	for(i=0,j=strlen(a);i<j;i++)
	if(a[i]=='.'){
		k=i;
		break;
	}
	if(a[0]>'0'){
		for(i=0;i<j;i++){
		if(i==1) printf(".");
		if(i!=k)
		printf("%c",a[i]);
	}
	printf("e%d",k-1);
	}
	else{
		for(i=0;i<j;i++)
		if(a[i]!='0'&&a[i]!='.'){
			k=i;
			printf("%c",a[i]);
			if(i!=j-1)
			printf(".");
			break;
		} 
		for(++i;i<j;i++)
		printf("%c",a[i]);
		printf("e-%d",k-1);
	}
	return 0;
 } 

