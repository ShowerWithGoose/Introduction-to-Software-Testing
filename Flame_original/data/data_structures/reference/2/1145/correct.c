#include<stdio.h>
#include<stdlib.h>
int jisuanjieguo(int,int,char);//char为运算符号
int main()
{
int x,y,z;
x=0;
char f1,f2,zhongjian;
f1='+';
while(f1!='='){
     scanf("%d %c",&y,&f2);
	 while((f2=='*')||(f2=='/')){
		scanf("%d %c",&z,&zhongjian);
		y=jisuanjieguo(y,z,f2);//与上个高级运算符号进行计算
		f2=zhongjian;
		}
	 x=jisuanjieguo(x,y,f1); //与上层运算符号计算
	 f1=f2;
	 }
if(f1=='=') printf("%d",x);
return 0;
}

int jisuanjieguo(int n,int m,char j)
{int he;
	if(j=='*') he=n*m;
	else if(j=='/') he=n/m;
	else if(j=='+') he=n+m;
	else if(j=='-') he=n-m;
return he;
}











































