#include<string.h>
#include<stdio.h>
#define MAX 100005
struct node{
    int nxt[27],cnt;
}tr[MAX];
int tn;

void dfs(int u, char s[]){
    if(tr[u].cnt) printf("%s %d\n",s,tr[u].cnt);
    for(int i=1;i<=26;++i){
        if(tr[u].nxt[i]){
            int sl=strlen(s);
            s[sl]='a'+i-1;
            dfs(tr[u].nxt[i],s);
            s[sl]='\0';
        }
    }
}
int main(){
    freopen("article.txt","r",stdin);
    char s[100],ch;
    while((ch=getchar())!=EOF){
        int sl=0;
        while((ch<'A'||ch>'Z')&&(ch<'a'||ch>'z')) {ch=getchar(); if(ch==EOF)break;}
        while(ch>='A'&&ch<='Z'||ch>='a'&&ch<='z') {if(ch<='Z')ch=ch-'A'+'a';s[++sl]=ch; ch=getchar();}
        int u=0;
        for(int i=1;i<=sl;++i){
            int k=s[i]-'a'+1;
            if(!tr[u].nxt[k]) tr[u].nxt[k]=++tn;
            u=tr[u].nxt[k];
        }
        ++tr[u].cnt;
    }
    tr[0].cnt=0;
    //for(int i=1;i<=tn;++i) printf("%d ",tr[i].cnt);
    char ss[MAX];
    dfs(0,ss);

    return 0;
}


