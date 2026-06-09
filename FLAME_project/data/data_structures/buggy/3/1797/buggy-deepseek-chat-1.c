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
      result[j++]=num[x+1]; // @@ Error: This line incorrectly skips the first non-zero digit and starts from the next character, causing the output to miss the first significant digit. It should be `result[j++]=num[x];` to capture the non-zero digit itself.
    }
    if(result[0]!=0)
    printf("%c.%se-%d",num[count+2],result,count+1); // @@ Error: `num[count+2]` is incorrect; it should be `num[count+2]` only if count+2 points to the first non-zero digit, but the logic is flawed. The correct base digit should be `num[count+2]` only if the loop correctly identifies the first non-zero digit, but due to the previous error, this indexing is off. Additionally, `result` may contain extra characters or be empty, leading to wrong output.
    else
    printf("%ce-%d",num[count+2],count+1); // @@ Error: Same indexing issue as above; `num[count+2]` may not be the correct first non-zero digit. Also, this branch assumes no decimal part, but the logic for determining when to use this is incorrect.
    }
    else
    {
        for(int x=1;x<len;x++)
        {
            if(num[x]!='.')
            result[j++]=num[x];
            
        }
    printf("%c.%se%d",num[0],result,i-1);} // @@ Error: For numbers with more than one digit before the decimal point, this prints the first digit, a decimal point, and then all remaining digits (including those before the original decimal point), which is incorrect. It should only include digits after the decimal point in the base.

    return 0;
}