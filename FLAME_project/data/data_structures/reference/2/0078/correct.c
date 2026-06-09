#include<stdio.h>
#include<string.h>


int main()
{            //undefined
	int a1,a2,a3;
	char op1,op2,op3;

	a1 = 0;           //为了保证结构，在最开始加上一个0+
	op1 = '+';
	while(op1!='=')
	{
		scanf("%d %c",&a2,&op2); //这里用一个空格来忽略空白符
		while(op2=='*' || op2=='/')
		{
			scanf("%d %c",&a3,&op3);
			if(op2=='*') a2 *= a3;
			else if(op2=='/') a2 /= a3;
			op2 = op3; //此处注意
		}
		if(op1=='+') a1 += a2;
		else if(op1=='-') a1 -= a2;
		op1 = op2; //此处注意
	}

	printf("%d",a1);


    return 0;

}

  /*
int main()
{
	char s[100], num[5][100];
	int i=0, j=0, k=0, a[100]={0};
	gets(s);
	
	for (i=0; s[i]!='='; i++) {
		if (s[i]==' ') {

			i--;
		}
		if (s[i]>='0'&&s[i]<='9'){

			num[j++][k++]= s[i];           //atoi(字符串
			//printf("%d ",a[j]);

		}else {

			j=0;
		}


	}
	for (i=0; s[i]!='='; i++) {
		if (s[i]=='*'){            //??
				atoi(num) *= a[j-1];
			}
		if (s[i]=='/'){
				a[j+1] /= a[j-1];
			}else continue;
	}
	for (i=0; s[i]!='='; i++) {
		if (s[i]=='+'){
				a[j+1] += a[j-1];
			}
		if (s[i]=='-'){
				a[j+1] -= a[j-1];
			} else continue;
	}
 if (s[i]=='=') printf("    %d", a[j]) ;

    return 0;

}

	*/



