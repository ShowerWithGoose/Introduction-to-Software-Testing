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
} // @@ [Non-alphabetic characters other than space and newline (like digits, punctuation) are not handled, causing words like "since1972" to be treated as "since" followed by invalid separators, but the null terminator is only added on space/newline, so "since1972.C" becomes "since" + garbage or merged tokens.]

for(i=0;i<1000;i++){
    con[i].ci=0;
}
i=0;
q=s;
while(*q!='\0'){
    flag=0;
    if(i==0){
    strcpy(con[i].zi,q);
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
for(d=0;d<=strlen(m);d++){
    q++;
} // @@ [This loop increments q by strlen(m)+1, which skips past the null terminator and into uninitialized/garbage data. It should only increment by strlen(m)+1 once per token, but the logic is flawed because tokens are not properly separated by single nulls due to earlier input processing errors. Also, multiple consecutive non-letter characters may result in empty strings being processed.]
}
qsort(con,i,sizeof(con[0]),compare);
for(j=0;j<i;j++){
    pf("%s %d\n",con[j].zi,con[j].ci);
}

fclose(in);

    return 0;
}