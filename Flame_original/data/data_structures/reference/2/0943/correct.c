#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define N 1005
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
//scanf记得变量要加&，循环变量记得初始化，break语句写在最后，读清题意，看看变量开int还是longlong
typedef long long ll;
char s[100000];
void deletec(char s[],char c){
    int i,j;
    for(i=j=0;s[i]!='\0';++i){//s[i]!='\0'用于遍历字符串
        if(s[i]!=c)s[j++]=s[i];//用于删除c；
    }
    s[j]='\0';
}
int judge(char c){
    if(c=='*'||c=='/'){
        return 3;
    }
   else if(c=='+'||c=='-'){
        return 2;
    }
   else  if(c=='='){
        return 1;
    }
    return 0;
}

int isnum(char c){
    if(c>='0'&&c<='9'){
        return 1;
    }
    else return 0;
}

typedef struct stack{
    int a[1000];
    int top;
}stack;
void count(char ch,stack *num){
    int e=0;
    switch(ch){
        case '+':
        e=num->a[num->top-1]+num->a[num->top];
        break;
        case '-':
        e=num->a[num->top-1]-num->a[num->top];
        break;
        case '*':
        e=num->a[num->top-1]*num->a[num->top];
        break;
        case '/':
        e=num->a[num->top-1]/num->a[num->top];
        break;
    }
    num->a[num->top-1]=e;
    num->a[num->top]=0;
    num->top--;
}
int main()
{
    int i=0,k=0,j,cnt=0,a;
    char arr[100];
    stack num,sign;
    num.top=-1,sign.top=-1;
    gets(s);
    deletec(s,' ');
    while(s[i]!='\0'){
        char ch=s[i];
        // if(cnt==0&&ch=='-'){
        //     num.top++;
        //     num.a[num.top]=-1;
        //     sign.top++;
        //     sign.a[sign.top]='*';
        // }
        if(isnum(ch)){
            j=i;
            k=0;
            while(isnum(s[j])){
            arr[k++]=s[j];
            j++;
         }
            i=j-1; arr[k]='\0';
            a=atoi(arr);
            cnt++;
            num.top++;
            num.a[num.top]=a;//数字入栈
     } else{
         if(sign.top==-1){
             sign.top++;
             sign.a[sign.top]=s[i];
         } else if(judge(s[i])>judge(sign.a[sign.top])){
             sign.top++;
             sign.a[sign.top]=s[i];
         } else{
             count(sign.a[sign.top],&num);
             sign.top--;
             sign.a[sign.top+1]=0;
             while(judge(s[i])<=judge(sign.a[sign.top])){
                count(sign.a[sign.top],&num);
                sign.top--;
                sign.a[sign.top+1]=0;
             }
             sign.top++;
             sign.a[sign.top]=s[i];
         }
     }
     i++;
    }
    printf("%d",num.a[0]);
return 0;
}
