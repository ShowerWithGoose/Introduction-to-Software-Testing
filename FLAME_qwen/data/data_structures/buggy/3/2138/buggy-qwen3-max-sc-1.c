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
   for(j = 0;str[i+1]!='\0';j++,i++)aftPoint[j] = str[i+1]; @@ [The loop condition uses `str[i+1]!='\0'` but `i` is being incremented inside the loop, which causes skipping of characters and potential out-of-bound access. Also, after the first loop, `i` points to '.', so `str[i+1]` is correct initially, but incrementing `i` in the loop body leads to reading beyond intended positions.]
   aftPoint[j] = '\0';

    prelen = strlen(prePoint);
    aftlen = strlen(aftPoint);

if(prePoint[0] == '0'){
    for(i = 0;aftPoint[i]=='0';i++);
    if((i+1)==aftlen)printf("%ce-%d",aftPoint[i],aftlen); @@ [The exponent should be `i+1`, not `aftlen`. For example, input "0.001" should give exponent -3, but `aftlen=3` and `i=2`, so it prints e-3 correctly only by coincidence. However, for "0.010", which shouldn't occur per problem (no trailing zeros), but more critically, for "0.0001", `aftlen=4`, `i=3`, and `(i+1)==aftlen` is true, so it prints e-4, which is correct. But the real issue is that the exponent should be `i+1`, not `aftlen`. However, the bigger error is in the else branch below.]
    else printf("%c.%se-%d",aftPoint[i],aftPoint+i+1,aftlen); @@ [Exponent should be `i+1`, not `aftlen`. For example, "0.0012" → should be 1.2e-3, but this prints e-4 (since aftlen=4).]
}

else if(prePoint[0]!='0'&&prelen == 1) printf("%c.%se0",prePoint[0],aftPoint);

else if(prePoint[0]!='0'&&prelen != 1)printf("%c.%s%se%d",prePoint[0],prePoint+1,aftPoint,prelen-1); @@ [This prints two parts after the decimal: prePoint+1 and aftPoint concatenated, but scientific notation should have only one digit before decimal and the rest (including original fractional part) after. However, the format "%c.%s%se%d" will output something like "1.23456e2" for "123.456", which is correct. BUT: if aftPoint is empty (e.g., input "123."), the program may output extra %s as empty, which is okay. However, the main logical error is in the zero case exponent calculation. Also, note that the problem states there are digits before and after the decimal point, so we don't have to handle missing parts. However, the critical bug is in the exponent value in the zero-leading case.]
    return 0;
}