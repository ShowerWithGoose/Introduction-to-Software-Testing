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
    while(fscanf(in,"%s",s)!=EOF){ // @@ The format specifier "%s" reads whitespace-delimited tokens, treating punctuation attached to words (like "since1972.C") as part of the word. This prevents proper separation of words from non-letter characters, leading to incorrect word extraction and counts. It should read character by character or use a method that isolates alphabetic sequences.
        int n=strlen(s);
        int u=0;
        for(int i=0;i<n;i++)if(s[i]>='A'&&s[i]<='Z')s[i]=s[i]-'A'+'a';
        for(int i=0;i<n;i++)if(s[i]>='a'&&s[i]<='z'){
            int tmp=s[i]-'a';
            if(!t[u].c[tmp])t[u].c[tmp]=++cnt,t[cnt].fa=u,t[cnt].ch=tmp;
            u=t[u].c[tmp];
        }t[u].res++; // @@ This line increments the count for the node reached after processing all alphabetic characters in the token. Because the input reading logic is flawed (see above), this often increments counts for invalid "words" containing mixed alphanumeric characters or fails to reset properly between distinct words separated by non-alpha chars within the same token. However, the primary error is the input reading method. A secondary logical issue here is that if a token has no letters, it still increments t[0].res, which is filtered in dfs, but if it has letters, it counts the sequence. The main failure is due to the input parsing.
    }dfs(0);
}