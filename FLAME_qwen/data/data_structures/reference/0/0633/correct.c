#include<stdio.h>
#include<ctype.h>

int main()
{
	char ch[300];
	scanf("%s",ch); 
	for(int i=0;ch[i]!='\0';i++){
		if(ch[i]=='-'){
			if(islower(ch[i-1])&&islower(ch[i+1])&&ch[i-1]<ch[i+1]){
				for(int k=1;k<ch[i+1]-ch[i-1];k++){
					printf("%c",ch[i-1]+k);
				}
			}
			else if(isupper(ch[i-1])&&isupper(ch[i+1])&&ch[i-1]<ch[i+1]){
				for(int k=1;k<ch[i+1]-ch[i-1];k++){
					printf("%c",ch[i-1]+k);
				}
			}
			else if(isdigit(ch[i-1])&&isdigit(ch[i+1])&&ch[i-1]<ch[i+1]){
				for(int k=1;k<ch[i+1]-ch[i-1];k++){
					printf("%c",ch[i-1]+k);
				}
			}
			else
			printf("%c",ch[i]);
		}
		else
		printf("%c",ch[i]);
	}
	return 0;
}

