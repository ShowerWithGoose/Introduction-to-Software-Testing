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
      printf("e%d",point-fir); // @@ [When the number is less than 1 (like 0.000...), the exponent should be negative and calculated as -(fir - point - 1), but this outputs a positive or incorrect exponent. Also, this branch doesn't handle decimal point in output correctly for single-digit case.]
  }
  else if(fir>point)
  {
      printf("%c.",fu[fir]); // @@ [This prints the first significant digit followed by '.', but then the loop below starts from 'fir' again, causing duplication of the first digit (e.g., '9.' becomes '9.9...'). It should start from fir+1.]
      for(int i=fir;i<=las;i++)
      {
          printf("%c",fu[i]); // @@ [This duplicates the first significant digit because it starts at 'fir', which was already printed before the loop. Should start at fir+1.]
    }
    printf("e%d",point-fir); // @@ [Exponent calculation is incorrect for numbers >= 1. For example, "123.45" should give e2, but point-fir = 3-0 = 3, which is wrong. Correct exponent is (point - 1) when fir==0. General formula should be (point - fir - 1) if fir < point, or (fir - 1) if no decimal or fir > point.]
  }
  else 
  {
      printf("%c",fu[0]); // @@ [This assumes the first character is always part of the normalized form, but for numbers like "0.000...", fu[0] is '0', which should not appear in scientific notation base. The base must start with the first non-zero digit.]
    printf(".");
    for(int i=1;i<point;i++)
    {
        printf("%c",fu[i]); // @@ [This prints digits between index 1 and point-1, which are all '0's in cases like "0.000...", but these zeros should not appear in the normalized base. Only the first non-zero digit and subsequent significant digits should be printed.]
    }
    for(int i=point+1;i<=las;i++)
    {
        printf("%c",fu[i]);
    }
    printf("e%d",point-fir-1); // @@ [While this exponent formula is correct for numbers < 1, the base printed above is wrong because it includes leading zeros and omits the first non-zero digit as the leading digit.]
  }
  return 0;
}