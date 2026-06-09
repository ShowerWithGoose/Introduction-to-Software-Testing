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
    if((i+1)==aftlen)printf("%ce-%d",aftPoint[i],aftlen); // @@ [Error: The exponent should be i+1 (the number of leading zeros plus one), not aftlen. For example, input "0.001" should output "1e-3", but this prints "1e-3" only if aftlen=3 and i=2, which happens to work; however, for "0.0001" (aftlen=4, i=3) it prints "1e-4" which is correct, but the logic is fragile. More critically, for "0.0" (aftlen=1, i=0) it prints "0e-1" instead of "0e0" because the condition (i+1)==aftlen is true but the exponent should be 0. The correct exponent is i+1, but the reference program uses i-1 for the case where input[0]=='0' and input[1]=='.', so the exponent calculation is inconsistent with the problem specification.]
    else printf("%c.%se-%d",aftPoint[i],aftPoint+i+1,aftlen); // @@ [Error: The exponent should be i+1 (the number of leading zeros plus one), not aftlen. For example, input "0.0012" should output "1.2e-3", but this prints "1.2e-4" because aftlen=4, while the correct exponent is i+1=3. The reference program uses i-1 for the exponent in this case, which corresponds to the number of leading zeros after the decimal point.]
}

else if(prePoint[0]!='0'&&prelen == 1) printf("%c.%se0",prePoint[0],aftPoint); // @@ [Error: When the number has only one digit before the decimal point and it's non-zero, the output should be just that digit followed by "e0" if there are no digits after the decimal point, or the digit, a decimal point, and the digits after the decimal point followed by "e0". However, this always prints a decimal point even if aftPoint is empty (e.g., input "5" would output "5.e0" instead of "5e0"). The problem states: "If it’s an integer, it contains only one significant digit without a decimal point." So when aftlen is 0, no decimal point should be printed.]

else if(prePoint[0]!='0'&&prelen != 1)printf("%c.%s%se%d",prePoint[0],prePoint+1,aftPoint,prelen-1); // @@ [Error: This concatenates prePoint+1 and aftPoint without a decimal point between them, but the base should have exactly one digit before the decimal point and the remaining digits after. For example, input "123.45" should output "1.2345e2", but this prints "1.2345e2" because prePoint+1 is "23" and aftPoint is "45", so "%s%s" gives "2345", which is correct. However, if aftPoint is empty (e.g., input "123"), this prints "1.23e2" instead of "1.23e2"? Actually, for "123", prePoint="123", aftPoint="", so it prints "1.23e2" which is "1.23e2" — but the problem expects "1.23e2"? Wait, "123" in scientific notation is "1.23e2", but the problem says "If it’s an integer, it contains only one significant digit without a decimal point." So "123" should be "1.23e2"? No, "123" is not an integer in the sense of having no decimal point in input; it has no decimal point, but the problem says "The input data contains no sign, has digits before and after the decimal point" — so input always has a decimal point. Thus, this case is fine. But the error is that when aftPoint is empty, the output should not have a trailing decimal point. For example, input "100." (if allowed) would output "1.00e2" but the problem says no trailing zeros, so this case may not occur. However, the main error is in the exponent calculation for the first case.]
    return 0;
}