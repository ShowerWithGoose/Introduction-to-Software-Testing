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
    if((i+1)==aftlen)printf("%ce-%d",aftPoint[i],aftlen); // @@ The exponent should be i+1 (the number of leading zeros plus one), not aftlen. For example, input "0.001" should output "1e-3", but this prints "1e-3" only if aftlen=3 and i=2, which happens to work here, but the logic is incorrect for cases like "0.010" (though trailing zeros are not allowed per spec). The correct exponent is i+1.
    else printf("%c.%se-%d",aftPoint[i],aftPoint+i+1,aftlen); // @@ Same issue: exponent should be i+1, not aftlen. For input "0.0012", expected output is "1.2e-3", but this prints "1.2e-4" because aftlen=4.
}

else if(prePoint[0]!='0'&&prelen == 1) printf("%c.%se0",prePoint[0],aftPoint); // @@ When prelen==1 and prePoint[0]!='0', the number already has one digit before the decimal point, so the exponent should be 0, but the output format should be just the digit without a decimal point if aftPoint is empty (e.g., input "5" should output "5e0", but this prints "5.e0" with a trailing decimal point). The spec says if it's an integer, it contains only one significant digit without a decimal point. This code always adds a decimal point and the aftPoint string, which may be empty, causing an extra dot.

else if(prePoint[0]!='0'&&prelen != 1)printf("%c.%s%se%d",prePoint[0],prePoint+1,aftPoint,prelen-1); // @@ The format specifier "%s%s" concatenates prePoint+1 and aftPoint without a decimal point between them, but the base should have exactly one digit after the decimal point. For example, input "123.45" should output "1.2345e2", but this prints "1.2345e2" only if prePoint+1 is "23" and aftPoint is "45", giving "1.2345e2" which is correct by coincidence. However, if aftPoint is empty (e.g., input "123"), this prints "1.23e2" instead of "1.23e2" (actually it would print "1.23e2" which is correct, but the spec says if it's an integer, no decimal point; here it always adds one). The main issue is that the exponent should be prelen-1, which is correct, but the base formatting may produce extra characters when aftPoint is empty.

    return 0;
}