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
      if(num[x]=='0') // @@ [This count should only count leading zeros before the first non-zero digit. Currently it increments for all zeros, causing incorrect exponent and first digit index.]
      count++;
      else
      result[j++]=num[x+1]; // @@ [This copies the digit after the current non-zero digit, but when the current digit is the first non-zero, it misses it. Also, it may copy out-of-bounds when x==len-1, but that is okay. However, the logic of counting zeros is broken.]
    }
    if(result[0]!=0)
    printf("%c.%se-%d",num[count+2],result,count+1);
    else
    printf("%ce-%d",num[count+2],count+1);
    }
    else
    {
        for(int x=1;x<len;x++)
        {
            if(num[x]!='.')
            result[j++]=num[x];
            
        }
    printf("%c.%se%d",num[0],result,i-1); // @@ [The result array is not null-terminated after copying digits. Using %s with result leads to undefined behavior.]
    }

    return 0;
}