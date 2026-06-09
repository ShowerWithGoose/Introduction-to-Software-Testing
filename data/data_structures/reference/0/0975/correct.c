#include<stdio.h>
#include<string.h>

char ch[65536];

int Judge(char x,char y);

int main(){
	gets(ch);
	int i,l=strlen(ch);
	char a,b;
	for(i=1;i<l;i++){
		if(ch[i]!='-'){
			printf("%c",ch[i-1]);
		}
		else{
			if(Judge(ch[i-1],ch[i+1])==1){
				char c=ch[i-1];
				while(c<ch[i+1]){
					printf("%c",c);
					c++;
				}
				i++;
			}
			else{
				printf("%c",ch[i-1]);
			}
		}
	}
	printf("%c",ch[i-1]);
	return 0;
} 

int Judge(char x,char y){
	if(x>='0'&&x<='9'){
		if(y>x&&y>='0'&&y<='9'){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if(x>='a'&&x<='z'){
		if(y>x&&y>='a'&&y<='z'){
			return 1;
		}
		else{
			return 0;
		}
	}
	else if(x>='A'&&x<='Z'){
		if(y>x&&y>='A'&&y<='Z'){
			return 1;
		}
		else{
			return 0;
		}
	}
	else return 0;
}

