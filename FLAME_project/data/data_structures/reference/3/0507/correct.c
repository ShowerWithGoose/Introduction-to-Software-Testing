#include<stdio.h>
#include<math.h>
#include<string.h>

int max(int a,int b);
char str[1000];
int i,j,res,len,point,begin,final,res;

int main(){
	gets(str);
	len=strlen(str);
	for(i=0;i<len;i++){
		 if(str[i]=='.'){
		 	point=i;
		 	break;
		 }
	}
	for(i=0;i<len;i++){
		 if(str[i]!='.'&&str[i]!='0'){
		 	begin=i;
		 	break;
		 }
	}
	for(i=0;i<len;i++){
		 if(str[i]!='0'){
		 	final=i;
		 }
	}
	res=(begin<point?point-begin-1:point-begin);
	printf("%c",str[begin]);
	if(begin!=final){
		printf(".");
		for(i=begin+1;i<point;i++) printf("%c",str[i]);
		for(i=max(point+1,begin+1);i<=final;i++) printf("%c",str[i]);
		printf("e%d",res);
	}
	else printf("e%d",res); 
	return 0;
}

int max(int a,int b){
	return(a>b?a:b);
}

