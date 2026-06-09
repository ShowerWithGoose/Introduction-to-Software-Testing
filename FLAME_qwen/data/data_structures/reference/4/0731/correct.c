#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE *p;
int i;
struct word{
    char word[26];
    int times;
}words[100000];
int num=0;
char in[26];

int comp(const void *a,const void *b){
    struct word *ap=(struct word *)a;
    struct word *bp=(struct word *)b;
    return strcmp(ap->word,bp->word);
}
void putin(){
    struct word *p;
    if(num==0){
        strcpy(words[0].word,in);
        words[0].times++;
        num++;
    }else{
        qsort(words,num,sizeof(struct word),comp);
        p=bsearch(in,words,num,sizeof(struct word),comp);
        if(p==NULL){
            strcpy(words[num].word,in);
            words[num++].times++;
        }else{
            p->times++;
        }
    }
    memset(in,0,26);
    return;
}

void getwords(){
    char c;
    while((c=fgetc(p))!=EOF){
        if((c<='Z'&&c>='A')||(c<='z'&&c>='a')){
            if(c<='Z'&&c>='A')in[i++]=c+('a'-'A');
            else in[i++]=c;
        }else if(in[0]<='z'&&in[0]>='a'){
            putin();
            i=0;
        }
    }
    if(in[0]<='z'&&in[0]>='a'){
        putin();
    }
}

int main(void){
    p=fopen("article.txt","r");
    getwords();
    fclose(p);
    qsort(words,num,sizeof(struct word),comp);
    for(int i=0;words[i].times!=0;i++){
        printf("%s %d\n",words[i].word,words[i].times);
    }
    return 0;
}


