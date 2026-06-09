#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char num[1000];
    char result[1000];
    gets(num); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings with modern compilers.]
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
      result[j++]=num[x+1]; // @@ [This accesses num[x+1], which skips the first non-zero digit after leading zeros; it should be num[x] instead. Also, 'result' is not null-terminated, leading to undefined behavior in printf.]
    }
    if(result[0]!=0) // @@ [This checks if result[0] is non-zero, but 'result' may be uninitialized or not null-terminated; also, condition should check j>0 or proper string state.]
    printf("%c.%se-%d",num[count+2],result,count+1); // @@ [Index 'count+2' may go out of bounds if all digits after decimal are zero or input is malformed. Also, 'result' lacks null termination.]
    else
    printf("%ce-%d",num[count+2],count+1); // @@ [Same out-of-bounds risk with 'count+2'; also fails to handle case where there are no digits after leading zeros.]
    }
    else
    {
        for(int x=1;x<len;x++)
        {
            if(num[x]!='.')
            result[j++]=num[x];
            
        }
    printf("%c.%se%d",num[0],result,i-1);} // @@ ['result' is not null-terminated, causing undefined behavior when passed to printf as a string.]

    return 0;
}