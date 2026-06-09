#include<stdio.h>
#include<string.h>
int main() {
	char s[1000];
	char ss[1000];
	gets(s);
	int i=1,l=strlen(s),m=0;
	for(i; s[i]!='\0'; i++) {
		if(s[i]=='-') {
			if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]<='z'&&s[i+1]>='a'&&s[i-1]<s[i+1]) {
				strcpy(ss,s+(i+1));//从i+1开始拷贝到ss 
				m=i;//确定-的位置 
				int a= s[i+1]-s[i-1]-1;
				for(int j=0; j<a; j++) {

					s[m]=s[m-1]+1;
					m++;
				}
				s[m]='\0';//把后面清除掉，防止加重复。 
				strcat(s,ss);
			}
			else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]<='Z'&&s[i+1]>='A'&&s[i-1]<s[i+1]) {
				strcpy(ss,s+(i+1));//从i+1开始拷贝到ss 
				m=i;//确定-的位置 
				int a= s[i+1]-s[i-1]-1;
				for(int j=0; j<a; j++) {

					s[m]=s[m-1]+1;
					m++;
				}
				s[m]='\0';//把后面清除掉，防止加重复。 
				strcat(s,ss);
			}
			if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]<='9'&&s[i+1]>='0'&&s[i-1]<s[i+1]) {
				strcpy(ss,s+(i+1));//从i+1开始拷贝到ss 
				m=i;//确定-的位置 
				int a= s[i+1]-s[i-1]-1;
				for(int j=0; j<a; j++) {

					s[m]=s[m-1]+1;
					m++;
				}
				s[m]='\0';//把后面清除掉，防止加重复。 
				strcat(s,ss);
			}
		}
	}
	puts(s);
	return 0;
}



