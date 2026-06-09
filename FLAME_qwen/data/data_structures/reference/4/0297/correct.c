#include<stdio.h>
#include<string.h>
int n,rt,m;
char s[205];
struct trie{
    int ch[27],w;
}t[1005];
void add(int l,int r){
    int p=rt,x;
    for(int i=l;i<=r;i++){
        x=s[i]-'a'+1;
        if(!t[p].ch[x]) t[p].ch[x]=++m;
        p=t[p].ch[x];
    }
    t[p].w++;
}
void dfs(int x,int d){
    if(t[x].w){
        for(int i=1;i<=d;i++) putchar(s[i]);
        printf(" %d\n",t[x].w);
    }
    for(int i=1;i<=26;i++){
        if(!t[x].ch[i]) continue;
        s[d+1]=i-1+'a';dfs(t[x].ch[i],d+1);
    }
}
int main(){
    rt=m=1;
    freopen("article.txt","r",stdin);
    while(gets(s+1)!=NULL){
        n=strlen(s+1);
        for(int i=1;i<=n;i++) if(s[i]>='A'&&s[i]<='Z') s[i]=s[i]-'A'+'a';\
        for(int i=1;i<=n;i++){
            if(s[i]>='a'&&s[i]<='z'){
                int p=i;
                while(s[p]>='a'&&s[p]<='z') p++;
                add(i,p-1);i=p;
            }
        }
    }
    dfs(rt,0);
    return 0;
}
