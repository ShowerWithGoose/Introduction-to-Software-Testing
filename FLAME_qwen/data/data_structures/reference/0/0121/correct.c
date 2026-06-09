#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
char *upper="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char *lower="abcdefghijklmnopqrstuvwxyz";
char *number="0123456789";
int main(){
	char str[1002];
	scanf("%s",str);
	for(int i=0;i<strlen(str);i++){
		if(str[i]>='A'&&str[i]<='Z'){
			printf("%c",str[i]);
			//TODO
		}
		if(str[i]>='a'&&str[i]<='z'){
			printf("%c",str[i]);
					//TODO
				}
		if(str[i]>='0'&&str[i]<='9'){
			printf("%c",str[i]);
					//TODO
				}
		if(str[i]=='-'){
			if(isupper(str[i-1])&&isupper(str[i+1])&&str[i-1]<str[i+1]){
				int flag=0;
				char *x;
				for(x=upper;x<=upper+25;x++){
					if(*x==str[i+1]){
						break;
						//TODO
					}
					if(*x==str[i-1]){
						flag=1;
						continue;
						//TODO
					}
					if(flag==1)  printf("%c",*x);
					//TODO
				}
				//TODO
			}
			else if(islower(str[i-1])&&islower(str[i+1])&&str[i-1]<str[i+1]){
				int flag=0;
				char *x;
				for(x=lower;x<=lower+25;x++){
					if(*x==str[i+1]){
						break;
						//TODO
						}
					if(*x==str[i-1]){
						flag=1;
						continue;
						//TODO
						}
					if(flag==1)  printf("%c",*x);
					//TODO
				}
				//TODO
			}
			else if(str[i-1]>='0'&&str[i+1]<='9'&&str[i-1]<str[i+1]){
				int flag =0;
				char *x;
				for(x=number;x<=number+25;x++){
					
					if(*x==str[i+1]){
						break;
						//TODO
						}
					if(*x==str[i-1]){
						flag=1;
						continue;
						//TODO
						}
					if(flag==1) printf("%c",*x);
					//TODO
				}
				//TODO
			}
			else printf("-");
		}
		//TODO
	}
	return 0;
}

