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
                    num++; // @@ [Error: num is incremented by 1 for the decimal point, but should count the number of leading zeros after the decimal point. For input "0.00000009123456789012", num becomes 1 after this line, but the correct exponent should be -8, meaning num should be 8. The loop below increments num for each '0' after the decimal point, but the initial num++ here adds an extra 1, causing the exponent to be off by one.]
                for(int j=i;j<len;j++){
                    if(s[j]=='0')
                        num++; // @@ [Error: This loop counts zeros including the decimal point itself (since j starts at i, which is the position of '.'), and also counts all zeros after the decimal point. For the input, it counts 7 zeros (positions after '.'), but with the initial num++, total becomes 8, which is correct for the exponent magnitude. However, the logic is flawed because it doesn't handle the case where the first non-zero digit appears after zeros correctly; the exponent should be the number of zeros after the decimal point before the first non-zero digit, but here it counts all zeros in the string, which may be incorrect if there are zeros after non-zero digits. Additionally, the loop condition j<len may cause num to be incremented for non-zero digits if they are '0'? No, it only increments for '0', but the loop continues until end of string, so it counts all zeros in the entire string after the decimal point, which is wrong. For the given input, after the decimal point, the zeros are "0000000" (7 zeros) then "9123456789012", so the loop counts 7 zeros, plus the initial num++ gives 8, which matches the expected exponent magnitude. But if there were zeros after non-zero digits, this would be incorrect. The correct approach is to count only the leading zeros after the decimal point until the first non-zero digit.]
                    else break;
                }
            }

            else num=i-1; // @@ [Error: This branch handles cases where the first digit before the decimal point is non-zero. For example, input "123.456", i is the position of '.', so num = i-1 gives the number of digits before the decimal point minus 1, which is the exponent. However, this logic fails for inputs like "0.123" where i==1 and s[0]=='0', so it goes to the if branch. But for inputs like "0.0" or "0.000", the if branch is taken, but the exponent calculation is incorrect because it doesn't handle the case where the number is zero or has no non-zero digits. Also, for inputs like "0.00123", the if branch is taken, but the exponent should be -3, not the number of zeros counted. The current code's logic for the if branch is flawed as described above.]

            print(s,len,num,flag);
        }
    }



    return 0;
}