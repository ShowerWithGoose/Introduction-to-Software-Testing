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
    printf("e%d",point-fir); 
  }
  else 
  {
      printf("%c",fu[0]); // @@ This line incorrectly prints the first character of the input string, which may be '0' for numbers like 0.000... It should print the first non-zero digit (fu[fir]) instead.
    printf(".");
    for(int i=1;i<point;i++)
    {
        printf("%c",fu[i]); // @@ This loop prints all digits before the decimal point, including leading zeros, which is incorrect. It should only print the significant digits after the first non-zero digit.
    }
    for(int i=point+1;i<=las;i++)
    {
        printf("%c",fu[i]);
    }
    printf("e%d",point-fir-1); // @@ The exponent calculation is incorrect. For numbers like 0.000...xyz, the exponent should be -(point - fir + 1) or similar, not point-fir-1. The current formula gives -8 for the test case, but the correct exponent is -8 (since 0.00000009123456789012 = 9.123456789012e-8, the exponent is -8, but the output shows e-8 which matches, but the base is wrong due to earlier errors).
  }
  return 0;
}