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
        printf("%c",s[i]); // @@ The logic for inserting the decimal point is incorrect. It prints the first significant digit, then the second, and only then inserts a dot. For input 0.00...091..., j points to '9'. The loop prints '9', then '1', then inserts '.', resulting in "91." instead of "9.1". The dot should be inserted after the first significant digit (when i==j).
        if(i==j+1)
        printf(".");
        
    }
    printf("e-%d",j-1); // @@ The exponent calculation is incorrect. For 0.00000009123..., the first non-zero digit '9' is at index 9 (0-indexed: '0','.','0','0','0','0','0','0','0','9'). The exponent should be -(number of zeros after decimal before first sig digit + 1). Here, there are 7 zeros after decimal before '9'. Exponent is -8. j=9. j-1 = 8. So it prints e-8. This part seems coincidentally correct for this specific case but let's check the formula. If input is 0.1, j=2 ('1' is at index 2). Exponent should be -1. Formula j-1 = 1. Prints e-1. Correct. If input is 0.01, j=3. Exponent -2. Formula j-1=2. Prints e-2. Correct. The exponent calculation `j-1` where `j` is the index of the first non-zero digit in the original string `s` (starting with "0.") is actually correct for the magnitude. `s[0]='0', s[1]='.'`. If first sig digit is at `j`, there are `j-2` zeros between '.' and the digit. The value is $d \times 10^{-(j-2+1)} = d \times 10^{-(j-1)}$. So exponent is `-(j-1)`. The code prints `e-%d`, `j-1`. This is correct. The main error is the placement of the decimal point in the mantissa.
    }
    return 0;}