#include<stdio.h>
#include<string.h>
int main() {
	char ch[1000];
	gets(ch);
	for(int i=0;i<strlen(ch);i++) {
		if(ch[i]!='-') {
			printf("%c",ch[i]);
		}
		else {
			if(ch[i-1]>='0'&&ch[i-1]<='9') {
				if(ch[i+1]>='0'&&ch[i+1]<='9'){
					for(int j=1;j<ch[i+1]-ch[i-1];j++) {
						printf("%c",ch[i-1]+j);
					}
				}
				else printf("-");
			}
			else if(ch[i-1]>='a'&&ch[i-1]<='z') {
				if(ch[i+1]>='a'&&ch[i+1]<='z') {
					for(int j=1;j<ch[i+1]-ch[i-1];j++) {
						printf("%c",ch[i-1]+j);
					}
				}
				else printf("-");
			}
			else if(ch[i-1]>='A'&&ch[i-1]<='Z') {
				if(ch[i+1]>='A'&&ch[i+1]<='Z') {
					for(int j=1;j<ch[i+1]-ch[i-1];j++) {
						printf("%c",ch[i-1]+j);
					}
				}
				else printf("-");
			}			
			
		}
	}
	 return 0;
}

