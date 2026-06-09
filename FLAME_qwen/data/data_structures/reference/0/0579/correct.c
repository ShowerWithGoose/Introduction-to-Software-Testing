#include<stdio.h>
#include<ctype.h>
int main()
{
	char s[100];
	gets(s);
	printf("%c",s[0]);
	for(int i=1;s[i]!='\0';i++)
	{
		if(s[i]!='-'){
			printf("%c",s[i]); 
		}
		else{
			//扩展前后为数字 
			if(isdigit(s[i-1])&&isdigit(s[i+1])&&s[i-1]<s[i+1]){
				for(int j=s[i-1]+1;j<s[i+1];j++){
					printf("%c",j);
				} 
			}
			//扩展前后为小写字母 
			else if(islower(s[i-1])&&islower(s[i+1])&&s[i-1]<s[i+1]){
				for(char k=s[i-1]+1;k<s[i+1];k++){
					printf("%c",k);
				} 
			}
			//扩展前后为大写字母
			else if(isupper(s[i-1])&&isupper(s[i+1])&&s[i-1]<s[i+1]){
				for(char m=s[i-1]+1;m<s[i+1];m++){
					printf("%c",m);
				} 
			}
			//不属于前三种情况，'-'原样输出
			else{
				printf("-");
			} 
		}
	}
	return 0;
}

