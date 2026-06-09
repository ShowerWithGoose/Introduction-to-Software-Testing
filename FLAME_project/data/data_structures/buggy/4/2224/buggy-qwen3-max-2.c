#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct WORD{
    char s[30];
    int n;
}word,*pword;
int aw(char c){
    if(c>=65&&c<=90){
        return 1;
    }else{
        if(c>=97&&c<=122){
            return 1;
        }else{
            return 0;
        }
    }
}
char bw(char c){
    if(c>=65&&c<=90){
        c=c+32;
    }
    return c;
}
int cmp(const void *p1,const void *p2){
    pword d1=(pword)p1;
    pword d2=(pword)p2;
    return strcmp(d1->s,d2->s);
}
int main(){
    word b[30000]={0};
    FILE *in;
    in=fopen("article.txt","r");
    char c=0;
    int n_i=0,j=0,d=1;
    while((c=fgetc(stdin))!=EOF){ @@ // Error: reads from stdin instead of file 'in'; should use fgetc(in)
        if(aw(c)>0){
            c=bw(c);
            b[n_i].s[j]=c;
            j++;
            d=0;
        }else{
            if(d==0){
                    b[n_i].n=1;
                n_i++;
            }
            d++;
                j=0;
            }
    }
    qsort(b,n_i,sizeof(word),cmp);
    int k=0;
    for(k=0;k<n_i;k++){
        if(strcmp(b[k].s,b[k+1].s)==0){
            b[k+1].n=b[k+1].n+b[k].n;
            strcpy(b[k].s,"+");
        }
    }
    int h=0;
    for(h=0;h<n_i;h++){
        if(strcmp("+",b[h].s)!=0){
        printf("%s %d\n",b[h].s,b[h].n);    
        }
    }
    fclose(in);
    return 0;
}