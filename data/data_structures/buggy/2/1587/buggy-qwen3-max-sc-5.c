#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
char s[100];
gets(s); // @@ [Using gets() is unsafe and deprecated; however, the immediate error is not here. The real issue is logic errors in expression evaluation, but the compilation error reported ("gcc: not found") is environmental. However, per problem context, we are to find logical/semantic bugs causing wrong output. The actual bugs are in the evaluation logic.]
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
len=k;
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



printf("%d\n",digit[len]); // @@ [This prints digit[len], but len equals the number of operators, and after processing, the result may not be at digit[len]. Also, the algorithm incorrectly zeroes out operands and fails to handle operator precedence correctly across the entire expression, especially when multiple * or / are followed by + or -. The final result is not accumulated properly.]






































return 0;
}