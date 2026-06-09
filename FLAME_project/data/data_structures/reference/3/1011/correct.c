#include<stdio.h>
#include<string.h>
char s[105];
int i,len,front_point,number_start;
int main(){
	fgets(s,104,stdin);
	len = strlen(s);
	for(i=0;i<len-1;i++){
		if(s[i]=='0'){
			continue;
		}
		if(s[i]!='0'&&s[i]!='.'){
			if(number_start!=0)
			continue;
		number_start = i+1;
		if(s[0]=='0')
			number_start = i-1;
		}
		if(s[i]=='.')
		front_point = i-1;
	}
	if(s[0]=='0')
	{
		if(number_start + 2 >=len - 1)
			printf("%c",s[number_start + 1]);
		else
			printf("%c.",s[number_start + 1]);
		for(i=number_start + 2;i<len-1;i++)
		{
			printf("%c",s[i]);
		}
		printf("e-%d",abs(number_start - front_point));
	}
	if(s[0]!='0')
	{
		printf("%c.",s[number_start - 1]);
		for(i=number_start;i<len-1;i++)
		{
			if(s[i]=='.')
				continue;
			printf("%c",s[i]);
		}
		printf("e%d",abs(number_start-front_point-1));	
	}
	return 0;
	
} 

