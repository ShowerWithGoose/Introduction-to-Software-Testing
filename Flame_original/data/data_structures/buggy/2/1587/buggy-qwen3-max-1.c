#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
char s[100];
gets(s); // @@ [Using gets() is unsafe and deprecated; however, the immediate error is that the code logic for parsing and evaluating expressions is flawed. But the compilation error reported ("gcc: not found") is environmental, not code-related. However, assuming the real issue is logical/runtime, multiple bugs exist in expression evaluation. The primary logical errors are:]
int i=0;
int j=0;
int k=0;
int len;
int digit[100];
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
len=k; // @@ [This sets len to the number of operators, but digit[len] may be out of bounds or not the final result]
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



printf("%d\n",digit[len]); // @@ [The final result is not necessarily at digit[len]; this indexing is incorrect. Also, the algorithm fails to correctly handle operator precedence and accumulation of results, especially for sequences like "5 - 1 * 2 * 3 + 12 / 2 / 2 =". The approach of zeroing operands and scanning forward is flawed and leads to wrong results or undefined behavior.]




































return 0;
}