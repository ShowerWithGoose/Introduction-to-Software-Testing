#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
char input[1005];
int pos[105];
int main()
{
	int i,j,count=0,flag=0,dis;
	scanf("%s",input);
	for(i=0;input[i]!='\0';i++){
		if(input[i]=='-'){
			count++;
			pos[count]=i;
		}
	}
	for(i=1;i<=count;i++){
		for(j=flag;j<pos[i]-1;j++){
			printf("%c",input[j]);
		}
		if(input[pos[i]+1]-input[pos[i]-1]>0){
			dis=input[pos[i]+1]-input[pos[i]-1];
			if((isdigit(input[pos[i]-1])&&isdigit(input[pos[i]+1]))||(islower(input[pos[i]-1])&&islower(input[pos[i]+1]))||(isupper(input[pos[i]-1])&&isupper(input[pos[i]+1]))){
				for(j=0;j<dis;j++){
					printf("%c",input[pos[i]-1]+j);
				}
			}
			else{
				printf("%c-",input[pos[i]-1]);
			}
		}
		else{
			printf("%c-",input[pos[i]-1]);
		}
		flag=pos[i]+2;
		if(input[flag]!='-') printf("%c",input[flag-1]);
	}
	if(input[flag]!='\0'){
		for(i=flag;input[i]!='\0';i++){
			printf("%c",input[i]);
		}
	}
	return 0;
}

