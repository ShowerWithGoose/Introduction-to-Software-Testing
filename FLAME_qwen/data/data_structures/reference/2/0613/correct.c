#include<stdio.h>
#include<string.h>
int cal (int a,char x,int b)
{ switch(x){  case '+':  a+=b;break; 
 case '-':  a-=b;break;
  case '*':  a*=b;break; 
 case '/':  if( b != 0)a/=b;  break; }
 return a;}
int main()
{ int num1,num2,num; char sign1,sign2,sign; 
scanf("%d %c",&num1,&sign1);  
 if(sign1 == '='){  printf("%d\n",num1); 
 return 0; }
 while(sign1 != '='){ while(sign1 == '*'||sign1 == '/')
{   scanf("%d %c",&num2,&sign2); 
  num1 = cal(num1,sign1,num2);   sign1 = sign2;    }  
if(sign2 == '=') break; 
 scanf("%d %c",&num,&sign);
  while((sign == '*'||sign == '/'))
{   scanf("%d %c",&num2,&sign2);  
 num = cal(num,sign,num2);   
sign = sign2;}
num1=cal(num1,sign1,num);  sign1 = sign;  
if(sign1 == '=') break;  }
printf("%d",num1); 
return 0;} 

