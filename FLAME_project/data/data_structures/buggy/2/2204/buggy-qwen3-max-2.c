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

j=j-1; // @@ [This sets j to the index of the last non-space character before '=', but if the input ends with " =", then j becomes index of '=', which breaks parsing logic. Also, it assumes '=' is always present and at the end, but doesn't ensure s[j] is '=' after trimming spaces.]

a1=0;op1='+';
for (int i=0;i<=j;i++)
{
    if(s[i]>'9'||s[i]<'0') {mark=i;break;} // @@ [This loop breaks at the first non-digit, which is correct for finding the first operator, but if the number is 0 or expression starts with operator (which it shouldn't per problem), this may fail. However, main issue is later logic.]
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
if (op1=='+')    {a1=a1+a2;a2=a3;a3=0;op1=op2;op2=s[i];} // @@ [a2 is set to a3, but a3 hasn't been properly initialized or updated for '+'/'-' terms. This incorrectly carries forward a3 (which may be 0) as the next operand, losing the actual next number.]
else if (op1=='-')    {a1=a1-a2;a2=a3;a3=0;op1=op2;op2=s[i];} // @@ [Same issue: a2 is replaced by a3 prematurely, before reading the full next number.]
}
else if(op2=='*'||op2=='/') 
{
if (op2=='*')    {a2=a2*a3;a3=0;op2=s[i];} // @@ [a3 is used before being fully read in many cases. The logic assumes a3 is already the next number, but a3 is only built when i>=mark, which may not have occurred yet.]
else if (op2=='/')    {a2=a2/a3;a3=0;op2=s[i];} // @@ [Division by zero possible if a3 is 0 due to incorrect parsing. Also, same issue of using a3 before it's ready.]
}
if (op2=='=')  
{
    if (op1=='+')    {printf("%d",a1+a2);}
else if (op1=='-')    {printf("%d",a1-a2);}
}
}
else if (i>=mark)a3=a3*10+s[i]-'0'; // @@ [This builds a3 only for characters after 'mark', but 'mark' is fixed as the position of the first operator. Subsequent numbers are not correctly parsed because mark isn't updated, so multi-digit numbers after the second term may not be read properly. Also, a3 is reused without reset between operations.]
}

}

return 0;
}