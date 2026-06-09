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
      printf("%c",fu[0]); // @@ Error: When the first digit before the decimal point is non-zero, this always prints the first character, but if the number has leading zeros (e.g., "0.00123"), fu[0] is '0', which is incorrect. Should print fu[fir] instead.
    printf(".");
    for(int i=1;i<point;i++)
    {
        printf("%c",fu[i]);
    }
    for(int i=point+1;i<=las;i++)
    {
        printf("%c",fu[i]);
    }
    printf("e%d",point-fir-1); // @@ Error: The exponent calculation is incorrect. For numbers like "0.00123", point-fir-1 gives -4, but the correct exponent should be -3 (since 0.00123 = 1.23e-3). The exponent should be point-fir (without subtracting 1).
  }
  return 0;
}