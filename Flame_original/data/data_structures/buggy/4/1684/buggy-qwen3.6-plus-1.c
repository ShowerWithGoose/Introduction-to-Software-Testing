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
    while(fscanf(in,"%s",s)!=EOF){ // @@ Using %s splits only on whitespace, but punctuation should also act as word separators per problem definition.
        int n=strlen(s);
        int u=0;
        for(int i=0;i<n;i++)if(s[i]>='A'&&s[i]<='Z')s[i]=s[i]-'A'+'a';
        for(int i=0;i<n;i++)if(s[i]>='a'&&s[i]<='z'){ // @@ Fails to reset trie pointer u when non-letter characters are encountered, causing separate words to be incorrectly merged.
            int tmp=s[i]-'a';
            if(!t[u].c[tmp])t[u].c[tmp]=++cnt,t[cnt].fa=u,t[cnt].ch=tmp;
            u=t[u].c[tmp];
        }t[u].res++; // @@ Unconditionally increments frequency count even if the string contained no letters, and fails to reset u to the root for the next word.
    }dfs(0);
}