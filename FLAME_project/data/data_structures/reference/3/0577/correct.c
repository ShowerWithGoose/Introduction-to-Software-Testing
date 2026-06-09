#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char a[105];
	int i,j;
	gets(a);
	if(a[0]=='0'){
		for(i=2;i<=strlen(a);i++){
			if(a[i]!='0')
			break;
		}
		if(a[i+1]!='\0'){
			printf("%c.",a[i]);
		}
		else
		printf("%c",a[i]);
		j=i-1;
		i++;
		while(i<strlen(a)){
			printf("%c",a[i]);
			i++;
		}
		printf("e-%d",j);
	}
	else{
		for(i=0;i<=strlen(a);i++){
			if(a[i]=='.')
			break;
		}
		j=i-1;
		printf("%c.",a[0]);
		for(i=1;i<=j;i++){
			printf("%c",a[i]);
		}
		for(i=j+2;i<strlen(a);i++){
			printf("%c",a[i]);
		}
		printf("e%d",j);
	}
 	return 0;
}


