#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
int a1,a2,a3;
char op1,op2,op3,mark; // @@ mark should be declared as int to safely store array indices; using char may cause overflow or compilation errors with strict type checking.
char s[1009]; 
int main()
{
int l,j=0;
gets(s); // @@ gets() is removed in the C11 standard and causes a compilation error in modern compilers; use fgets(s, sizeof(s), stdin) instead.
l=strlen(s);
for (int i=0;i<l;i++)
{
    if(s[i]!=' ') {s[j]=s[i];j++;}
}

j=j-1; // @@ The string s is not null-terminated after removing spaces, which can lead to undefined behavior or out-of-bounds access when processing the string.
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
if (op1=='+')    {a1=a1+a2;a2=a3;a3=0;op1=op2;op2=s[i];}
else if (op1=='-')    {a1=a1-a2;a2=a3;a3=0;op1=op2;op2=s[i];}
}
else if(op2=='*'||op2=='/') 
{
if (op2=='*')    {a2=a2*a3;a3=0;op2=s[i];}
else if (op2=='/')    {a2=a2/a3;a3=0;op2=s[i];}
}
if (op2=='=')  
{
    if (op1=='+')    {printf("%d",a1+a2);}
else if (op1=='-')    {printf("%d",a1-a2);}
}
}
else if (i>=mark)a3=a3*10+s[i]-'0';
}

}

return 0;
}