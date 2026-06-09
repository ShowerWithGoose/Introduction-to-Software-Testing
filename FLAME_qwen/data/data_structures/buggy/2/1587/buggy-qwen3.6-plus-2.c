#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
char s[100];
gets(s); // @@ `gets` is deprecated and removed in C11, causing compilation errors in modern compilers; use `fgets` instead.
int i=0;
int j=0;
int k=0;
int len;
int digit[100]; // @@ Array is uninitialized, leading to undefined behavior when checking for zero values later.
char operater[100];
while(s[i++]!='\0'){
 
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
    operater[k++]=s[i-1];
  }
}
operater[k]='\0';
j=0;
k=0;
while (operater[k]!='\0')
{
  if(operater[k]=='*'){
    digit[k+1]=digit[k]*digit[k+1];
    digit[k]=0;

  }
  else if(operater[k]=='/'){
    digit[k+1]=digit[k]/digit[k+1];
    digit[k]=0;
  }
  k++;
}
len=k;
k=0;
while (operater[k]!='\0')
{
  if(operater[k]=='+'){
    j=k;
    while (digit[++j]==0) // @@ Logic error: relies on uninitialized array values being zero and incorrectly skips valid zero operands.
    {
      ;
    }
    digit[j]=digit[k]+digit[j]; // @@ Logic error: `digit[k]` is set to 0 earlier, so this addition does not accumulate the result correctly.
    
  }
  else if(operater[k]=='-'){
    j=k;
while (digit[++j]==0)
{
  ;
}
digit[j]=digit[k]-digit[j]; // @@ Logic error: same as above, `digit[k]` is 0, so subtraction is incorrect.


  }
  k++;
}



printf("%d\n",digit[len]); // @@ Logic error: `len` is the count of operators, not the index of the final result; the result should be at `digit[0]` or the last valid index.

return 0;
}