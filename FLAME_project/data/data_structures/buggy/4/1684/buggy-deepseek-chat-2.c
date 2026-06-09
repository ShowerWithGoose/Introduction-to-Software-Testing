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
    while(fscanf(in,"%s",s)!=EOF){ // @@ The program reads whitespace-delimited tokens, but the problem requires reading character by character to handle punctuation attached to words (e.g., "since1972." should be split into "since" and "1972", but here "since1972" is treated as a single token, causing incorrect word boundaries and missing words like "c" and "since" that appear with punctuation).
        int n=strlen(s);
        int u=0;
        for(int i=0;i<n;i++)if(s[i]>='A'&&s[i]<='Z')s[i]=s[i]-'A'+'a';
        for(int i=0;i<n;i++)if(s[i]>='a'&&s[i]<='z'){
            int tmp=s[i]-'a';
            if(!t[u].c[tmp])t[u].c[tmp]=++cnt,t[cnt].fa=u,t[cnt].ch=tmp;
            u=t[u].c[tmp];
        }t[u].res++; // @@ This increments the count for the entire token, but if the token contains non-letter characters (like digits), they are skipped, and the word is still counted. However, the main issue is that tokens like "since1972" are not split into separate words, so "since" and "c" are not counted separately, and "since1972" is incorrectly counted as a word.
    }dfs(0);
}