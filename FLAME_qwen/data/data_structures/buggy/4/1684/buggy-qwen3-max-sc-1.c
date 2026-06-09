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
    in=fopen("article.txt","r"); @@ [If the file "article.txt" does not exist or cannot be opened, fscanf will cause undefined behavior. However, the primary compilation error is likely due to missing initialization of global variables in some environments, but more critically: the array t and cnt are uninitialized, leading to undefined behavior at runtime—not compilation error. But the actual compilation error reported is "gcc: not found", which is not a code issue. However, given the context, the real bug is that the code uses "%s" with fscanf, which reads space-delimited tokens, but the problem defines words as sequences of letters only. Non-letter characters within a token (e.g., "don't") would be partially processed incorrectly. But the immediate cause of discrepancy vs reference is word parsing logic. However, the error type says "Compilation Error", yet the provided buggy output is "/bin/sh: 1: gcc: not found", which indicates the environment lacks gcc—so no compilation happened. But assuming that's a red herring and we're to find logical errors causing wrong output: the main flaw is using fscanf("%s",...) which stops at whitespace, but doesn't isolate letter-only sequences. For example, input "Hello,world!" would be read as one string "Hello,world!" and then non-letters like ',' and '!' remain in s[i], so the inner loop skips them, but the word becomes "helloworld" (incorrectly merged). The correct approach is to read character by character and extract letter sequences, as in the reference program. Thus, the line using fscanf("%s",s) is fundamentally flawed for the problem's word definition.]
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
}