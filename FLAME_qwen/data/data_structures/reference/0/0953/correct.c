#include <stdio.h>
#include<string.h>
int main(){
	char str[105],a[105];
	gets(str);
	int j=0;
	for(int i=0;str[i]!='\0';i++){	
		if(str[i]=='-'){
			if((str[i-1]>='0'&&str[i-1]<='9')&&(str[i+1]>='0'&&str[i+1]<='9')&&str[i-1]<str[i+1]){
				for(int k=str[i-1];k<str[i+1]-1;k++){
					a[j++]=k+1;
				}
			}
			else if((str[i-1]>='a'&&str[i-1]<='z')&&(str[i+1]>='a'&&str[i+1]<='z')&&str[i-1]<str[i+1]){
				for(int k=str[i-1];k<str[i+1]-1;k++){
					a[j++]=k+1;
				}
			}
			else if((str[i-1]>='A'&&str[i-1]<='Z')&&(str[i+1]>='A'&&str[i+1]<='Z')&&str[i-1]<str[i+1]){
				for(int k=str[i-1];k<str[i+1]-1;k++){
					a[j++]=k+1;
				}
			}
			else{
				a[j++]='-';
			}
		}
		else
			a[j++]=str[i];
	}
	a[j]='\0';
	puts(a);
	return 0;
}

