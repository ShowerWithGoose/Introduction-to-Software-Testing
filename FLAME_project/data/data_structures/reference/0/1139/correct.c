#include<stdio.h>
#include<string.h>
int alike(char a,char b){
	if(a>='0'&&a<='9'&&b>='0'&&b<='9'&&b>a)return 1;
	if(a>='a'&&a<='z'&&b>='a'&&b<='z'&&b>a)return 1;
	if(a>='A'&&a<='Z'&&b>='A'&&b<='Z'&&b>a)return 1;
	return 0;
}
void widen(char a,char b){
	int i,k=b-a;
	for(i=0;i<k;i++)printf("%c",a+i);
}
int main(){
	char s[105];
	int i,len;
	scanf("%s",s);
	len=strlen(s);
	for(i=0;i<len-1;i++){
		if(s[i+1]=='-'&&alike(s[i],s[i+2])){
			widen(s[i],s[i+2]);
			
			i++;
		}
		else {
			printf("%c",s[i]);
		}
	}
	printf("%c",s[i]);
	return 0;
}

