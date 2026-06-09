#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int main(){

char num[300];
gets(num);
int i,j,di=0,u=0,c;
if(num[0]==48){
	di=1;
for(i=2;num[i]=='0';i++){
	di++;
}
printf("%c",num[i]);
if(num[i+1]!='\0'){

printf(".");
}
	for(j=i+1;num[j]!='\0';j++){
		printf("%c",num[j]);
	}
	printf("e");
	printf("-");
	printf("%d",di);
	
	
}
else if(num[0]>48&&num[0]<=57){
	for(i=0;i<strlen(num);i++){
		u++;
		if(num[i]=='.'||num[i]=='\0'){
			break;
		}
		
	}
	printf("%c",num[0]);
	for(i=1;num[i]!='0';i++){
		c++;
	}
	if(c!=strlen(num)-1){
		printf(".");
	}
	for(i=1;num[i]!='\0';i++){
		if(num[i]!='.'){
		
		printf("%c",num[i]);
		}
	}
    if(u-2!=1&&u-2!=0){
    	printf("e%d",u-2);
	}
	if(u-2==1){
		printf("e");
	}
	if(u-2==0){
		printf("e0");
	}
}

}


