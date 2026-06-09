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
                    num++; // @@ The logic for calculating the exponent for numbers like 0.00... is incorrect. It counts leading zeros including the one before the decimal point, but fails to account for the position correctly relative to the first significant digit. For 0.00000009..., it calculates num as 8 (1 initial + 7 zeros), but the loop breaks at the first non-zero. The exponent should be the number of places the decimal point moves. For 0.0000000912..., the first sig digit is at index 9. The decimal is at index 1. The exponent is -(9-1) = -8. The current code increments num for '0' at index 1 (the '0' before dot? No, i is index of dot. s[0]=='0'. The loop starts at j=i (index of dot). s[1] is '.', s[2] is '0'... This logic is flawed.
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
}