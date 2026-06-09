#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
struct stack{
	char s[1000];
	int top; 
}aa;
struct stack *pstack;
char out(struct stack *pstack){
	char temp = pstack->s[pstack->top];
	pstack->top --;
	return temp;
}
void in(char a,struct stack *pstack){
	pstack->s[++(pstack->top)] = a;
	
}
int main(){
	int number[100] = {0};
	char older[1000];
	char newer[1000];
	int i = 0;
	int j = 0;
	gets(older);
	pstack = &aa;
	int leng = strlen(older);
	for(;i<leng;i++){
		if(older[i]<='9'&&older[i]>='0'){
			newer[j++] = older[i];
		}
		else if(older[i]=='+'||older[i]=='-' ){
			newer[j++] = ' ';
			while(aa.top!=-1){
				newer[j++] = out(pstack);
			}
			in(older[i],pstack);
		}
		else if(older[i]=='*'||older[i]=='/'){
			newer[j++] = ' ';
			while(aa.s[aa.top]=='*'||aa.s[aa.top]=='/'){
				newer[j++] = out(pstack);
			}
			in(older[i],pstack);
		}
	}
	while(aa.top != -1){
				newer[j++] = out(pstack);
			}
	j--;
	

	
	
	
	int k = 0;
	int flag = 1;
	for(i = 0;i<=j;i++){
		if(newer[i]>='0'&&newer[i]<='9'){
			if(flag == 0){
				number[k-1]=number[k-1]*10 + newer[i] - '0';
			}
			else if(flag!=0){
				number[k++] =(newer[i] - '0');
			}
			flag = 0;
		}
		else if(newer[i] == ' '){
			flag = 1 ;
		}
		else if(newer[i] == '+'){
			number[k-2] = number[k-1] + number[k-2];
			number[k-1] = 0;
			k--;
		}
		else if(newer[i] == '-'){
			number[k-2] = number[k-2] - number[k-1];
			number[k-1] = 0;
			k--;
		}
		else if(newer[i] == '*'){
			number[k-2] = number[k-1] * number[k-2];
			number[k-1] = 0;
			k--;
		}
		else if(newer[i] == '/'){
			number[k-2] = number[k-2] / number[k-1];
			number[k-1] = 0;
			k--;
		}
	}
	printf("%d",number[0]);
	
	
	
	
	
	
	
	return 0;
}

