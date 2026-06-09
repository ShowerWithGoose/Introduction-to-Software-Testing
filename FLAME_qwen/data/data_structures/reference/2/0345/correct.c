#include <stdio.h>
#include <string.h>
#include <math.h>
struct stack{
	int top;
	int data[10000];
};

int judge(char x){
	switch (x){
		case '+':return 0;break;
		case '-':return 0;break;
		case '*':return 1;break;
		case '/':return 1;break;
	}
	return -1;
}

int cal(int a,char x,int b){
	if(x=='+')return a+b;
	else if(x=='-')return a-b;
	else if(x=='*')return a*b;
	else if(x=='/')return a/b;
	return -1;
	}
	
int main(){
	struct stack num,sign;
	num.top=0;
	sign.top=0;
	char a[10000];
	char b[10000];
	gets(a);
	int tmp;
	int i,j=0;
	for(i=0;a[i]!='\0';i++){
		if(a[i]==' ')continue;
		b[j]=a[i];
		j++;
	}//把去掉空格后的表达式放入a中 
	i=0,j=0;
	while(b[i]!='='){
		if((b[i]<='9'&&b[i]>='0')&&(b[i+1]>'9'||b[i+1]<'0')){
			num.top++;
			num.data[num.top]=b[i]-'0';
		}//单个数字入栈 
		else if((b[i]<='9'&&b[i]>='0')&&(b[i+1]<='9'&&b[i+1]>='0'))
		{
			int k=0;int turn[50]={0};int sum=0;

			while(b[i]<='9'&&b[i]>='0'){
				turn[k]=b[i]-'0';
				i++,k++;
			}
			for(j=0;turn[j]!='\0';j++){
				sum+=turn[j]*(pow(10,k-1));
				k--;
			}
			num.top++;
			num.data[num.top]=sum;
			continue;
		}
		else{//是符号 
			if(sign.top==0){//栈空 
				//进符号栈
				 sign.top++;
				 sign.data[sign.top]=b[i];
			}
			else
			{
				if(judge(b[i])<=judge(sign.data[sign.top]))//优先级小于栈顶 
				{

					while(judge(b[i])<=judge(sign.data[sign.top]))
					{
						tmp=cal(num.data[num.top-1],sign.data[sign.top],num.data[num.top]);
						sign.top--;
						num.top--;
						num.data[num.top]=tmp;
					}
					sign.top++;
				 	sign.data[sign.top]=b[i];
				}
				else//进栈 
				{
					sign.top++;
				 	sign.data[sign.top]=b[i];	
				}
			}
		}
		i++;
	}
	while(sign.top!=0){//符号栈不为空 
		tmp=cal(num.data[num.top-1],sign.data[sign.top],num.data[num.top]);
		sign.top--;
		num.top--;
		num.data[num.top]=tmp;
	}
	printf("%d",num.data[num.top]);
	return 0;
}



