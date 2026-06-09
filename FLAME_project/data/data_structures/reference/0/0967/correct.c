#include <stdio.h>
#include <string.h> 
void p(char s[],int i){
	int j;
	for(j=s[i-1]+1;j<s[i+1];j++){
		printf("%c",j); 
	}
}
int main()
{
	char s[100000]="";
	int i=0,j=0,k=0,n=0,m=0;
	gets(s);
	for(i=0;i<strlen(s);i++){
		if(s[i]=='-'&&i!=0&&i!=strlen(s)-1){
			if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i+1]>s[i-1]){
				p(s,i);
			}else{
				if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i+1]>s[i-1]){
					p(s,i);
				}else{
					if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]>s[i-1]){
						p(s,i);
					}else{
						printf("-");
					}
				}
			}
		}else{
			printf("%c",s[i]);
		}
	}
	return 0;
} 

