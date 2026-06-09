#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define pi acos(-1)
#define eps 1e-8
void Getwords();
int cmp(const void *a,const void *b);
int cmp1(const void *a,const void *b);

typedef struct alphabet{
    char word[15];
    int times;
}Words;

char theword[1005];
char tmp[1005];
int N;
char *p;
Words WN[205];
int numofwords;
int main(){
    FILE *in;
    in= fopen("article.txt","r");

    char c= fgetc(in);
    int i=0;
    int f=0;
    do {
        if(c=='\n') {
            if(f==0) {
                c = ' ';
                f=1;
                continue;
            }
        }
        else if(('A'<=c&&c<='Z')||('a'<=c&&c<='z')) {
            f = 0;
            theword[i] = tolower(c);
            i++;
        }
        else if(c==' '){
           theword[i]=c;
           i++;
        }
        else {
            theword[i]=' ';
            i++;
        }
        c= fgetc(in);
    }while(c!=EOF);

    p=theword;
    int d= strlen(theword);
    for (int j = 0; j < d; ++j) {
        if(theword[j]==' ') {
            continue;
        }
        else {
            if(('A'<=theword[0]&&theword[0]<='Z')||('a'<=theword[0]&&theword[0]<='z'))
                strcpy(tmp,theword);
            else {
                strcpy(tmp, theword + 1);
                for (int k = 0; k < d; ++k) {
                    theword[k] = '\0';
                }
                strcpy(theword, tmp);
                break;
            }
        }
    }

    theword[strlen(theword)]=' ';
    N= strlen(theword);
    int eddele=0;
    char tt[15];
    int key=0;

    Getwords();
    qsort(WN,numofwords,sizeof(Words),cmp);
    for (int j = 0; j < numofwords; ) {
        if(WN[j].word[0]=='\0') {
            j++;
            continue;
        }
        WN[j].times=0;
        for(int k=0;k<15;k++)   tt[k]='\0';
        key=0;
        strcpy(tt,WN[j].word);
        for (int k = 0; k < numofwords; ++k) {
            if(strcmp(tt,WN[k].word)==0){
                WN[j].times++;
                key++;
            }
        }
        printf("%s %d\n",WN[j].word,WN[j].times);
        j+=key;
    }
//    for (int j = 0; j <count-1; ++j) {
//        if(strcmp(words[j].word,words[j+1].word)==0){
//            for (int k = 0; k < 15; ++k) {
//                words[j].word[k]='\0';
//            }
//            eddele++;
////            j--;
//        }
//    }
//    qsort(words,count,sizeof(Words),cmp1);
//    qsort(words,count-eddele,sizeof(Words),cmp);
//
//    char *flag=file;
//    for (int j = 0; j < count-eddele; ++j) {
//        words[j].times=0;
//        flag=file;
//        for (int k = 0; k < count; ++k)  {
//            if(flag==file+strlen(file)-1)
//                break;
//            if(strstr(flag,words[j].word)!=NULL){
//                words[j].times++;
//                flag = strstr(flag, words[j].word) + strlen(words[j].word);
//            }
//            break;
//        }
//    }

//    ('a'<=(*(flag-1))&&(*(flag-1)) <= 'z')==0

//    for (int j = 0; j < count-eddele; ++j) {
//        printf("%s %d\n",words[j].word,words[j].times);
//    }
    return 0;
}
void Getwords(){
    int l=0;
    int flag=0;
    for (int i = 0; i < N; ++i) {
        if(theword[i]==' '){
            strncpy(WN[numofwords].word,p+flag,l);
            l=0;
            flag=i+1;
            numofwords++;
        }
        else l++;
    }
}
int cmp(const void *a,const void *b){
    Words *p1=(Words *)a;
    Words *p2=(Words *)b;
    return strcmp(p1->word,p2->word);
}
int cmp1(const void *a,const void *b){
    Words *p1=(Words *)a;
    Words *p2=(Words *)b;
    return strcmp(p2->word,p1->word);
}



