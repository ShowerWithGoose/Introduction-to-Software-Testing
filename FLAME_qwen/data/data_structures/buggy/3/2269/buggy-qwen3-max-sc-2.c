#include<stdio.h>
#include<string.h>
char s[101];
int main(){
    int j=0;
    char t;
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers.]
    if(s[0]!='0'){

    for(int i=0;i<strlen(s);i++){
        
        if(s[i]=='.')
        {
        j=i;break;}
        
    }
        for(int i=0;i<j;i++)
    {
        if(i==1)
        printf(".");
        printf("%c",s[i]);
    }
    
        if(j==1)
        printf(".");
        for(int i=j+1;i<strlen(s);i++)
    {
        printf("%c",s[i]);
    }
        printf("e%d",j-1);
    
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
        printf(".");
        
    }
    printf("e-%d",j-1); // @@ [The exponent calculation is incorrect. For numbers like "0.00123", the first non-zero digit is at index 4 (s[4]=='1'), so exponent should be -(4 - 1) = -3, but this prints -(4 - 1) = -3 only if j is correctly interpreted. However, j is the index of the first non-zero digit, and the decimal point is at index 1, so exponent should be -(j - 2), not -(j - 1). Also, if input is "0.1", j=2, exponent should be -1, but this outputs e-1 which is correct; however, for "0.01", j=3, outputs e-2 which is correct. Wait—actually, the logic here assumes the decimal point is always at index 1, which is true per problem constraints (input always has digits before and after decimal, and if starts with 0, then it's "0.xxx"). So decimal point is at index 1. Then first non-zero at index j (>=2). Number of places to shift = j - 2 + 1 = j - 1? Actually, 0.001 = 1e-3: decimal at index 1, '1' at index 4 → shift right 3 places → exponent -3. Distance from decimal point: j - 1 - 1 = j - 2? Wait: positions: [0]='0', [1]='.', [2]='0', [3]='0', [4]='1'. To get 1, move decimal from after 0 (position before [2]) to after [4], that's 3 moves → exponent -3. So exponent = -(j - 2). But code uses j-1 → for j=4, prints -3 → which is correct. Because j=4, j-1=3 → e-3. So actually exponent is correct. BUT: what if input is "0.10"? Problem states: "all digits are significant (i.e., there are no trailing zeros after the decimal point)", so "0.10" won't occur. So exponent logic may be okay. However, the bigger issue is formatting of mantissa.]

    } // @@ [The mantissa formatting is incorrect. For example, if input is "0.00123", the code prints "123." instead of "1.23". It prints all digits starting from first non-zero, and inserts a '.' after the second digit (i==j+1). So for j=4 (first non-zero at index 4), it prints s[4]='1', then at i=5 (j+1=5) prints '.', then rest. So output is "1.23" — that seems correct. Wait: loop is for(i=j; i<len; i++){ print s[i]; if(i==j+1) print '.'; } So for "0.00123", j=4, len=7 (assuming "0.00123" is 7 chars). i=4: print '1'; i=5: print '2', then because i==j+1 (5==5), print '.' → so output becomes "12." then '3' → "12.3", which is wrong. It should be "1.23". The '.' is inserted after the second digit, but it should be after the first digit. So condition should be if(i==j) { print first digit; then if more digits, print '.' and rest }. Current logic prints first digit (i=j), then at i=j+1 prints next digit AND a dot → so two digits before dot. This violates the requirement: scientific notation must have one significant digit before decimal. So error in mantissa formatting for numbers < 1.]

    return 0;}