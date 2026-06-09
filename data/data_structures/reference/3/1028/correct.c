#include <stdio.h>
#include <string.h>
#include <math.h>
#include<stdlib.h>
#define ll long long
int shuliangji(char*,int,int);
int main ()
{
    char s[1000];
    gets(s);
    int l=strlen(s);
    int xiaoshudian=0;
    int j=0;
    int flag1=0;
    int i;
    
	for(i=0;i<=l;i++){
		if(s[i]=='.'){
			xiaoshudian=i;
		}
	}
	if(xiaoshudian==0){
		xiaoshudian=l;
	}
 
		 while(s[l-1]=='0'){
		l--;
	}//去掉多余的0 
	while(s[j]=='0' || s[j]=='.'){
		j++;
		if(j>=l){
			flag1++;
			break;
		}		
	}
    
    if(flag1){
		printf("0e");
	}
	else{//j标记的是第一个有效数字 
		if((l-xiaoshudian==1 && xiaoshudian-j==1)|| l-j==1){
			printf("%ce",s[j]);
		}
		else{
			printf("%c.",s[j]);
			for(int i=j+1;i<l;i++){
				if(s[i]!='.'){
					printf("%c",s[i]);
				}
			}
			printf("e");
		}
	}
	
	printf("%d",shuliangji(s,xiaoshudian,l));
    return 0;
}
int shuliangji(char*s,int dian,int l){
	int j=0;
	int shu=0;
    int flag=0;
	while(s[j]=='0' || s[j]=='.'){
		j++;
		if(j>l){
			flag++;
			break;
		}
	}
    
    if(flag){
		return shu;
	}
	else{
		if(j<dian) return dian-j-1;
		else  return dian-j;
	}
}

