#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define eps 1e-6

void squeez(char a[10000])
{
	int i,j;
	for(i=j=0;a[i]!='\0';i++)
		if(a[i]!=' ')
			a[j++]=a[i];
	a[j]='\0';
}

int Cal(int a,char op,int b)
{
	if(op=='+'){
		return a+b;
	}
	if(op=='-'){
		return b-a;
	}
	if(op=='*'){
		return a*b;
	}
	return a/b;
}


int carry_num[1000];
char carry_op[1000];

int main(){
	char *a=(char *)malloc(100000*sizeof(char)); 
	scanf("%[^\n]",a);
	squeez(a);
	int cntn=0,num=0,cnto=0;
	char op;
	while(*a>='0' && *a<='9'){
		num=num*10+*a-'0';
		a++;
	}
	carry_num[cntn++] = num;
	while(*a!='='){
		op=*a; a++;
		if(op=='+' || op=='-'){
			if(cntn==1){
				carry_op[cnto++]=op;
				num=0;
				while(*a>='0' && *a<='9'){
					num=num*10+*a-'0';
					a++;
				}
				carry_num[cntn++]=num;
				continue;
			}
			int temp_num1,temp_num2;
			temp_num1 = carry_num[--cntn];
			temp_num2 = carry_num[--cntn];
			char temp_op = carry_op[--cnto];
			carry_num[cntn++] = Cal(temp_num1,temp_op,temp_num2);
			carry_op[cnto++] = op;
			num=0;
			while(*a>='0' && *a<='9'){
				num=num*10+*a-'0';
				a++;
			}
			carry_num[cntn++] = num;
		}else{
			int temp_num1,temp_num2;
			temp_num1 = carry_num[--cntn];
			num=0;
			while(*a>='0' && *a<='9'){
				num=num*10+*a-'0';
				a++;
			}
			temp_num2 = num;
			carry_num[cntn++] = Cal(temp_num1,op,temp_num2);
		}
	}
	if(cnto > 0){
		int temp_num1,temp_num2;
		temp_num1 = carry_num[--cntn];
		temp_num2 = carry_num[--cntn];
		char temp_op = carry_op[--cnto];
		carry_num[cntn++] = Cal(temp_num1,temp_op,temp_num2);
		printf("%d",carry_num[--cntn]);
	}else{
		printf("%d",carry_num[--cntn]);
	}
	return 0;
}



