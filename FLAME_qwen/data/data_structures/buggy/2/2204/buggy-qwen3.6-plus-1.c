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
gets(s); // @@ [gets() is deprecated and removed in C11 standard, causing compilation errors in modern environments. Use fgets(s, sizeof(s), stdin) instead.]
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
op2=s[mark]; // @@ [Initializes op2 to the first operator. When the main loop reaches i==mark, it attempts to evaluate this operator immediately, but a3 is still 0, leading to incorrect calculations.]
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
if(op2=='+'||op2=='-') // @@ [Evaluates the previous operator immediately. Fails for the first operator since a3 hasn't accumulated the next number yet. Operand shifting logic is also flawed.]
{
if (op1=='+')    {a1=a1+a2;a2=a3;a3=0;op1=op2;op2=s[i];}
else if (op1=='-')    {a1=a1-a2;a2=a3;a3=0;op1=op2;op2=s[i];}
}
else if(op2=='*'||op2=='/') // @@ [Evaluates * or / using a3 which is 0 for the first occurrence. Precedence handling is broken as it mixes evaluation of previous and current operators incorrectly.]
{
if (op2=='*')    {a2=a2*a3;a3=0;op2=s[i];}
else if (op2=='/')    {a2=a2/a3;a3=0;op2=s[i];}
}
if (op2=='=')  // @@ [Checks op2 after it was just updated to '=' in the branches above. Relies on flawed prior state updates and may produce incorrect results or print multiple times.]
{
    if (op1=='+')    {printf("%d",a1+a2);}
else if (op1=='-')    {printf("%d",a1-a2);}
}
}
else if (i>=mark)a3=a3*10+s[i]-'0'; // @@ [Accumulates digits into a3 but fails to reset a3 to 0 after it is consumed in calculations, causing carry-over errors for subsequent numbers.]
}

}

return 0;
}