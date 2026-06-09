#include<stdio.h>
#include<string.h>
int check(char,char);

int main(){
	char str[1005];
	int i=0;
	int p=1;
	gets(str);
	
	for(;str[i]!='\0';i++){
		
		if(str[i]=='-'&&i!=0&&i!=strlen(str)-1&&str[i+1]-str[i-1]){
			if(check(str[i-1],str[i+1])==1){
				for(p=1;p<str[i+1]-str[i-1];p++){
					printf("%c",str[i-1]+p);
				}
			}
			else printf("%c",str[i]);
		}
		else printf("%c",str[i]);
	}
	
return 0;
}


int check(char a,char b){
	if(a>='a'&&b<='z') return 1;
	else if(a>='A'&&b<='Z') return 1;
	else if(a>='0'&&b<='9') return 1;
	else return -1;
}




