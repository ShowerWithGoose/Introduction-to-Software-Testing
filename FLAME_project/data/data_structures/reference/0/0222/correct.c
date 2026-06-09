#include <stdio.h>
#include <string.h>
char s[10000000];
int i,j,k,a,b;
int main(){
	gets(s);
	a=strlen(s)-1;
	for(i=1;i<a;i++){
		if(s[i]=='-'){
			if((s[i-1]>='0'&&s[i+1]<='9')||(s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')){
				b=s[i+1]-s[i-1]-2;
				for(j=a;j>=i+1;j--){
					s[j+b]=s[j];
				}
				for(j=i;j<=i+b;j++){
					s[j]=s[i-1]+j-i+1;
				}
				s[j+a+1]='\0';
				i+=b+1;
				a=strlen(s)-1;
			}
		}
	}
	puts(s);
	return 0;
}

