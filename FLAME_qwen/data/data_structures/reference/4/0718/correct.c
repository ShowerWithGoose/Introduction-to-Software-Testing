#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct remind{
    char words[55];
    int n;
};
int cmp(const void *a, const void *b) {
    struct remind* p = (struct remind*)a, *q = (struct remind*)b;
    if (strcmp(p->words,q->words)>0)
        return 1;
    return -1;
}
int main() {
//    freopen("a.in", "r", stdin);
//    freopen("a.out", "w", stdout);
    FILE *in = fopen("article.txt", "r");
    struct remind test[100];
    char s[1005];
    int i=0,j,k,cnt=0;
    memset(&(test[cnt].words),0,55*sizeof(test[0].words[0]));
    test[cnt].n=0;
    while(fgets(s,1005,in)!=NULL)
//    while(gets(s)!=NULL)
    {
        for(i=0;i<strlen(s);i++){
            if(s[i]>'z'||(s[i]<'a'&&s[i]>'Z')||s[i]<'A')continue;
            for(j=i;(s[j]<='z'&&s[j]>='a')||(s[j]>='A'&&s[j]<='Z');j++) {
                if (s[j] >= 'A' && s[j] <= 'Z') {
                    s[j] = s[j] - 'A' + 'a';
                }
                test[cnt].words[j - i] = s[j];
            }
            test[cnt].n++;
            i=j;
            int flag=0;
            for (j= 0; j< cnt; j++) {
                if(strcmp(test[j].words,test[cnt].words)==0){
                    test[j].n++;
                    flag=1;
                }
            }
            if(flag==1){
                memset(test[cnt].words,0,55*sizeof(test[0].words[0]));
                test[cnt].n=0;
            }
            else{
                cnt++;
                memset(test[cnt].words,0,55*sizeof(test[0].words[0]));
                test[cnt].n=0;
            }
        }
    }
    qsort(test,cnt, sizeof(test[0]),cmp);
    for(i=0;i<cnt;i++){
        printf("%s %d\n",test[i].words,test[i].n);
    }
    return 0;
}

