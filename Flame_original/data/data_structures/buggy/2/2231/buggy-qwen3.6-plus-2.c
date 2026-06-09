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
            if(ans1!=0&&t!='\0'){ // @@ [The condition ans1!=0 incorrectly skips the pending operation when the current operand is 0, causing incorrect calculation results]
                ans=solve(ans,ans1,t);
            }
            t=s[i];i++; // @@ [Missing check for '=' causes an infinite loop and fails to apply the final operation before terminating the loop]
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