#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
char s[100];
gets(s);
int i=0;
int j=0;
int k=0;
int len;
int digit[100];
char operater[100];
while(s[i++]!='\0'){ // @@ Should stop when encountering '=', not just '\0'. This causes '=' to be treated as an operator.
 
   if(isdigit(s[i-1])){
     int p=i-1;
     int res=s[p]-'0';
    p++;
     while (s[p]==' '||isdigit(s[p]))
     {
      if(isdigit(s[p])){
     res=res*10+s[p]-'0';
     }
     p++;
     }

     digit[j++]=res;
     i=p;
     
  }
  else if(s[i-1]!=' '){
    operater[k++]=s[i-1]; // @@ Stores '=' as an operator, which should be ignored.
  }
}
operater[k]='\0';
j=0;
k=0;
while (operater[k]!='\0')
{
  if(operater[k]=='*'){
    digit[k+1]=digit[k]*digit[k+1]; // @@ Operation does not remove the operator, leading to incorrect indexing later.
    digit[k]=0; // @@ Setting left operand to zero without compacting breaks subsequent addition/subtraction.
  }
  else if(operater[k]=='/'){
    digit[k+1]=digit[k]/digit[k+1]; // @@ Same issue as multiplication.
    digit[k]=0;
  }
  k++;
}
len=k; // @@ Sets len to the number of operators (including '='), which is larger than the actual operand count.
k=0;
while (operater[k]!='\0')
{
  if(operater[k]=='+'){
    j=k;
    while (digit[++j]==0)
    {
      ;
    }
    digit[j]=digit[k]+digit[j];
    
  }
  else if(operater[k]=='-'){
    j=k;
while (digit[++j]==0)
{
  ;
}
digit[j]=digit[k]-digit[j];


  }
  k++;
}



printf("%d\n",digit[len]); // @@ Accesses digit[len] which is out of bounds, leading to undefined behavior (output 0).

return 0;
}