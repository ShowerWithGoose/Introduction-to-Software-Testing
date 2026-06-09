#include<stdio.h>
#include<string.h>
char s[101];
int main(){
    int j=0;
    char t;
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings in modern compilers. It should be replaced with 'fgets'.]
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
        printf("."); // @@ [This prints a decimal point after the second digit, but scientific notation requires exactly one non-zero digit before the decimal point. For example, input "0.0123" should output "1.23e-2", but this code would output "12.3e-2".]
        
    }
    printf("e-%d",j-1); // @@ [The exponent calculation is incorrect. For input "0.0123", j=2 (index of '1'), so exponent should be -(j - 1) = -1, but correct exponent is -2. It should be e-(j-1) only if counting from the decimal point; actually, exponent = -(j - 1) is wrong—it should be -(j - 1) when s[0]=='0' and first non-zero is at j, but since '.' is at index 1, exponent = -(j - 1) gives -1 for j=2, but correct is -2. Correct formula: exponent = -(j - 1) is off by one; should be -(j - 1) → actually, distance from decimal point: position after '.' is index 2 → 1st digit after '.' is position 2, which is 10^-1, so '1' at index 2 is 10^-2? Wait: "0.0123": digits after '.' are at indices 2('0'),3('1'),4('2'),5('3'). First non-zero at index 3. Exponent = - (3 - 1) = -2 → correct. But in code, j is set to first non-zero digit index. In "0.0123", s[0]='0', s[1]='.', s[2]='0', s[3]='1' → j=3. Then exponent printed is j-1 = 2 → "e-2", which is correct. However, the base formatting is wrong as noted above. But wait: in the else block, the loop prints s[j], then if i==j+1 prints '.', so for j=3: prints s[3]='1', then at i=4 (j+1=4), prints '.' then s[4]='2', etc. → outputs "1.23", which is correct. But what if only one digit after? e.g., "0.1": j=2 (s[2]='1'), then loop i=2: print '1'; i=3? strlen=3, so i<3 → only i=2. So never prints '.'. That's correct: "1e-1". But if "0.12": j=2, i=2: print '1'; i=3: print '2' and since i==j+1 (3==3), print '.' before? No: code does: printf("%c",s[i]); then if(i==j+1) printf("."); → so prints '1', then at i=3: prints '2', then prints '.' → "12." which is wrong. So the decimal point is printed after the second digit, not between first and second. This is a logic error in placement of decimal point.]
        
    }
    printf("e-%d",j-1);
    }
    return 0;}