#include<stdio.h>
#include<string.h>
#define NUM 1
#define LOW 2
#define CAP 3
char a[1005];
int i,j;
int type(char b){
	if(b>='0'&&b<='9')return NUM;
	if(b>='a'&&b<='z')return LOW;
	if(b>='A'&&b<='Z')return CAP;
	return -1;
}
void expand(int p){
	if(type(a[p-1]!=-1)&&type(a[p-1])==type(a[p+1])){
		for(j=a[p-1]+1;j<a[p+1];j++){
			printf("%c",j);
		}
	}else printf("-");
}
int main(){
	scanf("%s",a+1);
	int len=strlen(a+1);
	for(i=1;i<=len;i++){
		if(a[i]=='-'){
			expand(i);
		}else{
			printf("%c",a[i]);
		}
	}
	return 0;
}


