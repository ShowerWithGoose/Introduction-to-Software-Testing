# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <ctype.h>
struct node{
    char word[25];
    int n;
}out[110];
int read(FILE *in,char word[]){
    int i=0;
    char s;
    while ((s=fgetc(in))!=EOF){
        if(isalpha(s)){
            word[i]=tolower(s);
            i++;
        }
        else if(i)
            return 1;
    }
    return 0;
}
int cmp(const void * a, const void * b){
    struct node*c=(struct node*)a;
    struct node*d=(struct node*)b;
    return strcmp(c->word,d->word);
}
int main() {
    FILE *in;
    char word[25]={0};
    int cnt=0;
    in=fopen("article.txt","r");
    while(read(in,word)){
        int i=0,flag=1;
        for(;i<=cnt;i++){
            if(strcmp(word,out[i].word) == 0){
                out[i].n++;
                flag--;
                break;
            }
        }
        if(flag){
            strcpy(out[cnt].word, word);
            out[cnt].n++; 
            cnt++;
        }
        memset(word,0,25);
    }
    qsort(out,cnt, sizeof(struct node),cmp);

    for(int i=0;i<cnt;i++)
        printf("%s %d\n",out[i].word,out[i].n);

    return 0;
}

