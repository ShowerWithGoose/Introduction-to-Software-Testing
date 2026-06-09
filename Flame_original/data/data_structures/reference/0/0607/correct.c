#include<stdio.h>

int judge(char a,char b){
	if(a<='z'&&a>='a'&&b<='z'&&b>='a')
		if(a<b) return 1;
	if(a<='Z'&&a>='A'&&b<='Z'&&b>='A')
		if(a<b) return 1;
	if(a<='9'&&a>='0'&&b<='9'&&b>='0')
		if(a<b) return 1;
	return 0;
}

int main(){
	char s[1000010];
	gets(s);
	int i;
	for(i=0; s[i]!='\0'; i++){
		putchar(s[i]);
		if(s[i+1]=='-'){
			//puts("1");
			if(judge(s[i],s[i+2])){
				//puts("2");
				int j=s[i+2]-s[i];
				for(j=1; s[i]+j<s[i+2]; j++){
					putchar(s[i]+j);
				}
				i++;
			}
		} 
	}
	return 0;
}




