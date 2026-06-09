#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
int main()
{
	char s[1000];
	long long flag2=0,x=0,i=0,cnt=0,a=0,flag=0;
	gets(s);
	for(int z=0;z<strlen(s);z++){
		if(s[z]=='.'){
		i=z;
		break;
		}
	}
			if(i==1&&s[0]!='0'){
			for(int j=0;j<i;j++){
				printf("%d",s[a]-'0');
				a++;
			}
			printf(".");
			for(int k=i+1;k<strlen(s);k++){
				printf("%d",s[k]-'0');
			}
			printf("e0");
		}
			if(i==1&&s[0]=='0'){
			for(int k=i+1;k<strlen(s);k++){
				if(s[k]-'0'==0&&flag==0){
					cnt++;
				}
				if(s[k]!='0'&&k!=strlen(s)-1&&flag==0){
					printf("%d.",s[k]-'0');
					flag=1;
					continue;
				} 
				if(s[k]!='0'&&k==strlen(s)-1&&flag==0){
					printf("%de-%d",s[k]-'0',cnt+1);
				}
				if(flag==1){
					printf("%d",s[k]-'0');
					if(k==strlen(s)-1){
						printf("e-%d",cnt+1);
					}
				}
			}
		}
		if(i>1){
			printf("%d.",s[0]-'0');
			for(int j=1;j<strlen(s);j++){
				if(j!=i){
				printf("%d",s[j]-'0');
				}
			}
			printf("e%d",i-1);
		}
	return 0;
}



