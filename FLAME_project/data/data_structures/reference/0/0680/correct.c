#include<stdio.h>
#include<string.h>
#include<math.h>
char ch[100];
int main() {
	char a,b[30];
	int i,j,len,flag=0,t;
	gets(ch);
	len=strlen(ch);
	for(i=0; i<len; i++) {
		if(ch[i]=='-') {
			if(ch[i-1]>='a'&&ch[i-1]<='z'&&ch[i+1]>='a'&&ch[i+1]<='z'&&ch[i+1]>ch[i-1]) {
				b[0]=ch[i-1];
				flag=1;
				for(j=1; b[j-1]<ch[i+1]; j++) {
					b[j]=ch[i-1]+j;
				}
			}
			if(ch[i-1]>='A'&&ch[i-1]<='Z'&&ch[i+1]>='A'&&ch[i+1]<='Z'&&ch[i+1]>ch[i-1]) {
				b[0]=ch[i-1];
				flag=1;
				for(j=1; b[j-1]<ch[i+1]; j++) {
					b[j]=ch[i-1]+j;
				}
			}
			if(ch[i-1]>='0'&&ch[i-1]<='9'&&ch[i+1]>='0'&&ch[i+1]<='9'&&ch[i+1]>ch[i-1]) {
				b[0]=ch[i-1];
				flag=1;
				for(j=1; b[j-1]<ch[i+1]; j++) {
					b[j]=ch[i-1]+j;
				}
			}
		}
		if(flag==0){
			printf("%c",ch[i]);
		}else{
			for(t=1;t<j-1;t++){
				printf("%c",b[t]);
			}
		}
		flag=0;
		memset(b,0,sizeof(b));
	}
}


