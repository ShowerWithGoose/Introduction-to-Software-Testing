#include<stdio.h>
#include<string.h>
int main(){
	char s[1000]={'\0'};
	int i,j=0,x=0,num=1; 
	gets(s);
	int len=strlen(s);
	for(i=0;i<len;i++)
	   if(s[i]=='.') {x=i;break;}//小数点的位置 
	
	if(s[0]=='0') {
	for(i=x+1;s[i]!='\0';i++){
		if(s[i]=='0') num++;
		else break;
	   }
	if(i==len-1)
	printf("%ce-%d",s[i],num);
	else {	
	printf("%c.",s[i]);
	for(j=i+1;j<len;j++)
		printf("%c",s[j]);
	printf("e-%d",num);
	}
    return 0;
	}
	else{
		printf("%c.",s[0]);
		for(j=1;s[j]!='\0';j++){
		if(j==x) continue;
		printf("%c",s[j]);}
		
			
		printf("e%d",i-1);
	return 0;
	}	
	
} 

