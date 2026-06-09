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
   for(j = 0;str[i+1]!='\0';j++,i++)aftPoint[j] = str[i+1]; @@ [The loop condition uses `str[i+1]` but `i` is being incremented inside the loop, which causes skipping of characters and potential out-of-bound access. Also, after the first loop, `i` points to '.', so `str[i+1]` is correct initially, but incrementing `i` in `j++,i++` makes it skip every other character in the fractional part.]
   aftPoint[j] = '\0';

    prelen = strlen(prePoint);
    aftlen = strlen(aftPoint);

if(prePoint[0] == '0'){
    for(i = 0;aftPoint[i]=='0';i++);
    if((i+1)==aftlen)printf("%ce-%d",aftPoint[i],aftlen); @@ [The exponent should be `i+1`, not `aftlen`. For example, input "0.001" has aftlen=3, but exponent should be -3, which equals -(i+1) where i=2 (index of '1'), so exponent = -(2+1) = -3. But here it prints `aftlen` which is 3, leading to wrong exponent. Also, when there's only one non-zero digit at end, e.g., "0.001", it should print "1e-3", but this prints "1e3".]
    else printf("%c.%se-%d",aftPoint[i],aftPoint+i+1,aftlen); @@ [Same issue: exponent should be `i+1`, not `aftlen`.]
}

else if(prePoint[0]!='0'&&prelen == 1) printf("%c.%se0",prePoint[0],aftPoint);

else if(prePoint[0]!='0'&&prelen != 1)printf("%c.%s%se%d",prePoint[0],prePoint+1,aftPoint,prelen-1); @@ [This prints two parts after the decimal: `prePoint+1` and `aftPoint`, but they should be concatenated without separation. However, the bigger issue is that if `aftPoint` is empty (e.g., input "123."), then `aftPoint` is "", and output becomes "1.23e2" for "123." which is correct, but if input has no fractional part, the original problem states there are digits before and after the decimal point, so maybe not an issue. However, the main error is in exponent calculation for the zero-leading case above.]
    return 0;
}