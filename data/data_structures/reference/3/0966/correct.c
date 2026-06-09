//nation
#include<stdio.h>
#include<string.h>
 
int main()
{
	char ch[200];
	scanf("%s",ch);
	if(ch[0]=='0'){
		int i;
		for(i=0;strlen(ch)-i>0;i++){
			if(ch[i]>='1'&&ch[i]<='9'){
				break;
			}
		}
		char ch_1[200]={};
		ch_1[0]=ch[i];
		if(ch[i+1]!='\0'){
			ch_1[1]='.';
		}
		strcat(ch_1,ch+i+1);
		printf("%s",ch_1);
		printf("e%d",-i+1);
	}
	else if(ch[1]=='.'){
		printf("%s",ch);
		printf("e0");
	}else{
		int i;
		for(i=0;strlen(ch)-i>0&&ch[i]!='.';i++);
		int j=i;
		for(;strlen(ch)-i-1>0;i++){
			ch[i]=ch[i+1];
		}
		ch[i]='\0';
		char ch_1[200]={};
		ch_1[0]=ch[0];
		ch_1[1]='.';
		strcat(ch_1,ch+1);
		printf("%s",ch_1);
		printf("e%d",j-1);
	}
	return 0;
} 

