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

for (int i=0;i<=j;i++) // @@ The loop logic is flawed. It iterates through the entire string again, but the handling of operators and operands is incorrect. Specifically, it fails to correctly parse subsequent numbers after the first operator because `a3` is only updated when `i >= mark`, but `mark` is fixed at the position of the *first* operator. This means for an expression like "24 / 4 / 3...", after processing the first '/', it tries to read the next number into `a3` starting from index `mark` (which is the position of '/'), causing it to re-read or skip characters incorrectly, leading to division by zero or incorrect values. Furthermore, the state management of `a1`, `a2`, `a3` and operators `op1`, `op2` is inconsistent with standard precedence parsing.
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
else if (op2=='/')    {a2=a2/a3;a3=0;op2=s[i];} // @@ Potential division by zero if a3 is 0 due to incorrect parsing logic described above. In the test case "24 / 4 / 3 / 2 * 2 * 3 * 4 =", the incorrect parsing likely results in a3 being 0 or uninitialized when this line is executed for subsequent divisions.
}
if (op2=='=')  
{
    if (op1=='+')    {printf("%d",a1+a2);}
else if (op1=='-')    {printf("%d",a1-a2);}
}
}
else if (i>=mark)a3=a3*10+s[i]-'0'; // @@ This condition `i>=mark` is incorrect for parsing multiple operands. `mark` is the index of the first operator. For subsequent numbers, their indices are greater than `mark`, but the logic doesn't reset `mark` or handle the transition between operands correctly. It assumes all subsequent digits belong to `a3`, which is wrong when there are multiple operators.
}

}

return 0;
}