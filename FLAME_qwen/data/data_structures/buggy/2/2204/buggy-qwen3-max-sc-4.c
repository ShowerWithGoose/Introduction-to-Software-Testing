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
gets(s); // @@ [Using gets() is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments, gets() is not available, leading to a compilation error.]
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
a2=a2*10+s[i]-'0'; // @@ [a2 is used uninitialized. This leads to undefined behavior because a2 starts with an indeterminate value.]
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
if (op1=='+')    {a1=a1+a2;a2=a3;a3=0;op1=op2;op2=s[i];} // @@ [a3 is used uninitialized when assigned to a2. If the expression starts with a single number followed by operators, a3 may never be set before use.]
else if (op1=='-')    {a1=a1-a2;a2=a3;a3=0;op1=op2;op2=s[i];}
}
else if(op2=='*'||op2=='/') 
{
if (op2=='*')    {a2=a2*a3;a3=0;op2=s[i];} // @@ [a3 is uninitialized here as well; using it in multiplication or division leads to undefined behavior.]
else if (op2=='/')    {a2=a2/a3;a3=0;op2=s[i];} // @@ [Division by uninitialized a3 could also cause division by zero or garbage results. Additionally, if a3 is zero, this causes undefined behavior.]
}
if (op2=='=')  
{
    if (op1=='+')    {printf("%d",a1+a2);}
else if (op1=='-')    {printf("%d",a1-a2);}
}
}
else if (i>=mark)a3=a3*10+s[i]-'0'; // @@ [a3 is used uninitialized on first use in this accumulation. It should be initialized to 0 before the loop.]
}

}

return 0;
}