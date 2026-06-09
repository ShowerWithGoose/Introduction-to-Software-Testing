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
        }t[u].res++; // @@ [The program uses fscanf with "%s", which reads space-delimited tokens but does not properly handle non-alphabetic characters within a token. In the test input, words like "since1972.C" are read as whole tokens, and only alphabetic characters are processed, but the loop stops at non-letter characters without resetting or handling multiple words per token correctly. This causes "since" and "c" to be extracted from the same token without proper separation, leading to missing counts. Additionally, after processing all alphabetic characters in a token, the program increments t[u].res once per token, even if multiple valid words exist in one token (e.g., "since1972.C" contains "since" and "c"), but the current logic treats it as a single partial word path.]
    }dfs(0);
}