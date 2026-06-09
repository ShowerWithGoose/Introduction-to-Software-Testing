#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
char s[100];
int num1[100];
int num2[100]; 
char op1[100];
char op2[100];
int cnt_num=0,cnt_op=0;
int temp;
int operation(char c,int a,int b);//用于计算二元数的运算，a？b ，连续运算需要用上一个结果作为其中一元计算 
int main()
{
	int i,j,n,l=0,a;
	int k=0,m=0;
	gets(s);         //读入 
	for(i=j=0;s[i]!='\0';i++){     //删除空格 
		if(s[i]!=' ')
		s[j++]=s[i];	
	}
		s[j]='\0';
//	for(i=0;s[i]!='\0';i++)
//	printf("%c",s[i]); 
//	printf("\n");
	for(i=0;s[i]!='\0';i++){       //数字和字符分开存储 
		if(isdigit(s[i])>0){
			for(n=0; isdigit(s[i])>0; i++){//是数字 
			n=10*n+s[i]-'0';
			cnt_num++;
		}
		num1[k++]=n; 
	}	
		if(isdigit(s[i])==0){//是运算符 
			op1[m++]=s[i];
			cnt_op++;
		}
		
	}
//	for(i=0;i<k;i++)
//	printf("%d ",num1[i]);
//	printf("\n");
//	for(i=0;i<m;i++)
//	printf("%c",op1[i]);
//		printf("\n");
	for(i=n=a=0;i<cnt_op;i++){     //挑出乘除计算 
		if(op1[i]=='*'||op1[i]=='/'){
			j=i;
			temp=operation(op1[j],num1[j],num1[j+1]); 
			while(op1[j+1]=='*'||op1[j+1]=='/') {
				temp=operation(op1[j+1],temp,num1[j+2]);
				j++;
				i++;
			}
			num2[n]=temp;
			n++;
	}
		else {
			op2[a]=op1[i];
			a++;
			if(i!=j+1){
			num2[n]=num1[i];
			n++;
			}
		}		 
	}
//	for(i=0;i<n;i++)
//	printf("%d ",num2[i]);
//	printf("\n");
	//for(i=0;i<a;i++)
	//printf("%c",op2[i]);
//	printf("\n");
	if(op2[0]!='=')	{

		j=0;
		temp=operation(op2[j],num2[j],num2[j+1]);
		while(op2[j+1]!='='){
			temp=operation(op2[j+1],temp,num2[j+2]);
			j++;
		}
		printf("%d",temp);
	}
	else printf("%d",num2[0]);	

 	return 0;
}

int operation(char c,int a,int b){
	
	if(c=='+') {
		return a+b;
	}
	else if(c=='-'){
		return a-b;
	} 
	else if(c=='*') {
		return a*b;
	}
	else if(c=='/') {
		return a/b;
	}	
}

/*思路：
1、输入的运算表达式应选择字符数组，以“=”作为结束符号
2、表达式中会有空格，为保证读入，不能用scanf，只能gets
3、先算乘除，后算加减。除法用整除方式 ，全程int 
4、有可能没有任何符号，500=结果为500，5 - 1 * 2 * 3 + 12 / 2 / 2 =结果为2 
5、可以先去除所有空格（？） 
6、计数器？判断运算顺序
7、 设计一个函数进行二元整数运算(进入此函数的参数只有两个元和一个符号，不是数组)
8、考虑两位数以上的运算，不能一个数字一个数字扫描读取，要作为一个整体。 
9、把字符串中的数字变成实际数字，多位数也可应用。 
10、问题：如何提取多位数字，以及如何连乘连除？ 
*/
//5-1*2*3+12/2/2=




