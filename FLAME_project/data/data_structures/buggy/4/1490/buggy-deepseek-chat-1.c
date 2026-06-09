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

char file[1005];
char tmp[1005];
int Slen;
char *p;
Words words[205];
int count;
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
            file[i] = tolower(c);
            i++;
        }
        else if(c==' '){
           file[i]=c;
           i++;
        }
        else {
            file[i]=' ';
            i++;
        }
        c= fgetc(in);
    }while(c!=EOF);

    p=file;
    int d= strlen(file);
    for (int j = 0; j < d; ++j) {
        if(file[j]==' ') {
            continue;
        }
        else {
            if(('A'<=file[0]&&file[0]<='Z')||('a'<=file[0]&&file[0]<='z'))
                strcpy(tmp,file);
            else {
                strcpy(tmp, file + 1);
                for (int k = 0; k < d; ++k) {
                    file[k] = '\0';
                }
                strcpy(file, tmp);
                break;
            }
        }
    }

    file[strlen(file)]=' ';
    Slen= strlen(file);
    int eddele=0;
    char tt[15];
    int key=0;

    Getwords();
    qsort(words,count,sizeof(Words),cmp);
    for (int j = 0; j < count; ) {
        if(words[j].word[0]=='\0') {
            j++;
            continue;
        }
        words[j].times=0;
        for(int k=0;k<15;k++)   tt[k]='\0';
        key=0;
        strcpy(tt,words[j].word);
        for (int k = 0; k < count; ++k) {
            if(strcmp(tt,words[k].word)==0){
                words[j].times++;
                key++;
            }
        }
        printf("%s %d\n",words[j].word,words[j].times);
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
    for (int i = 0; i < Slen; ++i) {
        if(file[i]==' '){
            strncpy(words[count].word,p+flag,l); // @@ [strncpy does not null-terminate the destination string when the source length is less than the destination size, causing undefined behavior in subsequent string operations]
            l=0;
            flag=i+1;
            count++;
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