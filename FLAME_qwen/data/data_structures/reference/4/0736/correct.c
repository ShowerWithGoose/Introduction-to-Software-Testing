#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define N 10086
#define AlphaN 26

int readWord(FILE* f,char c[]) {
    char ch, *p = c;
    while(!isalpha(ch=fgetc(f))) {
        if(ch == EOF) return -1;
    }
    while(isalpha(ch)) {
        if(isupper(ch)) {
            ch = tolower(ch);
        }
        *p++=ch;
        ch = fgetc(f);
    }
    *p=0;
    return ch;
}

int ctoi(char x) {
    return x - 'a';
}
char itoc(int x){
    return x + 'a';
}

int nxt[N][AlphaN], tai = 0;
int cnt[N];

char otp[109];

void dfs(int p,int l) {
    if(cnt[p]) {
        printf("%s %d\n",otp, cnt[p]);
    }
    for(int i=0;i<AlphaN;i++) {
        if(nxt[p][i]) {
            otp[l] = itoc(i);
            dfs(nxt[p][i], l+1);
            otp[l] = 0;
        }
    }
}

int main() {
    FILE *file = fopen("article.txt", "r");
    char inp[109];
    while(~readWord(file, inp)) {
        int p = 0, t;
        for(char *c=inp; *c; c++) {
            t = ctoi(*c);
            if(!nxt[p][t]) {
                nxt[p][t] = ++tai;
                p = tai;
            }else p = nxt[p][t];
        }
        cnt[p]++;
    }

    dfs(0,0);
    

    return 0;
}
