#include<stdio.h>
#include<string.h>
int value(char a)
{
  int ans;
  if(a=='+'||a=='-')
  ans=0;
  if(a=='*'||a=='/')
  ans=1;
  return ans;
}

int main()
{
  int i=0,j=0,t=0,r=0,q=0;
  char s[105],fact[105],op[105],op_sec[105];
  int num[105]={0},el[105]={},ans=0;
  gets(s);

  for(i=0;i<strlen(s)-1;i++)//消去空格和等号
  {
    if(s[i]!=' ')
    {fact[j]=s[i],j++;}
  }
  
  for(i=0,j=0;i<strlen(fact);i++)
  {
    while(fact[i]<='9'&&fact[i]>='0')//读出每两个运算符号间的数,有j-1个数
    {num[j]=num[j]*10+(fact[i]-'0'),i++;}
    j++;

    if(fact[i]>'9'||fact[i]<'0')//把符号存起来，有t-1个符号
    {op[t]=fact[i],t++;}
  }

  //默认第一个数是正的
    for(i=0,r=0,q=0;i<t;i++)//把式子中的乘除先都算出来
    {
      if(value(op[i])==0)
      {el[r]=num[i],op_sec[q]=op[i];
       r++,q++;}
      else if(value(op[i])){
        el[r]=num[i];
        while(value(op[i]))//是乘除就接着往后继续读
        {
          if(op[i]=='*')
          el[r]=el[r]*num[i+1];
          else
          el[r]=el[r]/num[i+1];

          i++;
        }
        op_sec[q]=op[i],q++;
        r++;
      }
    }//有r-1个数，q-1个加号或减号
  
    ans=el[0];
    for(i=0;i<q;i++)
    {
      if(op_sec[i]=='+')
      ans=ans+el[i+1];
      else
      ans=ans-el[i+1];
    }
  
  printf("%d\n",ans);
  return 0;
}
