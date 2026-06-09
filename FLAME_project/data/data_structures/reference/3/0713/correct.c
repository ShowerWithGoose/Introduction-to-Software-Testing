#include <stdio.h>
int main(){
	char s[101]="",frational[101]="",first;
	int point=0,first_num=0,flag=0,number=0;
	int i=0,j=0;
	gets(s);
	if(s[0]=='0') flag=0;
	else flag=1;
	for(i=0;s[i]!='\0';i++){
			if(s[i]=='.'){
				point=i;
			}	
		}
	for(i=0;s[i]!='\0';i++){
		if(s[i]!='0' && s[i]!='.'){
			first_num=i;
			first=s[i];
			break;
		}	
	}	
	//printf("%d\n",first_num);
	for(i=first_num+1,j=0;s[i]!='\0';i++){
		if(s[i]!='.')
		  frational[j++]=s[i];
	}//记录小数部分的字符串
	frational[j]='\0';
	
	if(flag==0) number=first_num-point;
	else number=point-first_num-1;
	//printf("%d,%d\n",first_num,point);
	
	
	printf("%c",first);
	if(s[first_num+1]!='\0'){
		printf(".");
	}
	printf("%s",frational);
	printf("e");
	if(flag==0) printf("-");
	printf("%d",number);
	return 0;
}

