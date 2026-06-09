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
    for(i=0;num[i]!='.';i++) // @@ [If input has no decimal point, this loop runs past the end of string causing undefined behavior; also may cause infinite loop or segfault]
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
    if(result[0]!=0) // @@ [Incorrect condition: result[0] is a char, should check j>0 or result[0]!='\0'; also result not null-terminated]
    printf("%c.%se-%d",num[count+2],result,count+1); // @@ [num[count+2] may be out of bounds; e.g., if all digits after '.' are zero, count == len-2, then count+2 == len which is '\0']
    else
    printf("%ce-%d",num[count+2],count+1); // @@ [Same out-of-bounds access as above]
    }
    else
    {
        for(int x=1;x<len;x++)
        {
            if(num[x]!='.')
            result[j++]=num[x];
            
        }
    printf("%c.%se%d",num[0],result,i-1);} // @@ [result is not null-terminated, so printf may print garbage; also incorrect exponent calculation]

    return 0;
}