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
gets(s); // @@ [Using gets() is unsafe and may not be available in modern C standards; it was removed in C11. This can cause compilation errors with strict compilers or when using certain flags.]
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
a2=a2*10+s[i]-'0'; // @@ [a2 is used uninitialized. It should be initialized to 0 before this loop. Using an uninitialized variable leads to undefined behavior and may cause incorrect results or crashes.]
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
if (op2=='*')    {a2=a2*a3;a3=0;op2=s[i];} // @@ [a3 is used uninitialized here. If the first operator after the initial number is * or /, a3 will be 0 (from global initialization), but this logic fails for expressions like "2*3+4" because a3 hasn't been read yet. The parsing logic is fundamentally flawed.]
else if (op2=='/')    {a2=a2/a3;a3=0;op2=s[i];} // @@ [Same issue: division by zero possible if a3 is 0 due to uninitialized or incomplete parsing. Also, integer division by zero causes runtime crash, but more importantly, the parsing order is incorrect.]
}
if (op2=='=')  
{
    if (op1=='+')    {printf("%d",a1+a2);}
else if (op1=='-')    {printf("%d",a1-a2);}
}
}
else if (i>=mark)a3=a3*10+s[i]-'0'; // @@ [a3 is used uninitialized here as well. Also, the condition i>=mark may include operator characters if mark points to the first operator, leading to incorrect digit accumulation.]
}

}

return 0;
}