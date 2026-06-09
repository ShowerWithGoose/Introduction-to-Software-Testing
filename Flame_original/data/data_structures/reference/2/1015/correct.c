#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXSIZE 100
typedef int ElemType;

struct stack{
 int Top;
 ElemType data[MAXSIZE];
};
typedef struct stack Stack;
typedef struct stack *Stackp;
Stack OPFIGURE,OPTHETA;
void  push( Stackp s,  ElemType item )
{
 s->data[++s->Top]=item; 
}
int pop( Stackp s)
{
 return s->data[s->Top--]; 
}
int Gettop( Stackp s )
{
 return s->data[s->Top];
}
char Pre(char theta1,char theta2)
{
 int i,j;
 char pre[8][8]={
               {'>','>','<','<','<','>','>','<'},  
                     {'>','>','<','<','<','>','>','<'},  
                     {'>','>','>','>','<','>','>','>'},  
                     {'>','>','>','>','<','>','>','>'},  
                     {'<','<','<','<','<','=','0','<'},  
                     {'>','>','>','>','0','>','>','>'},  
                     {'<','<','<','<','<','0','=','<'},
      {'>','>','>','>','<','>','>','>'},}; 
                
    switch(theta1){
     case '+': i=0; break;  
        case '-': i=1; break;  
        case '*': i=2; break;  
        case '/': i=3; break;  
        case '(': i=4; break;  
        case ')': i=5; break;
        case '=': i=6; break;
        case '%': i=7; break;
 }
 
    switch(theta2){
     case '+': j=0; break;  
        case '-': j=1; break;  
        case '*': j=2; break;  
        case '/': j=3; break;  
        case '(': j=4; break;  
        case ')': j=5; break;
        case '=': j=6; break;
        case '%': j=7; break;
    }
    return(pre[i][j]);
}
int Op(int a,char theta,int b)

{
 
 switch(theta){
  case'+':return a+b;
  case'-':return a-b;
  case'*':return a*b;
  case'%':return a%b;
  case'/': 
          if(b!=0)
          return a/b;
          else
          {
           exit(0);
    }
 }
    
}
int IsTheta(char c)
{
 switch(c){
  case '+':   
        case '-':  
        case '*':   
        case '/':   
        case '(':   
        case ')': 
        case '%': 
        case '=': 
                 return 1;
   default:
           return 0;     
 }
}
int EvaluateExpression(char *expression)  
{
int a,b,theta,X1,X2,tmp;

 char ch;
 int i=0;
 
 OPFIGURE.Top=-1;
 OPTHETA.Top=-1;
 push(&OPTHETA,'=');
 ch=expression[i++];
 
 while(ch!='=' || Gettop(&OPTHETA)!='=')
 {
  if(IsTheta(ch)) 
  {
   switch(Pre(Gettop(&OPTHETA),ch)) 
   {
    case'<':
      push(&OPTHETA,ch);
      ch=expression[i++];
      break;
    case'>':
      theta=pop(&OPTHETA); 
         b=pop(&OPFIGURE);
         a=pop(&OPFIGURE);
         push(&OPFIGURE,Op(a,theta,b));
         break;
    case'=':
      tmp=pop(&OPTHETA);
         ch=expression[i++]; 
         break;
   } 
   
  }
  else if(isdigit(ch))  
  {
   X1=ch-'0'; 
   push(&OPFIGURE,X1);
   X2=X1;
   ch=expression[i++];
   
   while(isdigit(ch)) 
   {
    X1=ch-'0';
    X2=10*X2+X1; 
    tmp=pop(&OPFIGURE);
    push(&OPFIGURE,X2);
    ch=expression[i++];  
    
   } 
  }
  else if(ch==' ') 
  {
   while(ch==' ')
   {
    ch=expression[i++];
   }
  }
  else
  {
   exit(0); 
  }
 }
 return(Gettop(&OPFIGURE));
}
int main()
{ 
 char expression[100];
 int result;
 gets(expression);
 result=EvaluateExpression(expression);
 printf("%d\n",result);
 return 0;
}

