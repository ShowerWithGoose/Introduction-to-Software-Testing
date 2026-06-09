#include<stdio.h>
#include<string.h>
#include<ctype.h>
char s[10000];
int retSeperate[10000];
char *locSeparate[10000];
int myPower(int n,int p)
{
  int ret=1;
  while(p--)
  {
    ret*=n;
  }
  return ret;
}

int scanDigit(char *begin,char *end)
{
  int ret=0;
  int digit=end-begin;
  while (digit--)
  {
    ret+=myPower(10,digit)*(*begin-'0');
    begin++;
  }
  //printf("%d\n",ret);
  return ret;
  
}
int calTwo(int a,char op,int b)
{
  if(op=='+')
  {
    return a+b;
  }
  else if(op=='-')
  {
    return a-b;
  }
  else if(op=='*')
  {
    return a*b;
  }
  else if(op=='/')
  {
    return a/b;
  }
}
int doCal(char *begin)
{
  int digitTmp[100];
  char operatorTmp[100];
  int digitCount=0;
  int operatorCount=0;
  char *end=begin;
  for(;*end!='+'&&*end!='-'&&*end!='\0';end++)
  {
    if(*end=='*'||*end=='/')
    {
      operatorTmp[operatorCount++]=*end;
    }
    
  }
  
  for(;;)
  {
    
    char *tmp=begin;
    while(isdigit(*tmp))
    {
      tmp++;
        
    }
    digitTmp[digitCount++]=scanDigit(begin,tmp);
    if(digitCount>operatorCount)
    {
      break;
    }
    begin=tmp+1;
  }
  int ret=digitTmp[0];
  for(int i=1,j=0;j<operatorCount;j++,i++)
  {
    ret=calTwo(ret,operatorTmp[j],digitTmp[i]);
  }
  return ret;
  
}
int main(void)
{
  
  
  int len=0;
  char tmp;
  while((tmp=getchar())!='=')
  {
    if(tmp==' ')
    {
      continue;
    }
    else
    {
      s[len++]=tmp;
    }
  }
  s[len]='\0';
  int separate=1;
  locSeparate[separate-1]=&s[0];
  for(int i=0;i<strlen(s);i++)
  {
    if(s[i]=='+'||s[i]=='-')
    {
      
      separate++;
      locSeparate[separate-1]=&s[i+1];
    }
  }
  int ret=doCal(locSeparate[0]);
  for(int i=1;i<separate;i++)
  {
    
    ret=calTwo(ret,*(locSeparate[i]-1),doCal(locSeparate[i]));
    //printf("%d\n",ret);
  }
  printf("%d\n",ret);
  return 0;

  // int ret=0;
  // for(int i=0;i<strlen(s);)
  // {
  //   if(isdigit(s[i]))
  //   {
  //     int j=i;
  //     while (isdigit(s[j]))
  //     {
  //       j++;
  //       i++;
  //     }
      
  //     ret=scanDigit(&s[i],&s[j]);
      
  //   }
  //   else
  //   {

  //   }
  // }


}
