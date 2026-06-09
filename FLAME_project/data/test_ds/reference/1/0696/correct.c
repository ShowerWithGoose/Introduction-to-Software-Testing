#include<stdio.h>
#include<string.h>

char s[100000];

int check1(int i);
int check2(int i);

int main(){
	gets(s);
	int i,j,len;
	len = strlen(s);
	printf("%c",s[0]);
	for(i=1;i<strlen(s)-1;i++){
		if(check1(i)){
			if(check2(i-1)==check2(i+1)&&check2(i-1)!=-1){
				for(j=s[i-1]+1;j<s[i+1];j++)
					printf("%c",j);
			}
			else printf("%c",s[i]);
		}
		else printf("%c",s[i]);
	}
	printf("%c",s[len-1]);
}

int check1(int i){
	if(s[i+1]-s[i-1]>1&&s[i]=='-'){
		return 1;
	}
	else return 0;
}
int check2(int i){
	if(s[i]>='A'&&s[i]<='Z')return 1;
	if(s[i]>='a'&&s[i]<='z')return 2;
	if(s[i]>='0'&&s[i]<='9')return 3;
	else return -1;
}



