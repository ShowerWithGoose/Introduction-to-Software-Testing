#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct {
    char word[30];
    int count;
}dict;
dict a[110];
char tmpword[30];
int cmp(const void*a,const void*b){
    dict*c=(dict *)a; dict*d =(dict*)b;
    return strcmp(c->word,d->word);
}
int main(){
    int s,i=0,j,numword=0,flag=0;
    FILE *open=fopen("article.txt","r");
    while((s=fgetc(open))!=EOF){
        if(isalpha(s)){
        	flag=1;
            if(isupper(s))s=tolower(s);
            tmpword[i++]=s;
        }
        else {
            i=0;
        	if(!flag) continue;
            if(a[0].count==0){
                strcpy(a[0].word,tmpword);
                a[0].count=1;
                numword++;
            }
            else{
                for(j=0;j<numword;j++){
                    if(strcmp(tmpword,a[j].word)==0){
                        a[j].count++;
                        break;
                    }
                }
                if(j==numword){
                    strcpy(a[j].word,tmpword);
                    a[j].count=1;
                    numword++;
                }
            }
            memset(tmpword,'\0',30);
            flag=0;
        }
    }
    qsort(a,numword,sizeof(dict),cmp);
    for(i=0;i<numword;i++){
        printf("%s %d\n",a[i].word,a[i].count);
    }

}


