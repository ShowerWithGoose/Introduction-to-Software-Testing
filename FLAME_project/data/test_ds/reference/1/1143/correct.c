#include<stdio.h>
#include<string.h>

char s[10000],c[20000];
int i,l,j,p;
int main(){
	gets(s);
	l=strlen(s);
	for(i=0,j=0;i<l;i++,p=0){
		if(s[i]<='z'&&s[i]>='a'){
			if(s[i+1]=='-'&&(s[i+2]<='z'&&s[i+2]>='a')){
				do{
					c[j]=s[i]+p;
					j++;
					p++;
				}while(s[i]+p<s[i+2]);
				i++;
			}
			else {
				c[j]=s[i];
				j++;
			}
		}
		else if(s[i]<='9'&&s[i]>='0'){
			if(s[i+1]=='-'&&(s[i+2]<='9'&&s[i+2]>='0')){
				do{
					c[j]=s[i]+p;
					j++;
					p++;
				}while(s[i]+p<s[i+2]);
				i++;
			}
			else {
				c[j]=s[i];
				j++;
			}
		}
		else if(s[i]<='Z'&&s[i]>='A'){
			if(s[i+1]=='-'&&(s[i+2]<='Z'&&s[i+2]>='A')){
				do{
					c[j]=s[i]+p;
					j++;
					p++;
				}while(s[i]+p<s[i+2]);
				i++;
			}
			else {
				c[j]=s[i];
				j++;
			}
		}
		else{
		c[j]=s[i];
		j++;
		}
	}
	puts(c);
	return 0;
}


