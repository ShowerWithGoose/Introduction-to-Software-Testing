#include<stdio.h>
#include<string.h>
char s[5005];
int i,j,ans,ans1,ans2;
char t='\0'; // @@ t should be initialized to '+' to correctly accumulate the first term. With '\0', the first additive operator does not accumulate the result of the preceding multiplicative chain into ans.
void squeez(char s[]){
    int i,j;
    for(i=j=0;s[i]!='\0';i++){
        if(s[i]!=' ')s[j++]=s[i];
    }
    s[j]='\0';
}
int solve(int a,int b,char c){
    switch (c){
        case '+':return a+b;
        case '-':return a-b;
        case '*':return a*b;
        case '/':return a/b;
    }
}
int main(){
    gets(s);
    squeez(s);
    int l=strlen(s);
    i=0;
    while(s[i]>='0'&&s[i]<='9'){
        ans=ans*10+(s[i]-'0'); // @@ ans is mistakenly used to store the first number and also as the accumulator for additive operations. ans should remain 0 as the running total; the first number should be stored only in ans1.
        i++;
    }
    ans1=ans; // @@ This sets ans1 to the first number, but ans still holds the same value. This causes ans to be incorrectly used later as the starting point for addition/subtraction, instead of starting from 0 and using the result of the multiplicative chain.
//    printf("%d %d %d %d\n",ans,ans1,ans2,i);
    for(;i<l;i++){
        if(s[i]=='*'||s[i]=='/'){
            char m=s[i];
            int ans2=0;i++;
            while(s[i]>='0'&&s[i]<='9'){
                ans2=ans2*10+(s[i]-'0');
                i++;
            }
//        printf("~%d %d %d %d\n",ans,ans1,ans2,i);
            ans1=solve(ans1,ans2,m);
//        printf("~~%d %d %d %d\n",ans,ans1,ans2,i);
        }else{
            if(ans1!=0&&t!='\0'){ // @@ This condition works correctly only if t is properly initialized. However, due to the errors in setting ans and ans1, the accumulation here uses the wrong ans value.
                ans=solve(ans,ans1,t);
            }
            t=s[i];i++;
            ans1=0;
            while(s[i]>='0'&&s[i]<='9'){
                ans1=ans1*10+(s[i]-'0');
                i++;
            }
//        printf("!!%d %d %d %d\n",ans,ans1,ans2,i);
        }
//        printf("%d %d %d %d\n",ans,ans1,ans2,i);
        i--;
    }
    printf("%d",ans);
    return 0;
}