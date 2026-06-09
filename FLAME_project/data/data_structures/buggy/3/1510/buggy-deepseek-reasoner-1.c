#include<stdio.h>
#include<string.h>
int main()
{
   char s[105]={};
   gets(s);
   int num=0,len=0,flag=1;
   int dot=0,valid=0;
   len=strlen(s);
 
  if(s[0]=='0')
  {
      dot=1;
      for(int i=2;i<=len-1;i++)
      {
          if(s[i]!='0') // @@ [只打印非零数字，跳过了中间的零，导致输出缺少零]
          {
              printf("%c",s[i]);
              if(num==0)
              {
              valid=i;
              num=valid-dot;
              }
      
              if(flag==1&&i!=len-1)
              {
                  printf(".");flag=0;
              }
          }
      }
      
      printf("e-%d",num);
  }
  else
  {
          
          printf("%c.",s[0]);
          for(int i=1;i<=len-1;i++)
          {
              if(s[i]!='.')
              {
                  printf("%c",s[i]);
              }
             else
             {
                 dot=i;
                 num=dot-1;
              } 
          }
          printf("e%d",num);
          
     }
      
   return 0;
}