#include<stdio.h>
#include<string.h>
int main(){
	char m[100];
	fgets(m,100,stdin);//gets不安全无输入限制,用fgets替代，stdin代表的是输入缓冲区！ 
	for(int i=0;i<(int)strlen(m);i++){//加括号int 强制转换类型 
		if(m[i]=='-'){
			if(m[i-1]>='a'&&m[i-1]<='z'&&m[i+1]>='a'&&m[i+1]<='z'&&m[i-1]<m[i+1]){
				for(char n=m[i-1]+1;n<m[i+1];n++)
				printf("%c",n);
			}
			else if(m[i-1]>='A'&&m[i-1]<='Z'&&m[i+1]>='A'&&m[i+1]<='Z'&&m[i-1]<m[i+1]){
				for(char n=m[i-1]+1;n<m[i+1];n++)
								printf("%c",n);
			}
			else if(m[i-1]<='9'&&m[i-1]>='0'&&m[i+1]>='0'&&m[i+1]<='9'&&m[i-1]<m[i+1]){
				for(char n=m[i-1]+1;n<m[i+1];n++)
								printf("%c",n);
			}
			else
			printf("%c",m[i]);
		}
		else
		printf("%c",m[i]);
	}
	printf("\n");
	return 0;
}



