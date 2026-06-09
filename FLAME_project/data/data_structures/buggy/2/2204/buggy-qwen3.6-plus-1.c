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
gets(s);
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

for (int i=0;i<=j;i++) // @@ The loop logic is flawed. It iterates through the string but fails to correctly parse subsequent numbers after the first operator, leading to uninitialized variables (a3) being used in calculations. Specifically, when encountering '*' or '/', it uses 'a3' which has not been updated with the next number in the sequence because the parsing logic for numbers inside this loop is incorrect (it only updates a3 if i >= mark, which is static). This causes division by zero or incorrect arithmetic, leading to Runtime Error or Wrong Answer.
{

if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='=') 
{
if(op2=='+'||op2=='-') 
{
if (op1=='+')    {a1=a1+a2;a2=a3;a3=0;op1=op2;op2=s[i];}
else if (op1=='-')    {a1=a1-a2;a2=a3;a3=0;op1=op2;op2=s[i];}
}
else if(op2=='*'||op2=='/') 
{
if (op2=='*')    {a2=a2*a3;a3=0;op2=s[i];} // @@ Uses uninitialized or stale 'a3'. The code does not correctly parse the operand following the '*' or '/' operator before performing the operation.
else if (op2=='/')    {a2=a2/a3;a3=0;op2=s[i];} // @@ Uses uninitialized or stale 'a3'. Division by zero may occur if a3 is 0, causing Runtime Error.
}
if (op2=='=')  
{
    if (op1=='+')    {printf("%d",a1+a2);}
else if (op1=='-')    {printf("%d",a1-a2);}
}
}
else if (i>=mark)a3=a3*10+s[i]-'0'; // @@ This condition 'i>=mark' is only true for the first number after the first operator. For subsequent operators and numbers, this logic fails to update a2 or a3 correctly because 'mark' is fixed to the position of the first operator.
}

}

return 0;
}