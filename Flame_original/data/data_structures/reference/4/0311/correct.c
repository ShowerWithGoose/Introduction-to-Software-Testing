#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct list{
    char word[25];
    int cot;
};
int main(){
    FILE *in;
    in=fopen("article.txt","r");
    struct list p[1000];
    char w[200],w1[25];
    int c=0,i,j,k;
    while(fgets(w,200,in)!=NULL){
        int len=strlen(w);
        for(i=0;i<len;){
            if(w[i]>='a'&&w[i]<='z'||w[i]>='A'&&w[i]<='Z'){
                for(j=0;w[i+j]>='a'&&w[i+j]<='z'||w[i+j]>='A'&&w[i+j]<='Z';j++){
                    if(w[i+j]>='A'&&w[i+j]<='Z')
                        w1[j]=w[i+j]-'A'+'a';
                    else if(w[i+j]>='a'&&w[i+j]<='z')
                        w1[j]=w[i+j];
                }
                w1[j]='\0';
                for(k=0;k<c;k++){
                    if(strcmp(p[k].word,w1)==0){
                        p[k].cot++;
                        break;
                    }
                }
                if(k==c){
                    strcpy(p[c].word,w1);
                    p[c].cot=1;
                    c++;
                }
                i+=j;
            }
            else
                i++;
        }
    }
    struct list tmp;
    for(i=0;i<c;i++){
        for(j=i+1;j<c;j++){
            if(strcmp(p[i].word,p[j].word)>0){
                tmp=p[i];
                p[i]=p[j];
                p[j]=tmp;
            }
        }
    }
    for(i=0;i<c;i++)
        printf("%s %d\n",p[i].word,p[i].cot);
    return 0;
}

