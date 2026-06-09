#include <stdio.h>
char word[5]={};
int i=0;
void insert(char c){
	word[i]=c;
	i=!i;
	return;
}
char find(){
	return word[!i];
}
int main(){
	char c,last;
	int flag=0,have=0;
	while(~scanf("%c",&c)&&c!='\n'){
		if(flag==1){
			last=find();
			if(c>last&&have==1&&((last>='a'&&c>='a'&&last<='z'&&c<='z')||(last>='A'&&c>='A'&&last<='Z'&&c<='Z')||(last>='0'&&c>='0'&&last<='9'&&c<='9'))){
				for(char i=last+1;i<=c;i++){
					printf("%c",i);
				}
			}else{
				printf("-%c",c);
			}
			insert(c);
			have=1;
			flag=0;
			continue;
		}
		if(c!='-'){
			printf("%c",c);
			insert(c);
			have=1;
		}else{
			flag=1;
		}
	}
	
	return 0;
}

