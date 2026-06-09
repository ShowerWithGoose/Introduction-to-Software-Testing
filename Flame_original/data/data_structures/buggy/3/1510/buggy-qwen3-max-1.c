#include<stdio.h>
#include<string.h>
int main()
{
   char s[105]={};
   gets(s); // @@ [Using `gets()` is unsafe and deprecated; it can cause buffer overflow. Also, in many modern environments, `gets` is not available, which may lead to compilation errors.]
   int num=0,len=0,flag=1;
   int dot=0,valid=0;
   len=strlen(s);
 
  if(s[0]=='0')
  {
      dot=1;
      for(int i=2;i<=len-1;i++)
      {
          if(s[i]!='0')
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
      
      printf("e-%d",num); // @@ [If the input is "0.0", this block may not print any digit before 'e', violating scientific notation format. Also, `num` remains 0 if all digits after decimal are zero, but problem states no trailing zeros, so maybe acceptable. However, logic for exponent calculation is flawed: for "0.1", `i=2`, `valid=2`, `dot=1`, so `num=1`, prints "1e-1" — correct. But if input is "0.001", it prints "1e-2", should be "1e-3". So exponent is off by one.]
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
          printf("e%d",num); // @@ [If there's no decimal point in input (e.g., "123"), `dot` remains 0, so `num = -1`, leading to wrong exponent. Also, loop condition `i<=len-1` is okay, but if no '.' exists, `num` is never set correctly. Problem states input has digits before and after decimal point, so maybe safe, but code assumes '.' exists in non-zero-leading case. However, if input like "123.45", `dot=3`, `num=2`, prints "1.2345e2" — correct. But what if input is "1.0"? Problem says no trailing zeros, so "1.0" won't appear. Still, logic relies on encountering '.' to set `num`. If input lacks '.', undefined behavior.]
          
     }
      
   return 0;
}