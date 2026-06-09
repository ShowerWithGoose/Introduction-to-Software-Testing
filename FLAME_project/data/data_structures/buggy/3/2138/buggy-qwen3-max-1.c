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
   for(j = 0;str[i+1]!='\0';j++,i++)aftPoint[j] = str[i+1]; // @@ [The loop condition and increment are flawed: 'i' is incremented inside the loop, but the condition checks str[i+1] which may go out of bounds. Also, this incorrectly copies characters because 'i' is being modified while used as an index for str.]
   aftPoint[j] = '\0';

    prelen = strlen(prePoint);
    aftlen = strlen(aftPoint);

if(prePoint[0] == '0'){
    for(i = 0;aftPoint[i]=='0';i++);
    if((i+1)==aftlen)printf("%ce-%d",aftPoint[i],aftlen); // @@ [The exponent should be -(i+1), not -aftlen. For input "0.00000009...", there are 7 leading zeros after decimal before '9', so exponent is -8, but code uses aftlen (which is total digits after decimal) leading to wrong exponent.]
    else printf("%c.%se-%d",aftPoint[i],aftPoint+i+1,aftlen); // @@ [Same error: exponent should be -(i+1), not -aftlen. Using aftlen gives -20 instead of -8 for the test case.]
}

else if(prePoint[0]!='0'&&prelen == 1) printf("%c.%se0",prePoint[0],aftPoint);

else if(prePoint[0]!='0'&&prelen != 1)printf("%c.%s%se%d",prePoint[0],prePoint+1,aftPoint,prelen-1);
    return 0;
}