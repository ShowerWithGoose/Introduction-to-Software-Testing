#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
char s[105];
int loc1,loc2;//loc1表示第一个有效数字出现的位置，loc2表示小数点的位置（在字符数组中） 

void my_puts(int len)
{
	int pow_num=loc2-loc1-1;
	if(loc1<loc2){
		printf("%c",s[loc1]);
		if(loc1!=len-1)printf(".");
		for(int i=loc1+1;i<len;i++){
			if(i==loc2)continue;
			else printf("%c",s[i]);
		}
	}
	else{
		pow_num++;
		printf("%c",s[loc1]);	
		if(loc1!=len-1)printf(".");
		for(int i=loc1+1;i<len;i++)printf("%c",s[i]);
	}
	printf("e%d",pow_num);
}
int main(){
	gets(s);
	int len=strlen(s);
	for(int i=len-1;i>=0;i--){
		if(s[i]=='.')loc2=i;
		else if(s[i]!='0')loc1=i; 
	}
	my_puts(len);
	return 0;
}


