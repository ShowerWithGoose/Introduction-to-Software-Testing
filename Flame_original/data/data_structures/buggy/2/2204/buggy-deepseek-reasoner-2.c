#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int a1,a2,a3; // @@ Error: a2 and a3 are not initialized; using them later leads to undefined behavior.
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
a2=a2*10+s[i]-'0'; // @@ Error: a2 is uninitialized; should be set to 0 before this loop.
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
if (op1=='+')    {a1=a1+a2;a2=a3;a3=0;op1=op2;op2=s[i];} // @@ Error: uses a3 before the next number is accumulated; a3 is 0 at the first operator, causing loss of a2.
else if (op1=='-')    {a1=a1-a2;a2=a3;a3=0;op1=op2;op2=s[i];} // @@ Error: same logic error.
}
else if(op2=='*'||op2=='/') 
{
if (op2=='*')    {a2=a2*a3;a3=0;op2=s[i];} // @@ Error: uses a3 before it is built; a3 is 0 at first operator, setting a2 to 0.
else if (op2=='/')    {a2=a2/a3;a3=0;op2=s[i];} // @@ Error: same issue; also division by zero if a3 is 0.
}
if (op2=='=')  
{
    if (op1=='+')    {printf("%d",a1+a2);}
else if (op1=='-')    {printf("%d",a1-a2);}
}
}
else if (i>=mark)a3=a3*10+s[i]-'0'; // @@ Error: a3 is uninitialized on first use; should be initialized to 0 before this loop.
}

}

return 0;
}