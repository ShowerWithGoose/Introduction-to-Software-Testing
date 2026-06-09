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
   for(j = 0;str[i+1]!='\0';j++,i++)aftPoint[j] = str[i+1]; // @@ [The loop condition uses `str[i+1]!='\0'` but `i` is incremented inside the loop, causing `i` to go out of bounds and potentially skip or misread characters. Also, after the first loop, `i` points to '.', so `str[i+1]` is correct initially, but incrementing `i` in the loop body leads to reading `str[i+2]`, `str[i+3]`, etc., which is incorrect indexing.]

   aftPoint[j] = '\0';

    prelen = strlen(prePoint);
    aftlen = strlen(aftPoint);

if(prePoint[0] == '0'){
    for(i = 0;aftPoint[i]=='0';i++);
    if((i+1)==aftlen)printf("%ce-%d",aftPoint[i],aftlen); // @@ [The exponent should be `i+1` (number of leading zeros plus one), not `aftlen`. For example, input "0.001" should give exponent -3, but `aftlen=3` would give -3 only by coincidence; for "0.0012", `aftlen=4` but exponent should be -3, not -4.]
    else printf("%c.%se-%d",aftPoint[i],aftPoint+i+1,aftlen); // @@ [Same error: exponent should be `i+1`, not `aftlen`.]
}

else if(prePoint[0]!='0'&&prelen == 1) printf("%c.%se0",prePoint[0],aftPoint);

else if(prePoint[0]!='0'&&prelen != 1)printf("%c.%s%se%d",prePoint[0],prePoint+1,aftPoint,prelen-1); // @@ [When combining prePoint+1 and aftPoint, there's no check for trailing zeros in aftPoint. The problem states there are no trailing zeros after decimal in input, but when moving decimal point right, the combined fractional part may include digits that should not have trailing zeros—but more critically, the format requires only one digit before decimal and then significant digits after without trailing zeros. However, the bigger issue is that this prints all of prePoint+1 followed by all of aftPoint, which is correct per input spec, but the exponent calculation `prelen-1` is correct. However, note that if aftPoint is empty (e.g., input "123."), the code may print extra decimal or malformed output. But the main logical errors are in the zero-leading case exponents.]
    return 0;
}