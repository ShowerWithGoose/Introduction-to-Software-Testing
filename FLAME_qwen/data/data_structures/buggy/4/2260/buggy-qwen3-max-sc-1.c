#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct word{
    char ww[100];
    int num;
}word;
word fff[1000];
int j=0;
void shit(){
    FILE* op=fopen("article.txt","r");
    FILE *ou=fopen("fileout.txt","w");
    char c;
    while(fscanf(op,"%c",&c)!=EOF){
        //printf("<<<");
        if(c==' '||(c>='a'&&c<='z')||c=='\n')fprintf(ou,"%c",c);
        else if(c>='A'&&c<='Z'){
            c=tolower(c);
            fprintf(ou,"%c",c);
        }else{
            fprintf(ou,' '); // @@ [Using single quotes for a string literal in fprintf is invalid; should be "%s" with " " or just use ' ' with %c. Here, fprintf expects a format string as first argument after file pointer, but ' ' is a char, not a string. This causes a compilation error because fprintf's second argument must be a const char*, not a char.]
        }
    }
    //printf("f");
    fclose(op);
    fclose(ou);
    //FILE *ooo=fopen("fileout.txt","w");
    //while(fscanf(ooo,"%c",&c)!=EOF)printf("%c",c);
    //printf("g");
}
void print(){
    for(int i=0;i<j;i++){
        printf("%s %d\n",fff[i].ww,fff[i].num);
    }
}
void count(){
    FILE *ou=fopen("fileout.txt","r");
    char ss[100];
    int cnt=0;
    while(fscanf(ou,"%s",ss)!=EOF){
        //printf("%s ",ss);
        int sig=0;
        for(int i=0;i<cnt;i++){
            if(strcmp(ss,fff[i].ww)==0){
                fff[i].num+=1;
                sig=1;
                break;
            }
        }
        if(sig==0){
            strcpy(fff[j].ww,ss);
            fff[j].num+=1; // @@ [fff[j].num is uninitialized; it should be set to 1 instead of +=1 because it's the first occurrence. However, this is a logical error, not a compilation error. The compilation error is only on the fprintf line above.]
            j++;
            cnt++;
            //print();
        }
    }
}
void swapStruct(word *x,word *y){
    word temp=*x;
    *x=*y;
    *y=temp;
}
void sort(){
    for(int i=0;i<j-1;i++){
        for(int k=0;k<j-1;k++){
            if(strcmp(fff[k].ww,fff[k+1].ww)>0){
                swapStruct(&fff[k],&fff[k+1]);
            }
        }
    }
}
int main(){
    shit();
    count();
    sort();
    //printf(" %d",j);
    print();
    return 0;
}