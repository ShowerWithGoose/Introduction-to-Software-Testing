#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
char s[100];
gets(s); // @@ [Using gets() is unsafe and deprecated; however, the immediate error is that the code logic for parsing and evaluating expressions is flawed. But more critically, the compilation error in the test environment suggests missing compiler, yet assuming that's external, the real issue is logical errors causing wrong output. However, per instructions, we mark lines with potential errors. The primary logical flaw starts in expression parsing and evaluation order.]
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
len=k; // @@ [This sets len to the number of operators, but later digit[len] is printed. However, after processing * and /, the number of meaningful digits is not len+1 anymore due to zeroing out, and the final result isn't necessarily at digit[len].]
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



printf("%d\n",digit[len]); // @@ [The result is not stored in digit[len]. After processing, the final accumulated value is not tracked correctly. The algorithm incorrectly modifies the digit array and assumes the result is at index 'len', which is wrong.]


return 0;
}