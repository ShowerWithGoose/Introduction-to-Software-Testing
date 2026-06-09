#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int cal(int a,char x,int b) {
	switch(x) {
		case '+':
			return a+b;
			break;
		case '-':
			return a-b;
			break;
		case '*':
			return a*b;
			break;
		case '/':
			return a/b;
			break;
		default:
			return 0;
			break;
	}
}

int main() {
	int num[3];
	char op[2];
	scanf("%d %c",&num[0],&op[0]);
	if(op[0]=='=') {
		printf("%d",num[0]);
		return 0;
	} else {
		scanf(" %d",&num[1]);
		while(op[0]!='='||op[1]!='=') {
			scanf(" %c",&op[1]);
			if(op[1]=='=') {
				num[0]=cal(num[0],op[0],num[1]);
				printf("%d",num[0]);
				return 0;
			}
			scanf(" %d",&num[2]);
			if(op[0]=='*'||op[0]=='/') {
				num[0]=cal(num[0],op[0],num[1]);
				op[0]=op[1];
				num[1]=num[2];
			} else {
				if(op[1]=='*'||op[1]=='/') {
					num[1]=cal(num[1],op[1],num[2]);
				} else {
					num[0]=cal(num[0],op[0],num[1]);
					op[0]=op[1];
					num[1]=num[2];

				}
			}
		}
		return 0;
	}

}



