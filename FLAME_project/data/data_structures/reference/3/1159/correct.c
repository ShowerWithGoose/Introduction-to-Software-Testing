#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
char a[10000];
int t,flag,i,j,k;
int main()
{
	gets(a);
	for(i=0;i<strlen(a);i++){
		if(a[i]=='.'){
			flag=1;
			break;
		}
	}
	if(flag==0){
		printf("%c.",a[0]);
		for(i=1;i<strlen(a);i++)
			printf("%c",a[i]);
		printf("e0");
	}
	else{
		if(i==1&&a[0]!='0'){
			for(i=0;i<strlen(a);i++)
				printf("%c",a[i]);
			printf("e0");
		}
		else if(i==1&&a[0]=='0'){
		for(j=2;j<strlen(a);j++){
				if(a[j]!='0'&&j+1<strlen(a)){
				printf("%c.",a[j]);
				break;
				}
				if(a[j]!='0'&&j+1>=strlen(a)){
				printf("%c",a[j]);
				break;
				}
		}
			for(k=j+1;k<strlen(a);k++)
				printf("%c",a[k]);
			printf("e-%d",j-1);
		}		
			
		else {
		printf("%c.",a[0]);
		for(j=1;j<i;j++)
			printf("%c",a[j]);
		for(j=i+1;j<strlen(a);j++)
			printf("%c",a[j]);
		printf("e%d",i-1);	
		}
			
	}
	
	
return 0;
}




