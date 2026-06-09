#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
const double eps=0.000001;
char fro[205];
char num[205];
char aft[205];
int main()
{
	int count=0,i,len1,len2,flag=0;
	gets(num);
	for(i=0;num[i]!='.';i++){
		fro[i]=num[i];
		flag++;
	}
	for(i=flag+1;num[i]>='0'&&num[i]<='9';i++){
		aft[i-flag-1]=num[i];
	}
	len1=strlen(fro);
	len2=strlen(aft);
//	printf("%d %d\n",len1,len2);
	if(strcmp(fro,"0")==0){
		for(i=0;aft[i]=='0';i++){
			count++;
		}
		printf("%c",aft[count]);
		if((count+1)!=len2){
			printf(".");
		}
		for(i=count+1;i<len2;i++){
			printf("%c",aft[i]);
		}
		printf("e-%d",count+1);
	}
	else{
		if(len1==1){
			printf("%s.%se0",fro,aft);
		}
		else{
			printf("%c.",fro[0]);
			for(i=1;fro[i]!='\0';i++){
				printf("%C",fro[i]);
			}
			printf("%se%d",aft,len1-1);
		}
	}
	return 0;
}

