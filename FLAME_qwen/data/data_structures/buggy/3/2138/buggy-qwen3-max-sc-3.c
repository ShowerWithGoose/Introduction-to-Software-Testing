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
   for(j = 0;str[i+1]!='\0';j++,i++)aftPoint[j] = str[i+1]; @@ [The loop condition uses 'str[i+1]' but 'i' is being incremented inside the loop, which causes skipping of characters and potential out-of-bound access. Also, after the first loop, 'i' points to '.', so 'str[i+1]' is correct initially, but incrementing 'i' in the loop makes it skip every other character.]
   aftPoint[j] = '\0';

    prelen = strlen(prePoint);
    aftlen = strlen(aftPoint);

if(prePoint[0] == '0'){
    for(i = 0;aftPoint[i]=='0';i++);
    if((i+1)==aftlen)printf("%ce-%d",aftPoint[i],aftlen); @@ [The exponent should be 'i+1' (number of leading zeros + 1), not 'aftlen'. For example, input "0.001" should give exponent -3, but this prints -3 only if aftlen=3 and i=2, then (i+1)=3 equals aftlen=3, but exponent should be -(i+1) = -3, yet code uses 'aftlen' which coincidentally may match but fails generally. More critically, exponent value is wrong: it should be -(i+1), not -aftlen.]
    else printf("%c.%se-%d",aftPoint[i],aftPoint+i+1,aftlen); @@ [Same issue: exponent should be -(i+1), not -aftlen.]
}

else if(prePoint[0]!='0'&&prelen == 1) printf("%c.%se0",prePoint[0],aftPoint);

else if(prePoint[0]!='0'&&prelen != 1)printf("%c.%s%se%d",prePoint[0],prePoint+1,aftPoint,prelen-1); @@ [This prints all digits after the first from prePoint and then all of aftPoint, but scientific notation should only have one digit before decimal and the rest as fractional part without reintroducing original integer digits. For example, "123.45" becomes "1.2345e2", but this prints "1.2345e2" correctly? Wait: prePoint="123", so prePoint+1="23", aftPoint="45", so output is "1.2345e2" — that seems correct. However, if aftPoint is empty (e.g., "123."), this may print trailing decimal or extra digits. But problem states there are digits after decimal. Still, the bigger issue is in the zero case exponent calculation.]
    return 0;
}