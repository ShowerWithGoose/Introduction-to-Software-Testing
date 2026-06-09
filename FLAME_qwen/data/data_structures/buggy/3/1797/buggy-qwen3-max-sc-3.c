#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char num[1000];
    char result[1000];
    gets(num); // @@ [Using gets() is unsafe and deprecated; may cause compilation error with modern compilers that remove gets()]
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
      result[j++]=num[x+1]; // @@ [Accessing num[x+1] may go out of bounds when x == len-1]
    }
    if(result[0]!=0) // @@ [result[0] is a char; comparing to integer 0 is incorrect. Should check '\0' or use j>0]
    printf("%c.%se-%d",num[count+2],result,count+1); // @@ [num[count+2] may be out of bounds if count+2 >= len]
    else
    printf("%ce-%d",num[count+2],count+1); // @@ [num[count+2] may be out of bounds if count+2 >= len]
    }
    else
    {
        for(int x=1;x<len;x++)
        {
            if(num[x]!='.')
            result[j++]=num[x];
            
        }
    printf("%c.%se%d",num[0],result,i-1);} // @@ [result is not null-terminated, so printing it as string leads to undefined behavior]

    return 0;
}