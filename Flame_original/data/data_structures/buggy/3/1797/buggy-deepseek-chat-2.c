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
      result[j++]=num[x+1]; // @@ [Error: This line incorrectly skips the current non-zero digit and copies the next character instead. It should copy num[x] to result, not num[x+1]. Also, the loop logic for handling leading zeros after the decimal point is flawed.]
    }
    if(result[0]!=0) // @@ [Error: This condition checks if the first character of result is not the null character '\0', but it compares to integer 0 instead of character '0'. It should be result[0]!='\0' or result[0]!=0 (though 0 is equivalent to '\0', the intent is to check for a non-null character, but the logic is still wrong because result may not be properly null-terminated.]
    printf("%c.%se-%d",num[count+2],result,count+1); // @@ [Error: The index num[count+2] is incorrect; it should be num[count+2] is the first non-zero digit after the decimal point, but the loop increments count for each '0' starting from index 2, so the first non-zero digit is at index count+2. However, the format specifier %s for result is wrong because result is not null-terminated and contains only one character. Also, the exponent should be count+1, but the base representation is incorrect.]
    else
    printf("%ce-%d",num[count+2],count+1); // @@ [Error: This prints only one digit without a decimal point, but the problem requires the base to have one digit before and after the decimal point if it's a decimal. Also, the exponent should be count+1, but the base is missing the decimal part.]
    }
    else
    {
        for(int x=1;x<len;x++)
        {
            if(num[x]!='.')
            result[j++]=num[x];
            
        }
    printf("%c.%se%d",num[0],result,i-1);} // @@ [Error: result is not null-terminated, so using %s will cause undefined behavior. Also, the exponent should be i-1, but the base representation may have trailing zeros if the original number had them, which violates the problem's constraint that there are no trailing zeros after the decimal point.]

    return 0;
}