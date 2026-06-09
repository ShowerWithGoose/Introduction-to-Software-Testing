#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char num[1000];
    char result[1000];
    gets(num);
    int len =strlen(num);
    int i=0,j=0,count=0;
    for(i=0;num[i]!='.';i++)
    {

    }
    if(i==1&&num[0]!='0')
    {printf("%se0",num);
    }
    else if(i==1&&num[0]=='0')
    {
    for(int x=2;x<len;x++)
    {
      if(num[x]=='0')
      count++;
      else
      result[j++]=num[x+1]; // @@ [Off-by-one error: should store num[x], not num[x+1]; this skips the first non-zero digit and shifts all subsequent digits left, causing incorrect mantissa]
    }
    if(result[0]!=0) // @@ [Incorrect condition: result[0] is a char, comparing to integer 0; should check j>0 or result[0]!='\0']
    printf("%c.%se-%d",num[count+2],result,count+1); // @@ [Wrong index: num[count+2] skips the first non-zero digit; should be num[count+2] only if loop stored correctly, but due to earlier off-by-one, this points to wrong digit]
    else
    printf("%ce-%d",num[count+2],count+1); // @@ [Same indexing error: num[count+2] is incorrect; should be the first non-zero digit at position count+2 in original string, but due to logic flaw, it's misaligned]
    }
    else
    {
        for(int x=1;x<len;x++)
        {
            if(num[x]!='.')
            result[j++]=num[x];
            
        }
    printf("%c.%se%d",num[0],result,i-1);}

    return 0;
}