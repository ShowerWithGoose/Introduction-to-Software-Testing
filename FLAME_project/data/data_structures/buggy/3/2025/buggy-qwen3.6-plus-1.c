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
      for(int i=fir;i<=las;i++) // @@ The loop starts from fir, which prints the first significant digit again. It should start from fir+1 to print the remaining digits after the decimal point.
      {
          printf("%c",fu[i]);
    }
    printf("e%d",point-fir); 
  }
  else 
  {
      printf("%c",fu[0]); // @@ For numbers less than 1 (like 0.00...), the base should start with the first non-zero digit (fu[fir]), not fu[0] which is '0'.
    printf(".");
    for(int i=1;i<point;i++) // @@ This loop prints zeros between the initial '0' and the decimal point, which are not part of the significant digits in scientific notation base. The base should only contain significant digits.
    {
        printf("%c",fu[i]);
    }
    for(int i=point+1;i<=las;i++)
    {
        printf("%c",fu[i]);
    }
    printf("e%d",point-fir-1);
  }
  return 0;
}