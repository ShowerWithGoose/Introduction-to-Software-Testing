#include<stdio.h>
#include<malloc.h>
int judge(char a,char b){
	if((a>='a'&&a<='z'&&b>='a'&&b<='z'||a>='A'&&a<='Z'&&b>='A'&&b<='Z'||a>='0'&&a<='9'&&b>='0'&&b<='9')&&a<b){
		return 1;
	}
	return 0;
}
char s[10000],t[10000];
int main(){
	char temp,linshi;
	int j=1,k=1;
	gets(s);
	t[0]=s[0];
	for(j=1;s[j]!='\0';j++){
		if(s[j]=='-'){
			if(judge(s[j-1],s[j+1])){
				temp=s[j-1];
				while(++temp<s[j+1]){
					t[k++]=temp;
				}
			}else{
				t[k++]=s[j];
			}
		}else t[k++]=s[j];
	}t[k]='\0';
	printf("%s",t);
	return 0;
}
