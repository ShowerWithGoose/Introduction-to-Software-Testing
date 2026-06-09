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
                    num++;
                for(int j=i;j<len;j++){
                    if(s[j]=='0')
                        num++;
                    else break;
                }
            }

            else num=i-1;



            print(s,len,num,flag);
        }
    }



    return 0;
} // @@ [The program does not handle inputs without a decimal point. According to the problem, the input always has digits before and after the decimal point, but the code only processes the number when it encounters a '.'. If the input somehow lacks a '.', the loop ends without printing anything, leading to no output. However, more critically, the test case likely includes a valid input with a decimal point, but the logic for computing the exponent and formatting the mantissa is flawed. Specifically, in the case where the number starts with '0.' (like "0.00123"), the exponent calculation counts the leading zeros after the decimal including the first non-zero digit position incorrectly. Also, the print function assumes there's always a non-zero digit after skipping zeros and '.', but doesn't validate that. Additionally, the original reference program uses gets() which is unsafe, but the bug here is logical: the main loop only triggers on finding '.', but after processing, it doesn't exit, and if there are multiple '.' (invalid input), it would reprocess. But the core error is that for numbers >= 1 (e.g., "123.45"), the exponent is set to i-1 (which is correct: 2 for "123.45"), but the print function skips all leading zeros and the decimal, so for "123.45", j becomes 0 (since s[0]='1' != '0' or '.'), prints '1', then prints '.' because j+1=1 < len, then prints "2345", resulting in "1.2345e2" which is correct. However, for "0.00123", i=1, flag=1, num starts at 1, then counts two more zeros (at j=2,3), so num=3, then print skips '0','.', then j=2 (s[2]=='0') -> j=3 (s[3]=='0') -> j=4 (s[4]=='1'), prints '1', then since j+1=5 < len, prints '.', then "23", so "1.23e-3" — but wait, the exponent should be -3, and flag=1 causes "-" to be printed, so "1.23e-3", which is correct. So why the failure? The real issue: the program never handles the case where the input has no decimal point. But the problem states the input has digits before and after the decimal point, so '.' must exist. However, the code only calls print inside the if(s[i]=='.') block. But what if the string has no '.'? Then print is never called → no output. But per problem, input always has '.', so that shouldn't happen. Another possibility: the input "0.1" — i=1, s[0]=='0', so flag=1, num=1, then j starts at i=1, s[1]=='.'? No, s[1] is '.' already handled; the inner loop: for j from i=1 to len: s[1] is '.' — but the condition is if(s[j]=='0'), so '.' is not '0', so break. So num remains 1. Then print: j=0 (s[0]=='0') → skip, j=1 (s[1]=='.') → skip, j=2 (s[2]=='1') → stop. Print '1', then since j+1=3 > len (len=3? "0.1" has len=3: '0','.','1'), so j+1=3 == len → no decimal point printed. So output is "1e-1", but expected is "1.0e-1"? No, problem says: if base is decimal, one digit before and after. But "1" alone is integer form, which is allowed only if one significant digit. However, "0.1" has two significant digits? No, "0.1" has one significant digit. So "1e-1" is acceptable. But what about "0.10"? Problem states: no trailing zeros after decimal, so input won't have that. So maybe the bug is elsewhere. Wait, test case input is not provided explicitly, but the error type says "Compilation Error", yet the buggy output is "/bin/sh: 1: gcc: not found", which is a system error, not a code error. But the instruction says: "identify the location of the errors in the program below" based on failed test cases. However, the actual issue in the code is that it doesn't handle the case when the number is like "1.0" — but problem says no trailing zeros, so "1.0" won't appear. Another critical flaw: the main loop iterates through every character, and every time it sees a '.', it processes the number. If the input has only one '.', it's okay, but after processing, it continues the loop. However, the bigger issue: what if the input is "123"? No '.' → no output. But problem guarantees '.' exists. However, looking at the code: after the for-loop that checks for '.', if the input has a '.', it will call print once (at the first '.'). But what if the number is "0.0"? Problem states all digits are significant and no trailing zeros, and if only one digit before decimal it can be 0, but "0.0" would have trailing zero, so invalid input. So perhaps the real bug is in exponent calculation for numbers >=1. Example: "12.34" — i=2 (s[2]=='.'), so num = i-1 = 1. Correct exponent is 1. Print: j=0 (s[0]=='1' not skipped), print '1', then j+1=1 < len=5 → print '.', then print "234" → "1.234e1" — correct. Now "1.23": i=1, num=0, print "1.23e0" — correct. Now "0.001": i=1, flag=1, num=1, then inner loop: j=1 ('.'), not '0', so break → num=1. But exponent should be -3? No: 0.001 = 1e-3. How many zeros after decimal before 1? Two zeros, so exponent is -3. The code sets num=1 initially, then loops from j=i=1: s[1] is '.' → not '0', so break. So num=1, but should be 3. The error is here: after "0.", the zeros are at positions 2,3,... So the loop should start from i+1, not i. Because s[i] is '.', so the next characters are after decimal. So in "0.001", i=1 (the '.'), then the zeros are at index 2 and 3. So the inner loop should start at j = i+1. Currently, it starts at j=i, which is '.', so it breaks immediately. Hence, num remains 1, but should be 3. Therefore, the error is in the loop initialization: for(int j=i;j<len;j++) should be for(int j=i+1;j<len;j++). This causes undercounting of leading zeros after decimal, leading to wrong exponent.