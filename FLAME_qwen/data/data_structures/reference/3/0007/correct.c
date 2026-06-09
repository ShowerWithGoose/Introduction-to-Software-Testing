#include<stdio.h> 
#include<math.h>
#include<stdlib.h> 
#include<string.h> 
#include<stdbool.h> 
void judge(char s[]);
void out(int,int);
char s[150],ans[151];
int main(){ 
gets(s);
judge(s);
return 0;
}

void judge(char s[]){
int point=-1,real[111];
int i,j=0;
bool flag=0;
int len=strlen(s);
for(i=0;i<len;i++){
if(s[i]=='.'){
	point=i;
}else if(s[i]=='0'){
	flag=0;
}else if(flag==0&&s[i]!='0'&&s[i]!='.'){
	real[j]=i;
	j++;
}
}

out(point,real[0]);

}
void out(int pd,int nd){
int digit;
int i;
int j;
int len=strlen(s);
for(j=len-1;j>nd&&s[j]=='0';j--){
}
if(pd==-1){	
if(j==nd){
	printf("%ce%d",s[nd],strlen(s)-nd-1);
}else{	
printf("%c.",s[nd]);
	for(i=nd+1;i<=j;i++){
		printf("%c",s[i]);
	}
	printf("e%d",strlen(s)-nd-1);
	
}

	
}else{
digit=pd-nd;
printf("%c",s[nd]);	
	if(nd==len-1){
printf("e%d",digit);
	}else if(s[pd-1]=='0'){
			printf(".");
	for(i=nd+1;i<len;i++){
	if(s[i]=='.'){
		i++;
	}	
	printf("%c",s[i]);	
	} 
	printf("e%d",digit);
		
	}else{
	printf(".");
	for(i=nd+1;i<len;i++){
	if(s[i]=='.'){
		i++;
	}	
	printf("%c",s[i]);	
	} 
	printf("e%d",digit-1);
		
	}



}

}




