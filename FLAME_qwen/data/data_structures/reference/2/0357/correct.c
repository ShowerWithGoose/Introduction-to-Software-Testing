#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>

#define maxN 100100

char s[1000];
long long op1[maxN];
char op2[maxN];
int num1,num2;

void handle()
{
	switch(op2[num2]){
		case '+':
			op1[num1-1]=(op1[num1-1]+op1[num1]);
			num1--; 
			break;
		case '-':
			op1[num1-1]=(op1[num1-1]-op1[num1]);
			num1--;
			break;
		case '*':
			op1[num1-1]=(op1[num1-1]*op1[num1]);
			num1--;
			break;
		case '/':
			op1[num1-1]=(op1[num1-1]/op1[num1]);
			num1--;
			break;			
	}
}
void work1()
{
	while(num2>0&&op2[num2]!='('){
		handle();
		num2--;
	}
}

void work2()
{
	while(num2>0&&(op2[num2]=='*'||op2[num2]=='/')){
		handle();
		num2--;
	} 
} 

int main()
{
    //freopen("expr.in","r",stdin);
    //freopen("expr.out","w",stdout);
    gets(s);
    int len=strlen(s);
	int i=0;
	while(i<len){
		if(s[i]<='9'&&s[i]>'0'){
			long long temp=0;
			while(i<len&&s[i]>='0'&&s[i]<='9'){
				temp=(temp*10+s[i]-'0');
				i++;
			}
			num1++;
			op1[num1]=temp;
		}
		if(i==len)
			break;
		switch(s[i]){
			case '+':
			case '-':
					work1();
					op2[++num2]=s[i];
					break;
			case '*':
			case '/':
					work2();
					op2[++num2]=s[i];
					break;
			case '(':
					op2[++num2]=s[i];
					break;
			case ')':
					work1();
					num2--; 
					break;
		}
		++i;
		//printf("%d\n",num1);
		//for(int i=1;i<=num1;++i)
		//printf("%lld \n",op1[i]);
		
		//printf("%d\n",num2);
		//for(int i=1;i<=num2;++i)
		//printf("%d \n",op2[i]);
		//printf("\n\n");
	}   
    work1();
    printf("%lld \n",op1[1]);
    return 0;
}



