#include<stdio.h>
#include<string.h>
int main(){
	char str[110]={0};
	char a,c;
	int k=0;
	c=getchar();
	while(c!=EOF){
		str[k++]=c;
		c=getchar();
	}
	for(int i=0;i<strlen(str);i++){
		if(str[i]=='-'){
			if(i==0){
				printf("-");
			}
			else if(str[i-1]<='9'&&str[i-1]>='0'){
				if(str[i+1]>str[i-1]&&str[i+1]<='9'){
					for(int j=1;j<(str[i+1]-'0')-(str[i-1]-'0');j++){
						a=j+str[i-1];
						printf("%c",a);
					}
				}
				else{
					printf("-");
				}
			}
			else if(str[i-1]<='z'&&str[i-1]>='a'){
				if(str[i+1]>str[i-1]&&str[i+1]<='z'){
					for(int j=1;j<(str[i+1]-'a')-(str[i-1]-'a');j++){
						a=j+str[i-1];
						printf("%c",a);
					}
				}
				else{
					printf("-");
				}
			}
			else if(str[i-1]<='Z'&&str[i-1]>='A'){
				if(str[i+1]>str[i-1]&&str[i+1]<='Z'){
					for(int j=1;j<(str[i+1]-'A')-(str[i-1]-'A');j++){
						a=j+str[i-1];
						printf("%c",a);
					}
				}
				else{
					printf("-");
				}
			}
			else{
				printf("-");
			}
		}
		else{
			printf("%c",str[i]);
		}
	}
	return 0;
}

