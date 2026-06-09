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
      printf("e%d",point-fir); // @@ [When the number is of the form 0.00...d (single non-zero digit), the exponent should be -(position after decimal - 1). However, point - fir gives a positive value here because fir > point, leading to wrong sign and magnitude.]
  }
  else if(fir>point)
  {
      printf("%c.",fu[fir]);
      for(int i=fir;i<=las;i++)
      {
          printf("%c",fu[i]); // @@ [This loop prints from 'fir' to 'las', but it duplicates the first digit because the first digit was already printed before the decimal point. It should start from fir+1.]
    }
    printf("e%d",point-fir); // @@ [Exponent calculation is incorrect. For numbers >= 1 (like 123.45), exponent should be (number of digits before decimal - 1) = (fir_index_of_first_digit is 0, so exponent = point - 1). But point - fir gives negative when fir > point, which is wrong. Should be fir - 1 or similar.]
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
    printf("e%d",point-fir-1); // @@ [For numbers like 0.0009..., fir is the index of first non-zero digit (e.g., '9'), which is > point. So this branch (fir <= point) is not taken for such inputs. But in cases where input starts with non-zero (e.g., 1.23), this may work. However, the main issue is that this branch assumes fu[0] is significant, but for inputs like "0.123", fu[0] is '0', which should not appear in scientific notation base. The base must start with the first non-zero digit.]
  }
  return 0;
}