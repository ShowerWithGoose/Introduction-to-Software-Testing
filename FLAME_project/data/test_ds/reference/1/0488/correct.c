#include<stdio.h>
#include<string.h>
int main(){
	int length,a;
	char s[1005];
	scanf("%s",s);
	length=strlen(s);
	for(int i=0;i<length;i++){
		printf("%c",s[i]);
		if(s[i+1]=='-'){
			if(s[i]>='0'&&s[i]<='9'&&s[i+2]>='0'&&s[i+2]<='9'&&s[i+2]>s[i]){
				for(a=s[i]+1;a<s[i+2];a++)
					printf("%c",a);
					i++;
			}
			if(s[i]>='a'&&s[i]<='z'&&s[i+2]>='a'&&s[i+2]<='z'&&s[i+2]>s[i]){
				for(a=s[i]+1;a<s[i+2];a++)
					printf("%c",a);
					i++;
			}
			if(s[i]>='A'&&s[i]<='Z'&&s[i+2]>='A'&&s[i+2]<='Z'&&s[i+2]>s[i]){
				for(a=s[i]+1;a<s[i+2];a++)
					printf("%c",a);
					i++;
			}
		}
	}
	
	
	return 0;
}

