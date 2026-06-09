#include<stdio.h>
int cal(int a,int b,char c);
int readnum();
char readop();
int main()
{int a[2];
 char b[1];
 int num;
 int op;
 a[0]=readnum();
 b[0]=readop();
 if(b[0]!='=')
 a[1]=readnum();
 while(b[0]!='=')
 {if(b[0]=='*'||b[0]=='/')
  {
  a[0]=cal(a[0],a[1],b[0]);
  b[0]=readop();
  if (b[0] != '=')
  a[1]=readnum();
 }
  else
  {op=readop();
   if(op=='+'||op=='-'||op=='=')
   {a[0]=cal(a[0],a[1],b[0]);
    b[0]=op;
    if(op!='=')
    a[1]=readnum();
    
   }
   else if(op!='=')
   {num=readnum();
   a[1]=cal(a[1],num,op);
   
   }
   else
   b[0]=op;
  }

}
  printf("%d",a[0]);
}
int cal(int a, int b, char c)
{
 if(c=='+')
 return a+b;
 if(c=='-')
 return a-b;
 if(c=='*')
 return a*b;
 if(c=='/')
 return a/b;
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


