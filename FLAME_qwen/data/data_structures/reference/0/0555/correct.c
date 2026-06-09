#include<stdio.h>
#include<string.h>
int digit(char n)
{
	if(n>='0'&&n<='9'){
		return 1;
	}	else return 0;
}
int lower(char n)
{
	if(n>='a'&&n<='z'){
	return 1;
	}	else return 0;
}
int higher(char n){
	if(n>='A'&&n<='Z'){
		return 1;
	}	else return 0;
}
int judgement(char a,char b){
	if(digit(a)&&digit(b)==1){
		return 1;
	}if(lower(a)&&lower(b)==1){
		return 1;
	}if(higher(a)&&higher(b)==1){
		return 1;
	}
	return 0;
} 
int main()
{
	char s[100],x;
	gets(s);
	int len=strlen(s);
	for(int i=0;i<len;i++){
		if(i==len-1||s[i+1]!='-'){
			printf("%c",s[i]);
		}
		else{
			if(s[i]<s[i+2]&&judgement(s[i],s[i+2])){
				for(x=s[i];x<s[i+2];x++){
					printf("%c",x);
				}
				i++;
			}
			else{
				printf("%c-",s[i]);
				i++;
			}
		}
	}
	return 0;
 }




