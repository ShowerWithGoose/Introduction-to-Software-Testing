#include <stdio.h>
#include <string.h>
char fu[1000];
int main()
{
  gets(fu); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings depending on compiler settings.]
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
      printf("e%d",point-fir); // @@ [Incorrect exponent calculation when the number has only one significant digit; does not account for cases where the decimal point is before or after the digit correctly.]
  }
  else if(fir>point)
  {
      printf("%c.",fu[fir]);
      for(int i=fir;i<=las;i++)
      {
          printf("%c",fu[i]); // @@ [This loop prints the first digit twice because it starts at 'fir', which was already printed before the decimal point.]
    }
    printf("e%d",point-fir); // @@ [Exponent sign and value are incorrect when the first significant digit is after the decimal point (e.g., 0.00123). Should be negative.]
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
    printf("e%d",point-fir-1); // @@ [Exponent calculation is incorrect in general; logic does not properly handle all cases of scientific notation conversion, especially when leading zeros exist before the first significant digit.]
  }
  return 0;
}