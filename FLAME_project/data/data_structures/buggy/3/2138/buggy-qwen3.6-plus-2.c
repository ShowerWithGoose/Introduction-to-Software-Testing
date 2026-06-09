#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str[105];
    char prePoint[100] = {0},aftPoint[100]={0};
    int i=0,j = 0;
    int prelen,aftlen;

   scanf("%s",str);

   for(i = 0;str[i]!='.';i++)prePoint[i] = str[i];
    prePoint[i] = '\0';
   for(j = 0;str[i+1]!='\0';j++,i++)aftPoint[j] = str[i+1];
   aftPoint[j] = '\0';

    prelen = strlen(prePoint);
    aftlen = strlen(aftPoint);

if(prePoint[0] == '0'){
    for(i = 0;aftPoint[i]=='0';i++);
    if((i+1)==aftlen)printf("%ce-%d",aftPoint[i],aftlen); // @@ The exponent calculation is incorrect. It uses the total length of the fractional part instead of the position of the first significant digit. For 0.00...09..., the exponent should be -(number of leading zeros + 1). Here it prints -aftlen which is wrong. It should be -(i+1).
    else printf("%c.%se-%d",aftPoint[i],aftPoint+i+1,aftlen); // @@ The exponent calculation is incorrect. Similar to the previous line, it uses aftlen instead of the correct exponent which is -(i+1). The position of the decimal point shifts based on how many zeros were skipped.
}

else if(prePoint[0]!='0'&&prelen == 1) printf("%c.%se0",prePoint[0],aftPoint);

else if(prePoint[0]!='0'&&prelen != 1)printf("%c.%s%se%d",prePoint[0],prePoint+1,aftPoint,prelen-1);
    return 0;
}