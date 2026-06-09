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
   for(j = 0;str[i+1]!='\0';j++,i++)aftPoint[j] = str[i+1]; // @@ [The loop condition uses `str[i+1]!='\0'` but `i` is being incremented inside the loop, which may cause reading beyond the string boundary or skipping characters incorrectly. Also, after the first loop, `i` points to '.', so `str[i+1]` is the first digit after decimal. However, in the loop body, `i` is incremented per iteration, so `str[i+1]` becomes `str[(initial i + j) + 1]`, which eventually accesses out-of-bound memory when nearing the end. This leads to undefined behavior.]

   aftPoint[j] = '\0';

    prelen = strlen(prePoint);
    aftlen = strlen(aftPoint);

if(prePoint[0] == '0'){
    for(i = 0;aftPoint[i]=='0';i++);
    if((i+1)==aftlen)printf("%ce-%d",aftPoint[i],aftlen); // @@ [The exponent should be `i+1`, not `aftlen`. For example, input "0.001" should give exponent -3, but `aftlen=3`, and `i=2`, so it prints e-3 correctly only by coincidence. However, for "0.010", which shouldn't occur per problem (no trailing zeros), but more critically, for "0.0001", `aftlen=4`, `i=3`, and `(i+1)==aftlen` is true, so it prints e-4, which is correct. But the real issue is that the exponent should be `i+1`, not `aftlen`. However, the bigger flaw is in the previous line's logic: the exponent for "0.001" is -3, which equals -(i+1). So it should be `i+1`, but here it's printing `aftlen`, which only matches when all digits after leading zeros are consumed. This is incorrect in general. Also, note that the problem states there are no trailing zeros, so `aftPoint` has no trailing zeros, but the exponent calculation is still wrong: it should be `i+1`, not `aftlen`.]
    else printf("%c.%se-%d",aftPoint[i],aftPoint+i+1,aftlen); // @@ [Same error: exponent should be `i+1`, not `aftlen`.]
}

else if(prePoint[0]!='0'&&prelen == 1) printf("%c.%se0",prePoint[0],aftPoint);

else if(prePoint[0]!='0'&&prelen != 1)printf("%c.%s%se%d",prePoint[0],prePoint+1,aftPoint,prelen-1); // @@ [This prints the base as `X.YZeN` where YZ is the rest of prePoint and aftPoint concatenated. However, scientific notation requires only one non-zero digit before the decimal, then the rest of significant digits after. But this concatenates prePoint+1 and aftPoint without removing any potential trailing zeros (though problem says none exist), but more importantly, the format should be one digit, then decimal, then all remaining significant digits. However, the bigger issue is that if `aftPoint` is empty (e.g., input "123."), the program may output "1.23e2" correctly, but if input has no fractional part, the original input format guarantees digits before and after decimal, so maybe not. But the critical error is in the zero case exponent calculation.]
    return 0;
}