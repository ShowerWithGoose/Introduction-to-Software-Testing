#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
char putin[100];
    char putout[100],tmp[100];
    int i=0,j=1,e=0;
    int k=0,flag;
    int wei;
 int main()
 {
  //  int fu;
  //  double pu;
  //  int e=0;
  //  int a[1000];
  //  scanf("%lf",&pu);
   
  //  if(pu>=1||pu<(-10))
  //  {
  //    while (pu>10||pu<-10)
  //    {
  //      pu/=10;
  //      e++;
  //    }
  //    printf("%lf",pu);
  //    printf("e");
  //    printf("%d",e);
  //  }
  //  else if((pu<=1&&pu>=0)||(pu<0&&pu>=-1))
  //  {
  //    while ((pu<=1&&pu>=0)||(pu<0&&pu>=-1))
  //    {
  //      pu*=10;
  //      e++;
  //    }
  //    fu=-e;
  //    printf("%lf",pu);
  //    printf("e");
  //    printf("%d",fu);
  //  }
  // 由于数字太长，所以，采用字符串的方式读入
     
    

    gets(putin);//读入
// 先处理大于1的情况
   if (putin[0]!='0')
   {
     for ( i = 0; putin[i]!='\0'; i++)
     {
       if (putin[i]=='.')
       {
        flag=i;
       }
       
     }
     
     e=flag-1;

     for ( i = 0; putin[i]!='\0'; i++)
     {if (putin[i]>='0'&&putin[i]<='9')
     {
       putout[k++]=putin[i];
     }
     
       
       
     }
  printf("%c",putout[0]);
  printf(".");
  for ( i = 1; putout[i]!='\0'; i++)
  {
    printf("%c",putout[i]);
  }
  printf("e");
  printf("%d",e);
     
   }
  //  下面是小于一的情况
  else
  { //去掉多余的0
  int len;
  len=strlen(putin);
  for(int i=len-1;i>=0;i--)
  {
    if(putin[i]<='9'&&putin[i]>='1')
    break;
    if(putin[i]=='0')
    putin[i]='\0';
  }



    i=0;
    while (putin[i]=='0'||putin[i]=='.')
  {
    i++;
  }
  e=i-1;//算e
  // 下面统计0的个数
  for ( i = 0; putin[i]!='\0'; i++)
    {
      if (putin[i]!='0'&&putin[i]!='.')
      {
        wei=i-1;
        break;
      }
      
    }
    
    for ( i = wei+1; putin[i]!='\0'; i++)
    {
      putout[k++]=putin[i];
    }
    
    
    if (putout[1]=='\0')
    {
      printf("%c",putout[0]);
    }
    else
    {
      printf("%c",putout[0]);
    printf(".");}
  for ( i = 1; putout[i]!='\0'; i++)
  {
    printf("%c",putout[i]);
  }
  printf("e-");
  printf("%d",e);
    
  }




     return 0;

 }
