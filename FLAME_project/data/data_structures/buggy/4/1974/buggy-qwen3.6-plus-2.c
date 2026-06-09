#include <stdio.h>
#define sf scanf
#define pf printf
#define ll long long 
#include <math.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>
typedef struct word{
char zi[10086];
    int ci;

}word;
word con[1000];     

int main(){
FILE *in,*out;
in=fopen("article.txt","r");

int compare(const void *a,const void *b){
     word *c=(word* )a;
     word *d=(word *)b;
     return strcmp(c->zi,d->zi);

}
    char k;
    char s[10086]={'\0'};
    char ss[10086]={'\0'};
    char *q=malloc(100*sizeof(s[0]));
    char *m=NULL;
    int a,b,c,d,i=0,j,flag=0,flag1=0;
while((k=fgetc(in))!=EOF){
     if(k>='A'&&k<='Z'){
        s[i]=k-'A'+'a';i++;flag1=0;
    }else if(k>='a'&&k<='z'){
        s[i]=k;i++;flag1=0;
    }else if(k==' '||k=='\n'){
    if(flag1==0){
    
        s[i]='\0';i++;
        flag1=1;}
    }
} // @@ The loop fails to handle non-alphabetic characters (like digits and punctuation) as word delimiters. It only treats spaces and newlines as delimiters. Consequently, sequences like "since1972" are treated as single words or merged incorrectly because digits are ignored but don't trigger the end-of-word logic properly, leading to incorrect tokenization. Additionally, it misses the last word if the file doesn't end with a space/newline.


for(i=0;i<1000;i++){
    con[i].ci=0;
}
i=0;
q=s;
while(*q!='\0'){
    flag=0;
    if(i==0){
    strcpy(con[i].zi,q); // @@ If q points to an empty string (due to consecutive delimiters or initialization issues), this copies an empty word. More critically, the logic for advancing q is flawed below.
    con[i].ci++;
    i++;
    }
    else if(i!=0){
    for(j=0;j<i;j++){
        if(strcmp(q,con[j].zi)==0){
            con[j].ci++;
            flag=1;
            break;
        }
    }if(flag==0){
        strcpy(con[i].zi,q);
        con[i].ci++;
        i++;
    }
}
m=q;
for(d=0;d<=strlen(m);d++){ // @@ This loop advances q by strlen(m) + 1. Since m=q, it advances q to the end of the current string segment. However, because the input parsing in the first while loop did not correctly separate words with non-space delimiters (like digits), 'q' often points to large incorrect chunks or empty strings. The fundamental error is the parsing logic above, but this iteration logic assumes null-terminated words are correctly placed in 's', which they are not due to the previous error.
    q++;
}
}
qsort(con,i,sizeof(con[0]),compare);
for(j=0;j<i;j++){
    pf("%s %d\n",con[j].zi,con[j].ci);
}

fclose(in);

    return 0;
}