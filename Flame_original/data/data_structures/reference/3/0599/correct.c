#include <stdio.h>
#include <string.h>

int main()
{
	char a[110];
	char *str;
	str=a;
	gets(a);
	int i=0;
	int cnt=1;
	if(a[0]!='0'){
		for(i=0;a[i]!='.';i++){
			cnt++;
		}
		printf("%c.",a[0]);
		for(i=1;i<cnt-1;i++){
			printf("%c",a[i]);
		}
		for(i=cnt;i<strlen(a);i++){
			printf("%c",a[i]);
		}
		printf("e%d",cnt-2);
	}
	else if(a[0]=='0'){
		for(i=2;a[i]=='0';i++){}
		if(strlen(a)-i>=2){	
			cnt=1;
			for(i=2;a[i]=='0';i++){
				cnt++;
			}
			for(i=2;a[i]=='0';i++){
			}
			printf("%c.",a[i]);
			for(i=i+1;i<strlen(a);i++){
				printf("%c",a[i]);
			}
			printf("e-%d",cnt);
		}
		else{
			cnt=1;
			for(i=strlen(a)-1;a[i]!='.';i--){
				cnt++;
			}
			printf("%c",a[strlen(a)-1]);
			printf("e-%d",cnt-1);
		}
	}
	return 0;
} 

