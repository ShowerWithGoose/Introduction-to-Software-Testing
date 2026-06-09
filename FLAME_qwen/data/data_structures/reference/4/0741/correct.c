#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define M 1000
#define ll long long

typedef struct node{
    char word[20];
    int count;
} node;

int inc(const void *a, const void *b) {
	struct node *aa=(struct node *)a;
	struct node *bb=(struct node *)b;
	return(strcmp(aa->word,bb->word));
}

int main() {
    node wordlist[M];
    FILE *in;
    in=fopen("article.txt","r");
    int i,j,k,n,p;
    char line[M*M],c;

    // 错误判断
    if((in=fopen("article.txt","r"))==NULL){
		printf("can not open the file\n");
		return 0;
	}

    // 读入文件所有字符
    i=0;
	while((c=fgetc(in))!=EOF){
        line[i++]=tolower(c);
		// fputc(c,out);
	}
	line[i]='\0';
    n=i;
    // puts(line);

    for(i=0,k=0,j=0,p=0;i<n,line[i]!='\0';i++){
        if(!(isalnum(line[i]))&&p){
            wordlist[j].word[k]='\0';
            j++;
            k=0;
            p=0;
        }else if(isalpha(line[i])){
            wordlist[j].word[k]=line[i];
            wordlist[j].count=1;
            k++;
            p=1;
        }
    }

    qsort(wordlist, j, sizeof(node), inc);
    
    for(i=0;i<j;i++){
        for(k=i+1;k<j;k++){
            if(strcmp(wordlist[i].word,wordlist[k].word)==0){
                wordlist[k].count+=wordlist[i].count;
                wordlist[i].count=0;
            }else{
                break;
            }
        }
    }

    for(i=0;i<j;i++){
        if(wordlist[i].count!=0){
            printf("%s %d",wordlist[i].word,wordlist[i].count);
            if(i<j-1){
                printf("\n\n");
            }
        }
    }



	return 0;
}
