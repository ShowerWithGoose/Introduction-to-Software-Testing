#include<stdio.h>
#include<string.h>
char s[5005];
int i,j,ans,ans1,ans2;
char t='\0';
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
            ans=ans*10+(s[i]-'0');
            i++;
        }
        ans1=ans;
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
            if(ans1!=0&&t!='\0'){ // @@ The condition `ans1!=0` is incorrect because it skips updating the result when the accumulated high-precedence value (`ans1`) is legitimately zero (e.g., from `1-1` or `0*5`). It should also check if `t` has been initialized (not just `\0`) or handle the first operator differently. Specifically, if `ans1` is 0, the pending operation stored in `t` is ignored, leading to wrong results.
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
    printf("%d",ans); // @@ The final accumulated value in `ans1` (from the last term or high-precedence chain) is never added/subtracted to `ans`. The loop processes operators by applying the *previous* operator to `ans` and `ans1`, but when the loop ends, the last operator's effect on the last number is not fully resolved into `ans` if the logic relies on the next iteration to flush `ans1`. Actually, looking closer: the logic applies `t` (previous op) to `ans` and `ans1` when a NEW low-priority op is found. But at the end of the string, the last `ans1` is never combined with `ans` using the last `t`.
    return 0;
}