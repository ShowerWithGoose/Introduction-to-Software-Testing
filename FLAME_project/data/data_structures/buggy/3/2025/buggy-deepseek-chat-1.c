#include <stdio.h>
#include <string.h>
char fu[1000];
int main()
{
  gets(fu);
  int len=strlen(fu);
  int flag1=0,flag2=0;
  int fir,las,point;
  for(int i=0;i<len;i++)
  {
      if((fu[i]!='0'&&fu[i]!='.')&&flag1==0)
      {
          fir=i;
          flag1=1;
    }
    if( fu[i]=='.' )
    {
        point=i;
    }
  }
  for(int i=len-1;i>=0;i--)
  {
      if((fu[i]!='0'&&fu[i]!='.')&&flag2==0)
      {
          las=i;
          flag2=1;
    }
  }
  if(fir==las)
  {
      printf("%c",fu[fir]);
      printf("e%d",point-fir);
  }
  else if(fir>point)
  {
      printf("%c.",fu[fir]);
      for(int i=fir;i<=las;i++)
      {
          printf("%c",fu[i]);
    }
    printf("e%d",point-fir); // @@ The exponent calculation is incorrect. For numbers less than 1 (fir > point), the exponent should be point - fir + 1, not point - fir. For example, input 0.00000009123456789012: fir=8 (digit '9'), point=1, so exponent should be 1-8+1=-6, but code gives 1-8=-7, leading to wrong output.
  }
  else 
  {
      printf("%c",fu[0]);
    printf(".");
    for(int i=1;i<point;i++)
    {
        printf("%c",fu[i]);
    }
    for(int i=point+1;i<=las;i++)
    {
        printf("%c",fu[i]);
    }
    printf("e%d",point-fir-1); // @@ The exponent calculation is incorrect. For numbers greater than or equal to 1 (fir < point), the exponent should be point - fir - 1, but the base output is wrong because it always starts with fu[0] instead of fu[fir]. For example, input 123.456: fir=0, point=3, exponent should be 3-0-1=2, but base should be "1.23456", not "1.23.456". The loop logic incorrectly includes the decimal point and all digits before it.
  }
  return 0;
}