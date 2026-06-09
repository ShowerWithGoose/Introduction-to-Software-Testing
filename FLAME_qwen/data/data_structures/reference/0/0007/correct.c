#include<stdio.h> 
#include<math.h>
#include<stdlib.h> 
#include<string.h> 
#include<stdbool.h> 
void expand(char s[]);
int dif;
char s[1666];
int main(){ 

gets(s);
expand(s);


return 0;
}
void expand(char s[]){
char a[]="0123456789",b[]="abcdefghijklmnopqrstuvwxyz",c[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int flag1,flag2;
int i,j,len=strlen(s);
for(i=0;i<len;i++){
	if(s[i+1]!='-'){
		printf("%c",s[i]);
	}else{
		if(strchr(a,s[i])!=NULL){
			flag1=1;
		}
		if(strchr(b,s[i])!=NULL){
			flag1=2;
		}
		if(strchr(c,s[i])!=NULL){
			flag1=3;
		}
		if(strchr(a,s[i+2])!=NULL){
			flag2=1;
		}
		if(strchr(b,s[i+2])!=NULL){
			flag2=2;
		}
		if(strchr(c,s[i+2])!=NULL){
			flag2=3;
		}
		
		if(flag1!=flag2){
			printf("%c",s[i]);
			continue;
		}else{
		dif=s[i+2]-s[i];
		for(j=dif;j>=1;j--){
			printf("%c",s[i+2]-j);
		}
		j=0;
		i++;	
		}
		
	}
}	
		
}





