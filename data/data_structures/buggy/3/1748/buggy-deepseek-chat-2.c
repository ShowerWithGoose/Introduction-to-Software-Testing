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

            else num=i-1; // @@ Error: For numbers like "0.001", the exponent calculation is incorrect. The exponent should be negative and based on the number of leading zeros after the decimal point, not just i-1. Also, the flag is not set for this case, so the exponent sign is missing.

            print(s,len,num,flag);
        }
    }

    // @@ Error: The program does not handle cases where the input is an integer (no decimal point). The loop will never execute the if(s[i]=='.') block, so nothing is printed.

    return 0;
}