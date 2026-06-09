#include<stdio.h>
#include<string.h>
char s[5005];
int i,j,ans,ans1,ans2; // @@ [Variables 'ans', 'ans1', 'ans2' are used without initialization, leading to undefined behavior]
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
    gets(s); // @@ [Use of unsafe function 'gets' which is deprecated and may cause buffer overflow; also, in many modern environments, 'gets' is removed causing compilation error]
    squeez(s);
    int l=strlen(s);
    i=0;
        while(s[i]>='0'&&s[i]<='9'){
            ans=ans*10+(s[i]-'0'); // @@ [Variable 'ans' is uninitialized; using it leads to undefined behavior]
            i++;
        }
        ans1=ans;
//    printf("%d %d %d %d\n",ans,ans1,ans2,i);
    for(;i<l;i++){
        if(s[i]=='*'||s[i]=='/'){
            char m=s[i];
            int ans2=0;i++; // @@ [Redeclaring 'ans2' inside the loop hides the global 'ans2'; but more critically, after processing a number, 'i' may go out of bounds without checking]
            while(s[i]>='0'&&s[i]<='9'){
                ans2=ans2*10+(s[i]-'0');
                i++;
            }
//        printf("~%d %d %d %d\n",ans,ans1,ans2,i);
            ans1=solve(ans1,ans2,m);
//        printf("~~%d %d %d %d\n",ans,ans1,ans2,i);
        }else{
            if(ans1!=0&&t!='\0'){
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
    printf("%d",ans); // @@ [Final result may be incorrect due to uninitialized variables and flawed parsing logic; also, if expression starts with '-', logic fails]
    return 0;
}