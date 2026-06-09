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
    {
        printf("%se0",num); // @@ This line incorrectly prints the entire original number instead of the proper scientific notation base (e.g., "1.23e0" vs "1.23e0" is okay, but format not guaranteed for all cases; main issue is missing decimal point placement)
    }
    else if(i==1&&num[0]=='0')
    {
        for(int x=2;x<len;x++)
        {
            if(num[x]=='0')
                count++;
            else
                result[j++]=num[x+1]; // @@ This line stores the digit after the first non-zero digit, skipping the first non-zero digit itself, and also causes out-of-bounds access when x = len-1 (since num[x+1] is beyond the string)
        }
        if(result[0]!=0) // @@ This condition should check if any digits were stored (j>0) instead of comparing a character to integer 0
            printf("%c.%se-%d",num[count+2],result,count+1); // @@ The result array is missing the first non-zero digit, leading to an incorrect base
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
        printf("%c.%se%d",num[0],result,i-1);
    }

    return 0;
}