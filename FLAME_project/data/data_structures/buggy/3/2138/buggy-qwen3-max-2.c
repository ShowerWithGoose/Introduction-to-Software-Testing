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
   for(j = 0;str[i+1]!='\0';j++,i++)aftPoint[j] = str[i+1]; // @@ [The loop condition and increment are flawed: 'i' is incremented inside the loop, but the condition uses 'str[i+1]' which may go out of bounds or skip characters. Also, after the first loop, 'i' points to '.', so 'i+1' is correct initially, but incrementing 'i' in the second loop causes misalignment.]
   aftPoint[j] = '\0';

    prelen = strlen(prePoint);
    aftlen = strlen(aftPoint);

if(prePoint[0] == '0'){
    for(i = 0;aftPoint[i]=='0';i++);
    if((i+1)==aftlen)printf("%ce-%d",aftPoint[i],aftlen); // @@ [The exponent should be -(i+1), not -aftlen. For input "0.00000009123...", leading zeros count is 7, so exponent is -8, but code uses aftlen (14) leading to e-14 or similar. In this case, it prints e-14 instead of e-8.]
    else printf("%c.%se-%d",aftPoint[i],aftPoint+i+1,aftlen); // @@ [Same error: exponent should be -(i+1), not -aftlen. For the given test case, i=7 (index of '9'), so exponent should be -8, but aftlen=14 leads to e-14. However, observed output is e-20, suggesting additional miscalculation possibly from string parsing errors above. But primary logic error is using aftlen instead of i+1.]
}

else if(prePoint[0]!='0'&&prelen == 1) printf("%c.%se0",prePoint[0],aftPoint);

else if(prePoint[0]!='0'&&prelen != 1)printf("%c.%s%se%d",prePoint[0],prePoint+1,aftPoint,prelen-1);
    return 0;
}