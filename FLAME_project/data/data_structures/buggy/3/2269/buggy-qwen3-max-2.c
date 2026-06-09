#include<stdio.h>
#include<string.h>
char s[101];
int main(){
    int j=0;
    char t;
    gets(s);
    if(s[0]!='0'){

    for(int i=0;i<strlen(s);i++){
        
        if(s[i]=='.')
        {
        j=i;break;}
        
    }
        for(int i=0;i<j;i++)
    {
        if(i==1)
        printf("."); // @@ [This prints a decimal point after the second digit, but scientific notation requires only one non-zero digit before the decimal point. For numbers >= 1, it should print only the first digit, then a '.', then the rest.]
        printf("%c",s[i]);
    }
    
        if(j==1)
        printf("."); // @@ [This condition handles the case where there's only one digit before the decimal (e.g., "5.123"), but it's redundant and misplaced. The correct base should always have exactly one digit before the decimal point, so this logic is flawed.]
        for(int i=j+1;i<strlen(s);i++)
    {
        printf("%c",s[i]);
    }
        printf("e%d",j-1); // @@ [The exponent calculation is correct for numbers >= 1, but the base formatting is wrong due to earlier errors.]
    
}
    else
    {
        for(int i=0;i<strlen(s);i++){
        
        if(s[i]!='0'&&s[i]!='.')
        {
        j=i;break;}
        
    }
    
    for(int i=j;i<strlen(s);i++)
    {
        printf("%c",s[i]);
        if(i==j+1)
        printf("."); // @@ [This inserts the decimal point after the second significant digit, but scientific notation requires it after the first. For example, input "0.0000000912..." should become "9.123...", not "91.234...".]
        
    }
    printf("e-%d",j-1); // @@ [The exponent is calculated as -(j-1), but since j is the index of the first non-zero digit (e.g., '9' at index 8 in "0.00000009..."), the correct exponent should be -(j - 1) only if we count from the decimal point. Actually, for "0.00000009", the exponent is -8, and j=8 (0-indexed), so exponent = -(j - 1) = -7, which is wrong. It should be -(j - 1) only if j counts digits after the decimal. Correct exponent is -(j - 1) when s[0]=='0' and s[1]=='.', so exponent = -(j - 1) => but j starts at 0, so for "0.00000009", j=8, exponent should be -8, so it should be -(j - 1) is -7 → wrong. Should be -(j - 1) only if we consider position after decimal. Actually, number of leading zeros after decimal is (j - 2), so exponent = -(j - 1). Wait: "0." then 7 zeros then '9' → total shift = 8 → exponent = -8. Index of '9' is 8 (s[0]='0', s[1]='.', s[2]='0', ..., s[8]='9'), so exponent = -(8 - 1) = -7 → incorrect. Should be exponent = -(j - 1) is wrong; correct is exponent = -(j - 1) only if j is position after decimal. Actually, exponent = -(number of places moved) = -( (j - 1) )? Let's see: from 0.00000009 to 9e-8, we move 8 places right → exponent -8. The '9' is at index 8, so number of digits from decimal point (index 1) to '9' is (8 - 1) = 7, but we need to move 8 places. So exponent = -(j - 1) gives -7, but should be -8. Therefore, exponent should be -(j - 1) is incorrect; it should be -(j - 1) only if we count differently. Actually, correct exponent is -(j - 1) when j is index of first non-zero, but in "0.00000009", j=8, so exponent = -(8 - 1) = -7, but expected is -8. So error here: should be -(j - 1) is wrong; should be -(j - 1) → no, let's recount: positions: 0:'0',1:'.',2:'0',3:'0',4:'0',5:'0',6:'0',7:'0',8:'0',9:'9' — wait, input is "0.00000009123456789012", which has 7 zeros after decimal before '9'? Let's count: "0." + "0000000" (7 zeros) + "9..." → total 8 characters after '0.' before '9'? No: "0.00000009" → after decimal: 0(1),0(2),0(3),0(4),0(5),0(6),0(7),9(8) → so '9' is at index 9 (0-based: s[0]='0', s[1]='.', s[2]='0', ..., s[9]='9'). Then j=9. Exponent should be -8. So -(j - 1) = -(9 - 1) = -8 → correct. But in the test case input "0.00000009123456789012", how many zeros after decimal before '9'? "0." followed by 7 zeros then '9' → that's 8 digits after decimal before '9'? No: "0000000" is 7 zeros, so '9' is the 8th digit after decimal → index = 1 (for '.') + 8 = 9. So j=9, exponent = -(9 - 1) = -8 → correct. So why output is e-8? Then why is the base wrong? Because the base prints s[j] and s[j+1] then puts '.' after second digit. So for j=9, it prints s[9]='9', then s[10]='1', then puts '.' → "91." then rest → "91.234...e-8", but should be "9.123...e-8". So the exponent calculation is actually correct, but the base formatting is wrong because it prints two digits before the decimal. The error is in the placement of the decimal point: it should be after the first digit, not the second. So the line "if(i==j+1) printf(".");" causes the decimal to be printed after the second digit (i=j+1 means after printing s[j] and s[j+1], then put '.'), which is wrong. It should be after the first digit, i.e., after printing s[j], then print '.', then the rest. So the error is in the decimal point insertion logic in the else block. Also, in the if block (for numbers >=1), it prints multiple digits before decimal and inserts '.' at i==1, which is also wrong.]
    }
    return 0;}