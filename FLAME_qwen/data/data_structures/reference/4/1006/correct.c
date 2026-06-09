#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

int cmp_struct(const void *a ,const void *b);
typedef struct words{
    char word[50];
    int count,flag;
}words;

int main(void)
{
    FILE *in=fopen("article.txt","r");
    words a[500];
    char information[1000];
    int i=0,j=0,k=0,temp=0;

    while(fgets(information,1024,in)!=NULL){
        for(i=0;i<strlen(information);i++){
            if(isalpha(information[i])){
                sscanf(&information[i],"%s",a[j].word);
                for(k=0;k<strlen(a[j].word);k++){
                    if(isupper(a[j].word[k]))a[j].word[k]+=('a'-'A');
                    if(!isalpha(a[j].word[k]))a[j].word[k]=0;
                }
                i+=(strlen(a[j].word));
                j++;
            }
        }
    }

    qsort(a,j,sizeof(words),cmp_struct);

    for(i=0;i<j;i++){
        if(i!=0&&strcmp(a[temp].word,a[i].word)==0){
            a[temp].count++;
            a[i].flag=0;
        }else{
            a[i].flag=1;
            a[i].count=1;
            temp=i;
        }
    }

    for(i=0;i<j;i++){
        if(a[i].flag){
            printf("%s %d\n",a[i].word,a[i].count);
        }
    }

    return 0;
}

int cmp_struct(const void *a ,const void *b ){

	words c=*(words*)a;
    words d=*(words*)b;
    return(strcmp(c.word,d.word));

}
