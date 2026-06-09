/*
 * @Author:
 * @Date: 2022-03-25 13:20:16
 * $Trie
 * 已提交链表+哈希版本，此版本为Trie
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#define MaxS 1000

//========================= Trie
#define MaxN 100000

int trie[MaxN][26], node_num = 0, size[MaxN];

void trieInsert(char s[], int len) {
    int now = 0;
    for (int i = 0; i < len; i++) {
        int c = s[i] - 'a';
        if (!trie[now][c])
            trie[now][c] = ++node_num;
        now = trie[now][c];
    }
    size[now]++;
}

char wordStack[MaxS];
int top=-1;
void dfs(int now){
    if(size[now]>0){
        wordStack[top+1]='\0';
        printf("%s %d\n",wordStack,size[now]);
    }
    for(int i=0;i<26;i++){
        if(trie[now][i]){
            wordStack[++top]=i+'a';
            dfs(trie[now][i]);
            top--;
        }
    }
}

//=============================  main
void processStr(char s[],int len){
    for(int i=0;i<=len;i++){
        if(!isalpha(s[i])){
            s[i]='\0';
        }else if(isupper(s[i])){
            s[i]=tolower(s[i]);
        }
    }
}

char line[MaxS+5];
int len;

int  main() {
    freopen("article.txt","r",stdin);

    while(gets(line+1)!=NULL){
        len=strlen(line+1);
        processStr(line,len);// remove non-alphabets and split words by '\0'
        for(int i=1;i<=len;i++){
            if(isalpha(line[i])&&line[i-1]=='\0'){ // line[i] is a start of a certain word
                trieInsert(&line[i],strlen(&line[i]));
            }
        }
    }
    dfs(0);

    return 0;
}
