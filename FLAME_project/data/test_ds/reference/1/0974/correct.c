#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<math.h>
//int·¶Î§£º2147483647 (-2^31--2^31-1)
//scanf("%%",&,&);
//printf("%",);
//for(int i=0;i<n;i++){}
//if(){}

int main(){
	char str[10007];
	gets(str);
	int l=strlen(str),flag[10007]={0};
	for(int i=0;i<l;i++){
		if(str[i]=='-') flag[i]=1;
	}
	for(int i=0;i<l;i++){
		if((flag[i]==0)||(flag[i]==1&&str[i-1]==str[i+1])) printf("%c",str[i]);
	
		else{
			if((str[i-1]<='z'&&str[i-1]>='a'&&str[i+1]<='z'&&str[i+1]>='a')||(str[i-1]<='Z'&&str[i-1]>='A'&&str[i+1]<='Z'&&str[i+1]>='A')||(str[i-1]<='9'&&str[i-1]>='0'&&str[i+1]<='9'&&str[i+1]>='0')){
				int num=str[i+1]-str[i-1];
				for(int j=1;j<num;j++){
					printf("%c",str[i-1]+j);}
			}
			else printf("-");
		}
		}	
	return 0;	
	}

