#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

char word[500][20];
int cmp(const void *a,const void *b)
{
    return strcmp((char*)a,(char*)b);
}

int main()
{
    FILE *in;
    in=fopen("article.txt","r");

    int i=0,sign=0;
    char *mid=word,c;
    while((c=fgetc(in))!=EOF){
        if(!isalpha(c)){
            if(sign)i++;
            mid=&word[i];
            sign=0;
            continue;
        }
        sign=1;

        c=tolower(c);
        *mid=c;
        mid++;
    }

    qsort(word,i,sizeof(word[0]),cmp);

    int cnt=1;
    for(int j=0;j<i;j++){
        if(strcmp(word[j],word[j+1])==0){
            cnt++;
            continue;
        }
        printf("%s %d\n",word[j],cnt);
        cnt=1;
    }

    return 0;
}

