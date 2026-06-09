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
                    num++; // @@ This line incorrectly initializes num to 1 before counting leading zeros after the decimal. It should start at 0 because the exponent is determined by how many places we move the decimal point to get to the first non-zero digit.
                for(int j=i;j<len;j++){
                    if(s[j]=='0')
                        num++; // @@ This counts the zero at the decimal point position (j=i) as a leading zero, which is wrong. The loop should start from j=i+1 to skip the '.' itself.
                    else break;
                }
            }

            else num=i-1; // @@ For numbers >= 1 (e.g., "123.45"), this sets num = i-1, which is correct for the exponent (number of digits before decimal minus 1). However, this branch doesn't handle cases where there are leading zeros before the decimal (which shouldn't happen per problem constraints), but more critically, the logic for numbers < 1 is flawed above.



            print(s,len,num,flag);
        }
    }



    return 0;
}