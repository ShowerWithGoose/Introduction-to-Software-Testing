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

int compare(const void *a,const void *b){@@ [Nested function definition is not standard C; causes compilation error in strict C compilers.]
     word *c=(word* )a;
     word *d=(word *)b;
     return strcmp(c->zi,d->zi);

}
    char k;
    char s[10086]={'\0'};
    char ss[10086]={'\0'};
    char *q=malloc(100*sizeof(s[0]));@@ [Allocated memory is never freed and pointer is overwritten; leads to memory leak.]
    char *m=NULL;
    int a,b,c,d,i=0,j,flag=0,flag1=0;
while((k=fgetc(in))!=EOF){
     if(k>='A'&&k<='Z'){
        s[i]=k-'A'+'a';i++;flag1=0;
    }else if(k>='a'&&k<='z'){
        s[i]=k;i++;flag1=0;
    }else if(k==' '||k=='\n'){@@ [Only space and newline are treated as separators; other non-letter characters (punctuation) will be incorrectly included in words.]
    if(flag1==0){
    
        s[i]='\0';i++;
        flag1=1;}
    }
}@@ [Missing null termination for the last word when file ends with a letter; s may not be properly terminated.]


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
}
}
qsort(con,i,sizeof(con[0]),compare);
for(j=0;j<i;j++){
    pf("%s %d\n",con[j].zi,con[j].ci);
}

fclose(in);

    return 0;
}