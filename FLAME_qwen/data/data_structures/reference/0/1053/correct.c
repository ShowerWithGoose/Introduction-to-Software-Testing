#include<stdio.h>


int main(){
	char s[1000];
	
	scanf("%s",s);
	for(int i=0;s[i]!='\0';){
		printf("%c",s[i]);
		i++;
		if(s[i]=='-'&&((s[i-1]>='a'&&s[i+1]<='z')||(s[i-1]>='A'&&s[i+1]<='Z')||(s[i-1]>='0'&&s[i+1]<='9'))){
			char S=s[i-1]+1;
			do{
				printf("%c",S);
				S=S+1;
			}while(S!=s[i+1]);
			i=i+1;
		}			
	}
	return 0;
}

