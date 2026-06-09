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
gets(s); // @@ [Using gets() is unsafe and may cause buffer overflow; however, the main logic error is elsewhere.]
l=strlen(s);
for (int i=0;i<l;i++)
{
    if(s[i]!=' ') {s[j]=s[i];j++;}
}

j=j-1; // @@ [This sets j to the index before the '=', but the loop below uses i<=j which skips the '=' character, causing incorrect parsing.]
a1=0;op1='+';
for (int i=0;i<=j;i++)
{
    if(s[i]>'9'||s[i]<'0') {mark=i;break;} // @@ [This only finds the first operator, assuming the expression starts with a number followed by one operator, which breaks for longer expressions.]
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

for (int i=0;i<=j;i++) // @@ [The loop condition excludes the '=' due to j=j-1, so the final operator '=' is never processed, leading to missing final operation.]
{

if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='=') 
{
if(op2=='+'||op2=='-') 
{
if (op1=='+')    {a1=a1+a2;a2=a3;a3=0;op1=op2;op2=s[i];} // @@ [a2 is overwritten with a3 (which is often 0) before processing next term, losing current value.]
else if (op1=='-')    {a1=a1-a2;a2=a3;a3=0;op1=op2;op2=s[i];} // @@ [Same issue: a2 = a3 (0) loses the just-computed term.]
}
else if(op2=='*'||op2=='/') 
{
if (op2=='*')    {a2=a2*a3;a3=0;op2=s[i];} // @@ [a3 is used before being fully parsed in many cases; logic assumes a3 is ready when it's not.]
else if (op2=='/')    {a2=a2/a3;a3=0;op2=s[i];} // @@ [Division by zero possible if a3 is 0; also a3 not properly accumulated.]
}
if (op2=='=')  
{
    if (op1=='+')    {printf("%d",a1+a2);}
else if (op1=='-')    {printf("%d",a1-a2);}
}
}
else if (i>=mark)a3=a3*10+s[i]-'0'; // @@ [a3 accumulation starts from 'mark', but mark is only the first operator; subsequent numbers are misassigned.]
}

}

return 0;
}