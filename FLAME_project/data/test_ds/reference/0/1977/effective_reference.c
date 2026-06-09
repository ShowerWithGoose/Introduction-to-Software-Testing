#include<stdio.h> 
#include<string.h>
int is(char a,char b){
	if((a>='0'&&a<='9')&&(b>='0'&&b<='9'))
	return 1;
	else if((a>='a'&&a<='z')&&(b>='a'&&b<='z'))
	return 2;
	else if((a>='A'&&a<='Z')&&(b>='A'&&b<='Z'))
	return 3;
	else return 0;
}
int main(){
	char str[100],str1[100];int i,l;char k;
	scanf("%s",&str);
	int strLength=strlen(str);
	for(i=0;i<strLength;i++){
		if(is(str[i],str[i+2])!=0&&str[i+1]=='-'&&str[i+2]>str[i]){
			for(k=str[i];k<str[i+2];k++){
				printf("%c",k);
			}
		}
		else if(str[i]=='-'){
		    if(is(str[i-1],str[i+1])==0||str[i+1]<=str[i-1]){
		        printf("-");
			}
	    }
	    else if(str[i]!='-')
	    printf("%c",str[i]);
}
	return 0;
}


