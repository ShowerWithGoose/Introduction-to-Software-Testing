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
            if(i==1&&s[0]=='0'){ // @@ The condition incorrectly assumes the decimal point is always at index 1 when the number starts with "0.", but for input like "0.00000009123456789012", the decimal point is at index 1, so this part executes, but the logic for counting leading zeros and computing the exponent is flawed.
                    flag=1;
                    num++; // @@ This increments num by 1, but the exponent should be the count of zeros after the decimal point before the first non-zero digit, not just 1. For the test case, there are 8 zeros after the decimal point before '9', so num should be 8, not 1.
                for(int j=i;j<len;j++){ // @@ The loop starts from i (the decimal point) instead of i+1, so it includes the decimal point itself in the count, and the condition checks for '0' but the decimal point is not '0', causing incorrect counting.
                    if(s[j]=='0')
                        num++; // @@ This adds to num for each zero, but num was already incremented to 1, and then it counts zeros from the decimal point onward, which is wrong. It should count zeros after the decimal point before the first non-zero digit.
                    else break;
                }
            }

            else num=i-1; // @@ This branch handles cases where the first digit before the decimal is non-zero, but for numbers like "0.xxx", it is not reached because the if condition above catches it, yet the exponent calculation is incorrect.



            print(s,len,num,flag);
        }
    }



    return 0;
}