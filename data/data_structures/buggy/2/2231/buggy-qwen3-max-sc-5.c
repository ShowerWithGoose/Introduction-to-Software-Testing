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
    gets(s); // @@ [Use of unsafe function 'gets' which can cause buffer overflow; also, 'gets' is removed in C11 standard causing compilation error on modern compilers]
    squeez(s);
    int l=strlen(s);
    i=0;
        while(s[i]>='0'&&s[i]<='9'){
            ans=ans*10+(s[i]-'0'); // @@ ['ans' is used uninitialized here, leading to undefined behavior]
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
            if(ans1!=0&&t!='\0'){
                ans=solve(ans,ans1,t); // @@ ['ans' may be uninitialized when this line executes, leading to undefined behavior]
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
    printf("%d",ans); // @@ ['ans' might not have been properly computed for expressions starting with multiplication/division or single number]
    return 0;
}