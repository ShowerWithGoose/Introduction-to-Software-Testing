#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct word{
    char w[50];
    int f;
    struct word* link;
}*wd,wrd;
wd insert(wd,char[],wd);
int fg(FILE*,char[]);
int main()
{
    FILE *in;
    char x[50];
    int z;
    wd p,list,last;
    in=fopen("article.txt","r");
    list=(wd)malloc(sizeof(wrd));
    last=list;
    while((z=fg(in,x))>=0){
        if(z>0)
            last=insert(list,x,last);}
    last->link=NULL;
    p=list;
    list=list->link;
    free(p);
    for(p=list;p!=NULL;p=p->link)
        printf("%s %d\n",p->w,p->f);
    fclose(in);
    return 0;
}
wd insert(wd c,char t[],wd last)
{
    wd i,k;
    if(c==last){
        k=(wd)malloc(sizeof(wrd));
        strcpy(k->w,t);
        k->f=1;
        last->link=k;
        return k;
    }
    else{
        i=c->link;
        while(i!=last){
            if(strcmp(t,i->w)==0){
                i->f+=1;
                return last;
            }
            else if(strcmp(t,i->w)<0){
                k=(wd)malloc(sizeof(wrd));
                strcpy(k->w,t);
                k->f=1;
                k->link=c->link;
                c->link=k;
                return last;
            }
            else if((strcmp(t,i->w)>0)&&(strcmp(t,i->link->w)<0)){
                k=(wd)malloc(sizeof(wrd));
                strcpy(k->w,t);
                k->f=1;
                k->link=i->link;
                i->link=k;
                return last;
            }
            else if(strcmp(t,i->link->w)>=0)
                i=i->link;
        }
        if(strcmp(t,i->w)==0){
                i->f+=1;
                return i;}
        else if(strcmp(t,i->w)>0){
            k=(wd)malloc(sizeof(wrd));
            strcpy(k->w,t);
            k->f=1;
            i->link=k;
            return k;
        }
    }
}
int fg(FILE*in,char x[])
{
     int i=0;
     char j;
     memset(x,0,sizeof(x));
     while((j=fgetc(in))!=EOF){
        if(isalpha(j)!=0){
            x[i]=tolower(j);
            i++;}
        else{
            x[i]=0;
            return i;}
     }
     return EOF;
}



