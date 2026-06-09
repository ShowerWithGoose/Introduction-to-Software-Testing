#include<stdio.h>
int cal(int a,int b,char c);
int get_num();
char get_ch();
int main()
{
	int num[5] = {0};
	char ch,ch_1;
	num[0] = get_num();
	ch = get_ch();
	if(ch!='='){
		num[1] = get_num();
	}
	while(ch != '='){
		if(ch=='*'||ch=='/'){
			num[0] = cal(num[0],num[1],ch);
			ch = get_ch();
			if(ch!='='){
				num[1] = get_num();
			}
		}
		else{
			ch_1 = get_ch();
			if(ch_1=='+'||ch_1=='-'||ch_1=='='){
				num[0] = cal(num[0],num[1],ch);
				ch = ch_1;
				if(ch_1 != '='){
					num[1] = get_num();
				}
			}
			else if(ch_1 !='='){
				num[2] = get_num();
				num[1] = cal(num[1],num[2],ch_1);
			}
			else{
				ch = ch_1 ;
			}
		}
	}
	
printf("%d",num[0]);	
	
	return 0;
}

int cal(int a,int b,char c)
{
	int res;
	if(c=='+'){
		res = a+b;
	}
	else if(c=='-'){
		res = a-b;
	}
	else if(c=='*'){
		res = a*b;
	}
	else if(c=='/'){
		res = a/b;
	}
	return res;
}

int get_num()
{
	int num;
	scanf("%d",&num);
	return num;
}

char get_ch()
{
	char x;
	scanf(" %c",&x);
	return x;
}

