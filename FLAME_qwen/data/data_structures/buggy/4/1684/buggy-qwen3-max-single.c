#include<stdio.h>
#include<string.h>
int cnt;
char s[100010];
struct Layn{
    int c[30],ch,res,fa;
}t[100010];
void output(int u){
    if(!u)return;
    output(t[u].fa),printf("%c",t[u].ch+'a');
}
void dfs(int u){
    if(u&&t[u].res)output(u),printf(" %d\n",t[u].res);
    for(int i=0;i<26;i++)if(t[u].c[i])dfs(t[u].c[i]);
}
int main(){
    FILE *in;
    in=fopen("article.txt","r");
    while(fscanf(in,"%s",s)!=EOF){
        int n=strlen(s);
        int u=0;
        for(int i=0;i<n;i++)if(s[i]>='A'&&s[i]<='Z')s[i]=s[i]-'A'+'a';
        for(int i=0;i<n;i++)if(s[i]>='a'&&s[i]<='z'){
            int tmp=s[i]-'a';
            if(!t[u].c[tmp])t[u].c[tmp]=++cnt,t[cnt].fa=u,t[cnt].ch=tmp;
            u=t[u].c[tmp];
        }t[u].res++;
    }dfs(0);
} // @@ [The program does not check if the file "article.txt" was successfully opened. If the file does not exist or cannot be opened, fscanf will invoke undefined behavior. Additionally, global variables like 'cnt' and 't' are uninitialized, which may lead to unpredictable behavior. However, the primary compilation error indicated in the test environment ("gcc: not found") is unrelated to the code itself—it suggests a missing compiler. But since the problem states the error type is Compilation Error and expects code-level fixes, the real issue is that the code uses C99 features (like declaring variables inside for loops: "for(int i=0;...)") without ensuring C99 compliance. In strict C89 mode, this causes a compilation error. To fix, either declare loop variables at the start of the block or compile with -std=c99. Given the instruction to mark lines with errors, the first occurrence of "for(int i=..." should be flagged.]