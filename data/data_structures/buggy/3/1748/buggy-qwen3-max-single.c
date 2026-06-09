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
} // @@ [The program does not handle inputs that do not contain a decimal point ('.'), causing it to produce no output for such cases. According to the problem description, inputs always have digits before and after the decimal point, but the code assumes '.' exists and only processes inside the 'if(s[i]=='.')' block. If the input somehow lacks '.', the loop ends without printing anything, violating the expected behavior. Additionally, the logic for computing the exponent (num) is flawed: for numbers like "123.45", it sets num = i-1 = 2, which is correct, but for "0.00123", it sets num = number of leading zeros after decimal + 1, which results in num=4, but should be -3. The sign and magnitude of the exponent are incorrectly calculated.]