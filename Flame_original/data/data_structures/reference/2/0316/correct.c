#include <stdio.h>
#include <string.h>
int main()
{	int i=0,k=0;
	char op1,op2,op3; 
	int a3=0;
	int a1=0,a2=0;
	int j=0;
	int temp=1;//用于求这个数字 
	int location[100];
	int number[100]={0};
	char s[100],t[100];
	char first[100];//乘除符号的地址
	char second[100];//加减符号的地址 
	gets(s);
	int count=0;
	int n=0;//几位数 
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]!=' ')
		t[k++]=s[i];
	 } 
	 t[k]='\0';//到此将所有的空格去除；
	for(i=0;i<strlen(t);i++) 
	 {
	 	if(t[i]=='+'||t[i]=='-'||t[i]=='*'||t[i]=='/'||t[i]=='=')
	 	{
	 		location[j++]=i;//将字符串中出现运算符号的位置存起来		 
	 	}
	 }
	 //现在location[j-1]存放等号的地址 
	 //j为运算符号的出现次数加等号的出现次数 
	 for(i=j-1;i>0;i--)//i为 t串中等号的地址 
	 	{	temp=1; 
		 	n=location[i]-location[i-1]-1;//几位数   //location是运算符号的地址，i是符号的编号，同样是第几个数字； 
		 	for(k=0;k<n;k++) 
	 		{
			 number[i]+=(t[location[i]-(k+1)]-'0')*temp;
			 temp=temp*10;
			}
			
		}
	temp=1;
	for(i=0;i<location[0];i++)
	{
	number[0]+=(t[location[0]-(i+1)]-'0')*temp;
	temp=temp*10;
	
	}
	
//	for(i=0;i<j;i++)
//	{
//		printf("%d\n",number[i]);//到此所有数字全部被存储在number数组中，开头为number[0]的j个数字； 
//	 } 
	i=0;
	k=0;
	op1='+';
	op2=t[location[k]];//k为符号的编号，0开头    i为数字开头，数组以0开头
	a1=0;
	while(op1!='=')
	{		
		a2=number[i++];
		while(t[location[k]]=='*'||t[location[k]]=='/')
		{	
			if(t[location[k]]=='*')
				a2*=number[i++];
			else if(t[location[k]]=='/') 
				a2/=number[i++];

			k++;
		}
			if(op1=='+'||op1=='-')
			{
				if(op1=='+')
				a1+=a2;
				if(op1=='-')
				a1-=a2; 	
				
			}
		op1=t[location[k++]];
	
	}
	printf("%d",a1);
	return 0;
}
 

