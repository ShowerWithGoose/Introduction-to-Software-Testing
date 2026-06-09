#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char s1[200],s2[200],fu[200],fu2[200];
int num1[200],num2[200];
int main()
{ int l1,l2,i,j,k=0,sum=0,y;
  gets(s1);
  l1=strlen(s1);
  for(i=0;i<l1;i++)
  {if(s1[i]!=' ')
   {s2[k]=s1[i];
    k++;
   }
  }
  s2[k]='\0';
  l2=strlen(s2);
  for(i=0;i<l2;i++)
  { scanf("%d",&num1[i]); // @@ 错误：应从字符串s2解析数字，而不是从标准输入重新读取
      scanf("%c",&fu[i]); // @@ 错误：应从字符串s2解析运算符，而不是从标准输入重新读取
      {if(fu[i]=='=')
       break;
      }
  }
  k=0;
  y=num1[0];
  for(j=0;j<=i;j++)
  { if(j>1)
    {if(fu[j-1]=='+'||fu[j-1]=='-')
    y=num1[j];}
    if(fu[j]=='+'||fu[i]=='-'||fu[i]=='=') // @@ 错误：使用了错误的索引 fu[i] 应为 fu[j]；且缺少对 '-' 的正确判断
    {num2[k]=y;
     fu2[k]=fu[j];
     k++;
     }
    if(fu[j]=='*')
    {  
       y*=num1[j+1]; // @@ 错误：可能数组越界，未检查 j+1 是否有效
    }
      if(fu[j]=='/')
    {  
       y/=num1[j+1]; // @@ 错误：可能数组越界，未检查 j+1 是否有效
    }
  }
  sum=num2[0]; // @@ 错误：若 num2 为空（k=0），访问 num2[0] 是未定义行为
  for(j=0;j<k;j++)
  {
      if(fu2[j]=='+')
      sum+=num2[j+1];
      if(fu2[j]=='-')
      sum-=num2[j+1];
      
  }
   printf("%d",sum);
  return 0;
}