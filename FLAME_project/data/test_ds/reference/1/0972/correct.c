#include<stdio.h>
#include<string.h>

int main(){
	char s[1000];
	scanf("%s",s);
	int i,j,m;
	char ch[1000];
	char k;
	for(i=0,j=0;i<strlen(s);i++){
		if(s[i+1]!='-'){
			ch[j]=s[i];
			j++;
		}
		if(s[i+1]=='-'){
			if(s[i]>='0'&&s[i]<='9'&&s[i+2]>='0'&&s[i+2]<='9'){
				k=s[i];
				for(;k<s[i+2];k+=1){
					ch[j]=k;
					j++;
				}
				i+=1; 
			}
			else if(s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z'){
				k=s[i];
				for(;k<s[i+2];k+=1){
					ch[j]=k;
					j++;
				}
				i+=1; 
			}
			else if(s[i]>='A'&&s[i]<='Z'&&s[i+2]>='A'&&s[i+2]<='Z'){
				k=s[i];
				for(;k<s[i+2];k+=1){
					ch[j]=k;
					j++;
				}
				i+=1; 
			}
			else{
				for(m=0;m<=2;m++){
					ch[j]=s[i];
					j++;i++;
				}
			}
		}
		
	}
	printf("%s",ch);
	return 0;
} 


