#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char num[1000];
    char result[1000];
    gets(num); // @@ [Use of unsafe function 'gets' which has been removed from C11 standard; causes compilation error with modern compilers]
    int len =strlen(num);
    int i=0,j=0,count=0;
    for(i=0;num[i]!='.';i++) // @@ [If input has no decimal point, this loop runs past the end of string causing undefined behavior]
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
      result[j++]=num[x+1]; // @@ [Off-by-one error: should be num[x], not num[x+1]; skips first non-zero digit and reads beyond array if x == len-1]
    }
    if(result[0]!=0) // @@ [Incorrect check: should compare with '\0' or use j>0; result[0]!=0 is always true since characters are non-zero ASCII values]
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
    printf("%c.%se%d",num[0],result,i-1);} // @@ [Missing null-termination of result array; passing unterminated string to printf leads to undefined behavior]

    return 0;
}