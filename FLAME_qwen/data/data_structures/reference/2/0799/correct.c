#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int priority(char a,char b)
{
	/*a在栈中，b要比较*/
	/*只有b直接高级的时候才返回1，其它时候返回0*/
	if((b=='*'||b=='/')&&(a=='+'||a=='-')) return 1;
	else 
	return 0;
}

int main()
{
	char stack_op[100]={0};
	int stack_exp[100]={0};
	int tail_op=-1,tail_exp=-1,r_num;
	char r_op;
	bool state=0; //0读数字，1读符号
	while(1){
		switch(state){
			case 0:
				scanf("%d",&r_num);
				stack_exp[++tail_exp]=r_num;
				break;
			case 1:
				scanf("%c",&r_op);
				if(r_op==' ') continue; 
				if(r_op=='=') goto out;
				while(tail_op>-1&&(!priority(stack_op[tail_op],r_op))){
					int num1=stack_exp[tail_exp-1],num2=stack_exp[tail_exp];
					switch(stack_op[tail_op]){
						case '+': num1 += num2; break;
						case '-': num1 -= num2; break;
						case '*': num1 *= num2; break;
						case '/': num1 /= num2; break;
					}
					stack_exp[--tail_exp]=num1;
					--tail_op;
				}
				stack_op[++tail_op] = r_op;
				break;
		}
		state=!state;
	}
	out:
	//把剩下的符号全部弹出来
	while(tail_op>-1){
		int num1=stack_exp[tail_exp-1],num2=stack_exp[tail_exp];
		switch(stack_op[tail_op]){
			case '+': num1 += num2; break;
			case '-': num1 -= num2; break;
			case '*': num1 *= num2; break;
			case '/': num1 /= num2; break;
		}
		stack_exp[--tail_exp]=num1;
		--tail_op;
	} 
	printf("%d",stack_exp[tail_exp]);
	return 0; 
}



