#include <stdio.h>
#include <string.h>

int calculateString(char *s){
	if(!s||strlen(s)==0){
		return 0;
	}
    int *stack = (int*)malloc(strlen(s)*sizeof(int));
	int top = -1;
	int i;
	int num;
	char op = '\0';
	int ret = 0;
	for(i=0;i<strlen(s);i++){
		num=0;
		if(s[i]>='0'&&s[i]<='9'){
			while(i<strlen(s)&&(s[i]>='0'&&s[i]<='9')){
				num = num*10+(s[i]-'0');
				i++;
			}
			i-=1;
			switch(op){
				case('-'): num = -num;break;
				case('*'): num = stack[top--]*num;break;
				case('/'): num = stack[top--]/num;break;
				default: break;
			}
			stack[++top] = num;
		}
		else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
			op=s[i];
		}
	}
	while (top != -1)
        ret += stack[top--];
    return ret;
}

int main(){
	char s[100];
	gets(s);
	printf("%d",calculateString(s));
}

