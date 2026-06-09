#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define WORDLEN 55
#define TABLELEN 10005
typedef struct _WordRec{
    char word[WORDLEN];
    int count;
}WordRec,*PWordRec;
WordRec wordTable[TABLELEN];
int total=0;
int getWord(FILE *fp,char word[]){
    int i=0;
    char c;
    while(!isalpha(c=fgetc(fp)))
        if(c==EOF) return 0;
        else continue;
    word[i++]=tolower(c);
    while((c=fgetc(fp))!=EOF){
        if(!isalpha(c))
            break;
        word[i++]=tolower(c);
    }
    word[i]='\0';
    return 1;
}
int searchWord(char word[]){
    int i;
    for(i=0;i<total;i++){
        if(strcmp(word,wordTable[i].word)==0)
            return i;
    }
    return -1;
}
int insertWord(char word[]){
    strcpy(wordTable[total].word,word);
    wordTable[total].count=1;
    total++;
    return total;
}
int cmp(const void *p1,const void *p2){
    PWordRec w1=(PWordRec)p1;
    PWordRec w2=(PWordRec)p2;
    return strcmp(w1->word,w2->word);
}
int main(){
    FILE *fp;
    int pos,i;
    char word[WORDLEN];
    fp=fopen("article.txt","r");
    if(fp==NULL){
        perror("Can't open the file!\n");
        return -1;
    }
    while(getWord(fp,word)){
        pos=searchWord(word);
        if(pos>=0){
            wordTable[pos].count++;
        }else{
            insertWord(word);
        }
    }
    qsort(wordTable,total,sizeof(WordRec),cmp);
    for(i=0;i<total;i++)
        printf("%s %d\n",wordTable[i].word,wordTable[i].count);
    return 0;
}
