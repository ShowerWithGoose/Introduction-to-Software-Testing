#include <stdio.h>
#include <string.h>

void quchu(char s[])
{
	int i,j;
	for (i=j=0;s[i]!='\0';i++)
		if(s[i]!=' ')
			s[j++]=s[i];
		s[j]='\0';
}

int main(){

	int num1=0,num2,num3;
	char sym1='+',sym2,sym3;
	while(sym1!='='){
		int i=0;
scanf("%d %c",&num2,&sym2);
		while(sym2=='*'||sym2=='/'){
			scanf("%d %c",&num3,&sym3);
			if(sym2=='*'){
				num2=num2*num3;
			}
			else if(sym2=='/'){
				num2=num2/num3;
			}
			sym2=sym3;
		}
		if(sym1=='+'){
			num1=num1+num2;
		}
		else if(sym1=='-'){
			num1=num1-num2;
		}
		sym1=sym2;
	}
	printf("%d",num1);
	return 0;
}



