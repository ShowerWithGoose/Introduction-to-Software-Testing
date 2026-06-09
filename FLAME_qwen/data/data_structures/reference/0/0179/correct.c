#include <stdio.h>
#include <string.h>
char s[];
int main()
{ 
int i=0;int n=0,j,k;
gets(s);
int m=strlen(s);

for(i=0;i<m;i++){
	if(s[i]>='0'&&s[i]<='9'){
		if(s[i+1]=='-'&&s[i+2]<='9'&&s[i+2]>s[i]){
			printf("%c",s[i]);
			for(j=s[i]+1;j<s[i+2];j++){
				printf("%c",j);
			}
			i++;
		}
		else{
			printf("%c",s[i]);
		}
		   
	}
	else if(s[i]>='a'&&s[i]<='z'){
		if(s[i+1]=='-'&&s[i+2]<='z'&&s[i+2]>s[i]){
			printf("%c",s[i]);
			for(j=s[i]+1;j<s[i+2];j++){
				printf("%c",j);
			}i++;
		}
		else{
			printf("%c",s[i]);
		}
		
	}
	else if(s[i]>='A'&&s[i]<='Z'){
		if(s[i+1]=='-'&&s[i+2]<='Z'&&s[i+2]>s[i]){
			printf("%c",s[i]);
			for(j=s[i]+1;j<s[i+2];j++){
				printf("%c",j);
			}i++;
		}
		else{
			printf("%c",s[i]);
		}
	}else{
		printf("%c",s[i]);
	}
}

return 0;}



