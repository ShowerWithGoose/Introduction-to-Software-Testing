#include <stdio.h>
#include <string.h>
char fu[1000];
int main()
{
  gets(fu); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors with modern compilers.]
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
      printf("e%d",point-fir); // @@ [If the input is like "0.005", 'fir' will be at '5', but 'point' is before 'fir', so 'point - fir' is negative, but this branch assumes only one significant digit and may miscompute exponent when the number is less than 1 and starts with zero. However, the primary compilation error is due to 'gets'.]
  }
  else if(fir>point)
  {
      printf("%c.",fu[fir]);
      for(int i=fir;i<=las;i++)
      {
          printf("%c",fu[i]); // @@ [This loop prints from 'fir' to 'las' inclusive, but it should skip the decimal point if present in that range. Also, it duplicates the first digit because 'fir' is printed before the loop and again as the first iteration.]
    }
    printf("e%d",point-fir); 
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
    printf("e%d",point-fir-1); // @@ [The exponent calculation is incorrect in cases where leading zeros exist before the first non-zero digit (e.g., "0.00123"). The exponent should be -(number of leading zeros after decimal + 1), but this formula doesn't account for that correctly. However, the immediate cause of compilation failure is 'gets'.]
  }
  return 0;
}