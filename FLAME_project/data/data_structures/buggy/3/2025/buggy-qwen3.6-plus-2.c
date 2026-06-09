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
          printf("%c",fu[i]); // @@ [Logic Error: The loop starts from 'fir' (the first significant digit), but since 'fu[fir]' was already printed before the decimal point, this prints the first digit again. It should start from 'fir + 1'.]
    }
    printf("e%d",point-fir); 
  }
  else 
  {
      printf("%c",fu[0]); // @@ [Logic Error: For numbers less than 1 (e.g., 0.00...), the first significant digit is at index 'fir', not necessarily index 0 (which is '0'). It should print 'fu[fir]'.]
    printf(".");
    for(int i=1;i<point;i++) // @@ [Logic Error: This loop prints digits between index 1 and the decimal point. However, for scientific notation of small numbers, we need to print the digits following the first significant digit 'fu[fir]'. The range should be from 'fir + 1' to 'las', skipping the decimal point if encountered, or simply iterating through the significant digits after the first one.]
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