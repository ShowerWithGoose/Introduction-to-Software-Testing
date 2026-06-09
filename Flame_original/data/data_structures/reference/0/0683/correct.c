#include<stdio.h>
#include<string.h>
#include<math.h>
char s[100];
void print(char a,char b){
	char c;
	for(c=a+1;c<=b-1;c++){
		printf("%c",c);
	}
	return;
}
int main(){
	int len,i;
	scanf("%s",s);
	len=strlen(s);
	for(i=0;i<=len;i++){
		printf("%c",s[i]);		
		if(s[i+1]=='-'){
			if(s[i]>='0'&&s[i]<='9'&&s[i+2]>='0'&&s[i+2]<='9'){
				print(s[i],s[i+2]);
				i+=1;
			}
			else if(s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z'){
				print(s[i],s[i+2]);
				i+=1;
			}
			else if(s[i]>='A'&&s[i]<='Z'&&s[i+2]>='A'&&s[i+2]<='Z'){
				print(s[i],s[i+2]);
				i+=1;
			}
		}
	}
	return 0;
} 



