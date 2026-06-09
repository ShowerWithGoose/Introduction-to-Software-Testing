#include<stdio.h>
#include<string.h>
int main()
{
 char s[1005];
 gets(s);         //输入字符串 
 int n,i;
 n=strlen(s);    //得出字符串长度 n 
 printf("%c",s[0]);    //直接打印第一个 
 for(i=1;i<n-1;i++)   //从第二个字符开始  因为第一个字符就算是-也不用展开 
 {
  
  if(s[i]=='-'&&48<=s[i-1]&&s[i-1]<=57&&s[i+1]<=57&&s[i+1]>=48&&(s[i+1]-s[i-1])>0)
  {int a;
  a=s[i+1]-s[i-1];
  for(int A=1;A<a;A++)
  {
   printf("%c",s[i-1]+A);
  }
  }//一种   如果 字符是- 并且前后符合条件 则打印两者之间的所有数 不含首尾 
  
  
  else if(s[i]=='-'&&s[i-1]>=65&&s[i-1]<=90&&s[i+1]>=65&&s[i+1]<=90&&(s[i+1]-s[i-1])>0)
  {int b;
  b=s[i+1]-s[i-1];
  for(int B=1;B<b;B++)
  {
   printf("%c",s[i-1]+B);
  }
  }//两种   同上 
  
  else if(s[i]=='-'&&s[i-1]>=97&&s[i-1]<=122&&s[i+1]>=97&&s[i+1]<=122&&(s[i+1]-s[i-1])>0)
  {int c;
  c=s[i+1]-s[i-1];
  for(int C=1;C<c;C++)
  {
   printf("%c",s[i-1]+C);
  }
  }//三种   同上 
  
  else   //注意这是否则  除了上述情况就会打印   自身   
  {
   printf("%c",s[i]);
  }
 
 }
 printf("%c",s[n-1]);  //打印最后一个  因为循环不会算到最后一个 
 return 0;
}

