#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int min(int a,int b){
    return a<=b?a:b;
}

int max(int a,int b){
    return a>=b?a:b;
}

typedef struct Element{
    int to;
    struct Element* next;
}Element;

typedef struct List{
    Element *head;
    Element *tail;
}List;

void print(char*s,int len,int num,int flag){
    int j=0;
    while(s[j]=='0'||s[j]=='.')
        j++;
    printf("%c",s[j]);
    if(j+1<len)
        printf(".");
    for(int i=j+1;i<len;i++){
        if(s[i]!='.')
            printf("%c",s[i]);
    }
    printf("e");
    if(flag) printf("-");
    printf("%d",num);
}

int main(){
    char s[100005]={0};
    scanf(" %s",s);
    int len=strlen(s);
    int flag=0;
    int num=0;
    for(int i=0;i<len;i++){
        if(s[i]=='.'){
            if(i==1&&s[0]=='0'){
                    flag=1;
                    num++; // @@ The logic for calculating the exponent for numbers like 0.00... is incorrect. It counts leading zeros including the one before the decimal point, but fails to account for the position correctly relative to the first significant digit. For 0.00000009..., it calculates num as 8 (counting '0', '.', '0', '0', '0', '0', '0', '0', '0' then breaks at '9'? No, the loop is `for(int j=i;j<len;j++)`. i is index of '.'. s[i] is '.'. num starts at 0, increments to 1. Then j becomes i+1. s[i+1] is '0', num becomes 2. ... s[i+7] is '0', num becomes 8. s[i+8] is '9', break. So num is 8. This part actually seems to calculate the magnitude of the negative exponent correctly for this specific case structure, BUT:
                for(int j=i;j<len;j++){
                    if(s[j]=='0')
                        num++;
                    else break;
                }
            }

            else num=i-1; // @@ This line is executed for inputs like "123.45". Here num becomes 2 (index of '.' is 3, 3-1=2). The exponent should be 2 (1.2345e2). This seems correct for positive exponents. However, the previous block's logic is flawed because it doesn't strip trailing zeros or handle the general case of finding the first significant digit properly in conjunction with the exponent calculation. The main issue is that the `print` function relies on `num` being the exponent magnitude, but the calculation in the `if` block is fragile and incorrect for general cases (e.g., 0.10 vs 0.1). More critically, for the input `0.00000009123456789012`, the code enters the `if` block. `num` becomes 8. `flag` becomes 1. `print` is called. Inside `print`, `j` skips '0' and '.', landing on '9'. It prints '9', then '.', then the rest. It prints "e-", then `num` which is 8. Output: 9.123...e-8. Wait, the buggy output provided in the prompt is `9.123456789012e-1`. Let's re-read the code carefully.
            
            Re-evaluating the `if` block:
            `num` is initialized to 0.
            `flag` is 0.
            Input: `0.00000009123456789012`
            `i` finds '.' at index 1.
            `i==1 && s[0]=='0'` is true.
            `flag=1`.
            `num++` -> `num` becomes 1.
            Loop `j` starts at `i` (1).
            `s[1]` is '.'. `s[j]=='0'` is false. Break immediately.
            So `num` remains 1.
            This explains the output `e-1`.
            The error is that the loop starts at `j=i` (the decimal point), checks if `s[j]=='0'`. The decimal point is not '0', so it breaks. It fails to count the zeros *after* the decimal point.
            
            Therefore, the line `for(int j=i;j<len;j++){` is logically incorrect because it starts checking at the decimal point itself instead of the character after it, or fails to skip the decimal point.
            
            Also, the `else` branch `num=i-1` calculates the exponent for numbers >= 1. For `12.34`, `i`=2, `num`=1. Correct (1.234e1). For `123.45`, `i`=3, `num`=2. Correct.
            
            The primary error is in the loop initialization/condition for the small number case.

            print(s,len,num,flag);
        }
    }



    return 0;
}