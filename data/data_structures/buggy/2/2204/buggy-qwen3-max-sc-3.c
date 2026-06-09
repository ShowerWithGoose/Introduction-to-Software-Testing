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
gets(s); // @@ [Using `gets` is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments, `gets` is not available, leading to compilation errors.]
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
a2=a2*10+s[i]-'0'; // @@ [Variable `a2` is used uninitialized. This leads to undefined behavior because `a2` starts with an indeterminate value.]
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
if (op1=='+')    {a1=a1+a2;a2=a3;a3=0;op1=op2;op2=s[i];} // @@ [Variable `a3` is used uninitialized when assigned to `a2`. This causes undefined behavior.]
else if (op1=='-')    {a1=a1-a2;a2=a3;a3=0;op1=op2;op2=s[i];} // @@ [Same issue: `a3` is uninitialized when assigned to `a2`.]
}
else if(op2=='*'||op2=='/') 
{
if (op2=='*')    {a2=a2*a3;a3=0;op2=s[i];} // @@ [`a3` is uninitialized here, leading to undefined behavior in multiplication.]
else if (op2=='/')    {a2=a2/a3;a3=0;op2=s[i];} // @@ [Division by uninitialized `a3`—undefined behavior; could even cause division by zero.]
}
if (op2=='=')  
{
    if (op1=='+')    {printf("%d",a1+a2);}
else if (op1=='-')    {printf("%d",a1-a2);}
}
}
else if (i>=mark)a3=a3*10+s[i]-'0'; // @@ [`a3` is used uninitialized in `a3*10`; this is undefined behavior.]
}

}

return 0;
}