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
            if(i==1&&s[0]=='0'){ // @@ The condition only handles the case where the decimal point is at index 1 and the first character is '0', but does not correctly handle numbers like "0.001" where there are leading zeros after the decimal point. The logic for counting exponent and flag is incomplete and incorrect for general cases.
                    flag=1;
                    num++;
                for(int j=i;j<len;j++){
                    if(s[j]=='0')
                        num++;
                    else break;
                }
            }

            else num=i-1; // @@ This assumes the exponent is always i-1 for non-zero leading digits, but does not account for cases where the number has no integer part (e.g., ".5" is not valid input per problem description) or where the number is an integer without a decimal point. The logic fails to handle numbers like "12.34" correctly because it only processes when a decimal point is found, and for integers without a decimal point, the loop never executes, leaving num uninitialized and no output produced.



            print(s,len,num,flag);
        }
    }



    return 0;
}