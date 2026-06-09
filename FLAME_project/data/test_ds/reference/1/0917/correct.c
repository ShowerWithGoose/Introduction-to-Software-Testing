#include<stdio.h>
#include<string.h>
int main(){
	int i,j; 
	char str[200];
	scanf("%s",str);
	for(i=0;i<strlen(str);i++){
		if(str[i]=='-'){
			if((str[i-1]>=48&&str[i-1]<=57)&&(str[i+1]>=48&&str[i+1]<=57)&&(str[i+1]-str[i-1]>0)){
				for(j=1;j<str[i+1]-str[i-1];j++){
					printf("%c",str[i-1]+j);
				}
				i++;
			}
			else if((str[i-1]>=65&&str[i-1]<=90)&&(str[i+1]>=65&&str[i+1]<=90)&&(str[i+1]-str[i-1]>0)){
				for(j=1;j<str[i+1]-str[i-1];j++){
					printf("%c",str[i-1]+j);
				}
				i++;
			}
			else if((str[i-1]>=97&&str[i-1]<=122)&&(str[i+1]>=97&&str[i+1]<=122)&&(str[i+1]-str[i-1]>0)){
				for(j=1;j<str[i+1]-str[i-1];j++){
					printf("%c",str[i-1]+j);
				}
				i++;
			}
		}
		printf("%c",str[i]);
	}
	return 0;
}

