#include <stdio.h>
#include <math.h>
#include <string.h> 
#include <ctype.h>

int main()
{
	char s[1000];
	scanf("%s",&s);
	
	char one,last;
	int point,length,mici;
	int i;
	
	length=strlen(s);
	
	for(i=0;i<length;i++){
		if(s[i]>=49&&s[i]<=57){
			one=s[i];
			break;
		}
	}
	printf("%c",one);	
	
	int j;	
	for(j=length-1;j>=0;j--){
		if(s[j]!='0'&&s[j]!='.'){
			last=s[j];
			break;
		}
	}
	
	point=strchr(s,'.')-s;
	
	if(i<point){
		mici=point-i-1;
	}else{
		mici=point-i;
	}
	int k;
	if(i-j==0){
		printf("e%d",mici);
	}else{
		printf(".");
		for(k=i+1;k<=j;k++){
			if(s[k]!='.'){
				printf("%c",s[k]);
			}
		}
		printf("e%d",mici);
	}
	return 0;
 }



