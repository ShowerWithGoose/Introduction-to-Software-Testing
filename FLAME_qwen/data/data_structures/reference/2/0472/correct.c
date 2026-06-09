#include<stdio.h>
int jisuan(int a,int b,char op);
int readnum();					
char readop();	
int main(){
	
	int a[3];
	int b[2];
	a[0]=readnum();
	b[0]=readop();
	if(b[0]=='='){
		printf("%d",a[0]);
	}
	else{
		a[1]=readnum();
		while(b[0]!='='){
			if(b[0]=='*'||b[0]=='/'){
				a[0]=jisuan(a[0],a[1],b[0]);
				b[0]=readop();
				a[1]=readnum();
				
			}
			else{
				b[1]=readop();
				if(b[1]=='*'||b[1]=='/'){
					a[2]=readnum();
					a[1]=jisuan(a[1],a[2],b[1]);
					//b[1]=readop();
				}
				else{
					a[0]=jisuan(a[0],a[1],b[0]);
					a[1]=readnum();
					b[0]=b[1];
				}
			}
		}
		printf("%d",a[0]);
	}
	
	
	
	
	return 0;
}
int jisuan(int a, int b, char op)
{
	int result;
	if (op == '+')
		result = a + b;
	else if (op == '-')
		result = a - b;
	else if (op == '*')
		result = a * b;
	else
		result = a / b;
	return result;
}
 
int readnum()
{
	int num;
	scanf(" %d", &num);
	return num;
}
char readop()
{
	char op;
	scanf(" %c", &op);
	return op;
}

