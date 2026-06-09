#include <stdio.h>
char s[10000];
char t[10000]; 
int judge(char a, char b){
	if(((a>='a' && a<='z') && (b>='a' && b<='z')) || ((a>='A' && a<='Z') && (b>='A' && b<='Z')) || ((a>='0' && a<='9') && (b>='0' && b<='9')))
		return 1;
	else	return 0;
}
int main(){
	gets(s);
	int i,j=0,k;
	for(i=0;s[i]!='\0';i++){
		if(s[i+1]=='-' && judge(s[i],s[i+2])){
			for(k=0;k<s[i+2]-s[i];k++){
				t[j++]=s[i]+k;
			}
			i++;
		}else{
			t[j++]=s[i];
		}
	}
	t[j]='\0';
	puts(t);
	return 0;
}

