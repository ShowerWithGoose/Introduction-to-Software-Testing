#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int a1,a2,a3;
char op1,op2,op3,mark;
char s[1009]; 
int main()
{
int l,j=0;
gets(s); // @@ gets is unsafe, but the major logical errors are elsewhere
l=strlen(s);
for (int i=0;i<l;i++)
{
    if(s[i]!=' ') {s[j]=s[i];j++;}
}

j=j-1;
a1=0;op1='+';
for (int i=0;i<=j;i++)
{
    if(s[i]>'9'||s[i]<'0') {mark=i;break;}
}
op2=s[mark];
for (int i=0;i<mark;i++)
{
a2=a2*10+s[i]-'0';
}

if (op2=='=')
{
printf("%d",a2);

 } 

 else{

for (int i=0;i<=j;i++)
{

if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='=') 
{
if(op2=='+'||op2=='-') 
{
if (op1=='+')    {a1=a1+a2;a2=a3;a3=0;op1=op2;op2=s[i];} // @@ When op2 is the first operator, a3 is 0 (not yet parsed), leading to loss of the first number in expressions starting with '+' or '-'.
else if (op1=='-')    {a1=a1-a2;a2=a3;a3=0;op1=op2;op2=s[i];} // @@ Same issue as above.
}
else if(op2=='*'||op2=='/') 
{
if (op2=='*')    {a2=a2*a3;a3=0;op2=s[i];} // @@ Multiplies/divides by a3 before it has been set from the following number (a3 is 0 initially or from previous operation).
else if (op2=='/')    {a2=a2/a3;a3=0;op2=s[i];} // @@ Same issue, and division by zero when a3=0.
}
if (op2=='=')  
{
    if (op1=='+')    {printf("%d",a1+a2);}
else if (op1=='-')    {printf("%d",a1-a2);} // @@ Only handles final combination when the last operator was '+' or '-', but not when the last operation is '*' or '/' (result stored in a2, not a1).
}
}
else if (i>=mark)a3=a3*10+s[i]-'0';
}

}

return 0;
}