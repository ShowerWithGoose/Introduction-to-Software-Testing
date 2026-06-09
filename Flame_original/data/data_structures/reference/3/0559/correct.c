#define eps 1e-11
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<ctype.h>
char str[110];
//87899.9999999999000999  8.78999999999999000999e4
int main()
{
	gets(str);
	int len=strlen(str);
	int cnt=0;
	int mark=1;
	int pot=0;
	for(int i=0;i<len;i++)
	{
		if(str[0]=='0'){
			mark=-1;
			break;
		}
		if(str[i]=='.'){
			pot=1;
			break;
		}
		if(str[i]!='.'&&pot==0){
			cnt++;
		}
	}
	if(mark>0){
		//800000.0  8e5
		//800050060.0  8.005e5
		//87899.9999999999000999  8.78999999999999000999e4
		int sign=0;
		for(int k=0;k<len;k++){
			if(str[k]!='0'&&str[k]!='.') sign=0;
			if(str[k]=='0'||str[k]=='.') sign-=1;
		}
		if(len+sign==1){//8 -
			printf("%c",str[0]);
		}
		else{
			printf("%c.",str[0]);
			for(int i=1;i<len+sign;i++){
				if(str[i]!='.'){
					printf("%c",str[i]);
				}
			}
		}
		printf("e%d\n",cnt-1);
	}
	else{//0.000203
		int j =2;
		//cnt=0
		while(str[j]=='0'){
			j++;
			cnt++;
		}
		if((j+2)<len){
			//7 8
			printf("%c.",str[j]);
			for(j++;j<len;j++){
				printf("%c",str[j]);
			}
		}
		else printf("%c",str[j]);
		printf("e-%d\n",cnt+1);
	}
	return 0;
}

